/*************************************************************************
    > File Name: text_query.cpp
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Wed 08 Mar 2017 09:28:08 AM CST
 ************************************************************************/

#include<text_query.h>

/* This program is a practice for learning c++ program.
   The function is that looking for a word provided by user in a text file.
   The query result is all the line number which the word appeares in the text file.
*/

queue<string> InputWords::translate()
{
	queue<string> word_que;
	stack<char> word_stack;
	string word;

	for (auto &c: words)
	{
		if (c == ' ' )
			continue;

		if (c == '(')
		{
			word_stack.push(c);
			continue;
		}

		if (c == ')')
		{
			if (!word.empty())
			{
				for (auto &ww: word)
					cout << "word ?:" << ww << endl;
				word_que.push(word);
			}
			word.erase(0);

			while (!word_stack.empty() && word_stack.top() != '(')
			{
				word_que.push(string(1, word_stack.top()));
				word_stack.pop();
			}

			if (!word_stack.empty() && word_stack.top() == '(')
				word_stack.pop();
			else
			{
				cout << "You enter a invalid charator!!!" << endl;
				while (!word_stack.empty())
					word_stack.pop();
				while (!word_que.empty())
					word_que.pop();
				break;
			}

			continue;
		}

		//When a operator come in, then push pre word to que.
		if (c == '&' || c == '|')
		{
			if (word_que.empty() && word.empty())
			{
				cout << "You enter a invalid charator!!!" << endl;
				break;
			}

			word_que.push(word);
			word.erase(0);

			while (!word_stack.empty() && word_stack.top() != '(')
			{
				if (word_stack.top() == '&' || c == '|')
				{
					word_que.push(string(1, word_stack.top()));
					word_stack.pop();
				}
				else
					break;
			}

			word_stack.push(c);
		}
		else
		{
			word.append(1, c);
		}
	}

	if (!word.empty())
		word_que.push(word);

	//Pop all rest operator char to que.
	while (!word_stack.empty())
	{
		word_que.push(string(1, word_stack.top()));
		word_stack.pop();
	}

	cout << "Expression is: " << (word_que.empty() ? "NULL" : "what?... ");
	if (!word_que.empty())
	{
		for (string *i = &word_que.front(); i != &word_que.back() + 1; i++)
		{
			cout << *i;
		}
	}

	cout << " end" <<endl;

	return word_que;
}

Query InputWords::query(queue<string> word)
{
	stack<Query> query_stack;
	string s;
	Query query_t1, query_t2;

	while (!word.empty())
	{
		s = word.front();
		word.pop();

		if (s == "")
			continue;

		if (s == "&")
		{
			if (!query_stack.empty())
			{
				query_t1 = query_stack.top();
				query_stack.pop();
				if (!query_stack.empty())
				{
					query_t2 = query_stack.top();
					query_stack.pop();
				}
				else
					return Query(shared_ptr<Query_base>(nullptr));

				query_stack.push(query_t2 & query_t1);
			}
		}
		else if (s == "|")
		{
			if (!query_stack.empty())
			{
				query_t1 = query_stack.top();
				query_stack.pop();
				if (!query_stack.empty())
				{
					query_t2 = query_stack.top();
					query_stack.pop();
				}
				else
					return Query(shared_ptr<Query_base>(nullptr));

				query_stack.push(query_t2 | query_t1);
			}
		}
		else
			query_stack.push(Query(s));
	}

	return query_stack.top();
}

ResultQuery InputWords::query(TextQuery &text)
{
	auto t = translate();
	if (t.empty())
	{
		cout << "translate is null!!!" << endl;
		return ResultQuery(nullptr, "");
	}

	auto q = query(t);
	if (q.ptr == nullptr)
	{
		cout << "query is null" << endl;
		return ResultQuery(nullptr, "");
	}

	return q.eval(text);
}

ResultQuery Query_or::eval(TextQuery &text)
{
	auto lvalue = lv.eval(text);
	auto rvalue = rv.eval(text);
	shared_ptr<set<TextQuery::Line_NO>> retlines;

	if (lvalue.ptr != nullptr)
	{
		retlines = make_shared<set<TextQuery::Line_NO>>(lvalue.begin(), lvalue.end());
		if (rvalue.ptr != nullptr)
			retlines->insert(rvalue.begin(), rvalue.end());
	}
	else if (rvalue.ptr != nullptr)
		retlines = make_shared<set<TextQuery::Line_NO>>(rvalue.begin(), rvalue.end());
	else
		return ResultQuery(nullptr, "");

	cout << (lvalue.word + " | " + rvalue.word) << endl;
	for (const auto &l: *retlines)
	{
		cout << " " << l;
	}

	cout << endl;

	return ResultQuery(retlines, lvalue.word + " | " + rvalue.word);
}

ResultQuery Query_and::eval(TextQuery &text)
{
	auto lvalue = lv.eval(text);
	auto rvalue = rv.eval(text);

	if (lvalue.ptr == nullptr || rvalue.ptr == nullptr)
		return ResultQuery(nullptr, "");

	auto retlines = make_shared<set<TextQuery::Line_NO>>();

	set_intersection(lvalue.begin(), lvalue.end(), rvalue.begin(),
						rvalue.end(), inserter(*retlines, retlines->begin()));

	cout << (lvalue.word + " & " + rvalue.word) << endl;
	for (const auto &l: *retlines)
	{
		cout << " " << l;
	}

	cout << endl;

	return ResultQuery(retlines, lvalue.word + " & " + rvalue.word);
}

TextQuery::TextQuery(string s) : file_name(s)
{
	Line_NO i = 0;
	string text;
	ifstream infile(s);
	
	if(!infile.is_open())
	{
		cout << "Your inpput file " << s << " is open failed!!!" << endl;
		exit(1);
	}

	while(getline(infile, text))
	{
		++i;
		text_v.push_back(text);

		string word;
		istringstream stream(text);
		while(stream >> word)
		{
			shared_ptr<set<Line_NO>> ptr = make_shared<set<Line_NO>>();
			auto text_pair = text_map.insert({word, ptr});
			text_pair.first->second->insert(i);
		}
	}

	infile.close();
}

ResultQuery TextQuery::query(string s)
{
	auto word = text_map.find(s);
	
	if(word != text_map.end())
	{
		return ResultQuery(word->second, s);
	}
	else
		return ResultQuery(nullptr, "");
}

string TextQuery::printv(Line_NO line) const
{
	return text_v[--line];
}

ostream &print(ostream &out, ResultQuery result, TextQuery text)
{
	if (result.ptr == nullptr || result.begin() == result.end())
	{
		out << "You look for the word is not in the file!!";
		return out;
	}

	out << "You look for the word " << "\"" << result.word << "\"" << " lines number " << ": " << endl;
	for (const auto &l: result)
	{
		out << "(Line " << l << "): " << text.printv(l) << endl;
	}

	return out;
}

int main(void)
{
	string s;

	cout << "Please input a text file name for query:" << endl;

	if(!(cin >> s))
	{
		cout << "The file name is invalid, the program need to restart!!!" << endl;
		return -1;
	}

	TextQuery text(s);


	cout << "Please enter word to look for, or enter q to quit: ";

	while(getline(cin, s))
	{
		if(s.empty())
			continue;

		if (s == "q")
		{
			cout << "You enter q to quit." << endl;
			break;
		}

		InputWords input_word(s);

		//Print the result of query from text object by using method query.
		//Result is a instance of ResultQuery, as a parameter to print.
		print(cout, input_word.query(text), text) << endl << endl;

		cout << "Please enter word to look for, or enter q to quit: ";
	} 

	return 0;
}
