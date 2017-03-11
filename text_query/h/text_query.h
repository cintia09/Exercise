/*************************************************************************
    > File Name: ../h/text_query.h
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Wed 08 Mar 2017 12:49:42 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<memory>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

class ResultQuery;
class Query;
class TextQuery;
class InputWords;
class Query_base;
class Query_text;

//Define TextQuery
class TextQuery
{
	friend class ResultQuery;
	public:
		using Line_NO = unsigned int;
		TextQuery() = default;
		TextQuery(string s);

		ResultQuery query(string s);
		string printv(Line_NO) const;
	private:
		string file_name;
		vector<string> text_v;
		map<string, shared_ptr<set<Line_NO>>> text_map; 
};

//Define ResultQuery
class ResultQuery
{
	public:
		ResultQuery() = default;
		ResultQuery(ResultQuery &&text): ptr(text.ptr), word(std::move(text.word)){}
		ResultQuery operator=(ResultQuery &&text) {ptr = text.ptr; word = text.word;}
		ResultQuery(shared_ptr<set<TextQuery::Line_NO>> p, string s): ptr(p), word(s) {}
		string word;
		shared_ptr<set<TextQuery::Line_NO>> ptr;
		set<TextQuery::Line_NO>::iterator begin() {return ptr->begin();}
		set<TextQuery::Line_NO>::iterator end() {return ptr->end();}
};

//Define InputWords for save and translate the express entered by user
class InputWords
{
	public:
		InputWords() = default;
		InputWords(string s): words(s){}
		ResultQuery query(TextQuery&);
	private:
		queue<string> translate();
		Query query(queue<string>);
		string words;
};

/*
//Define Query(It's interface for user)
class Query
{
	public:
		friend Query operator|(Query, Query);
		friend Query operator&(Query, Query);
		Query() = default;
		Query(string s) {p = make_shared<Query_text>(Query_text(s));}
		ResultQuery eval(const TextQuery &text){return p->eval(text);}
	private:
		Query(shared_ptr<Query_base> p): ptr(p){};
		shared_ptr<Query_base> p;
};
*/

//Define Query_base, it's the base of Query class.
class Query_base
{
	friend class Query;
	virtual ResultQuery eval(TextQuery &text) = 0;
	public:
		virtual ~Query_base() = default;
};

class Query_text: public Query_base
{
	friend class Query;
	Query_text() = default;
	Query_text(string s): word(s) {cout << "Query_text, word: " << s << endl;}
	string word;
	virtual ResultQuery eval(TextQuery &text) override {cout << "Query_text eval" << endl; return text.query(word);}
};

//Define Query(It's interface for user)
class Query
{
	public:
		friend Query operator|(Query &, Query &);
		friend Query operator&(Query &, Query &);
		Query() = default;
		Query(string s) {ptr = shared_ptr<Query_base>(new Query_text(s)); cout << "Query new query_text" << endl;}
		ResultQuery eval(TextQuery &text){cout << "Query eval" << endl; return ptr->eval(text);}
		Query(shared_ptr<Query_base> p): ptr(p){cout << "Query ptr" << endl;}
		shared_ptr<Query_base> ptr;
};


class Query_binary: public Query_base
{
	Query_binary() = default;
	protected:
		Query lv, rv;
		Query_binary(Query &l, Query &r): lv(l), rv(r){}
		~Query_binary() = default;
};

class Query_or: public Query_binary
{
	friend Query operator|(Query &, Query &);
	Query_or() = default;
	Query_or(Query &l, Query &r): Query_binary(l, r){cout << "Query_or" << endl;}
	ResultQuery eval(TextQuery &text) override;
};

inline Query operator|(Query &l, Query &r)
{
	cout << "operator | " << endl;
	return shared_ptr<Query_base>(new Query_or(l, r));
}

class Query_and: public Query_binary
{
	friend Query operator&(Query &, Query &);
	Query_and() = default;
	Query_and(Query &l, Query &r): Query_binary(l, r){cout << "Query_and" << endl;}
	ResultQuery eval(TextQuery &text) override;
};

inline Query operator&(Query &l, Query &r)
{
	cout << "operator & " << endl;
	return shared_ptr<Query_base>(new Query_and(l, r));
}


