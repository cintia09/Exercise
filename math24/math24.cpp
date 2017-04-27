/*************************************************************************
    > File Name: math24.cpp
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Sun 23 Apr 2017 11:15:49 AM CST
 ************************************************************************/

#include<iostream>
#include"math24.h"
using namespace std;

/*
maxtren::maxtren(const int number[])
{
	int i, j, k;

	mathadd add[4];
	mathdec dec[4];
	mathpuls puls[4];
	mathdev dev[4];

	int abcd[4][4] = {0};

	cout << "maxtren: " << endl;
	for (i = 0;i < 4;++i)
	{
		char c[10];
		sprintf(c, "%d", number[i]);
		string s(c);

		cout << number[i] << ", ";
		add[i] = mathadd(number[i], string(" + " + s));
		dec[i] = mathdec(number[i], string(" - " + s));
		puls[i] = mathpuls(number[i], string(" x " + s));
		dev[i] = mathdev(number[i], string(" / " + s));
		cout << add[i].value << ", " << add[i].str << ", " << dec[i].str << ", " << puls[i].str << ", " << dev[i].str << endl;
	}
	
	for (i = 0;i < 4;++i)
	{
		for (j = 0;j < 4;++j)
		{
			if (i != j)
			{
				char c[10];
				sprintf(c, "%d", number[i]);
				string s(c);
				vector<math> madd, mdec,  mpuls, mdev;
				abcd[i][j] = 1;

				if (!abcd[j][i])
				{
					madd.push_back(math(shared_ptr<mathdouble>(new mathdouble(number[i], number[j], add[j].evalue(number[i]), string("(" + s + add[j].str + ")")))));
					for (k = 0;k < 4;++k)
						if (k != i && k != j)
						{
							madd.push_back(math(shared_ptr<mathadd>(new mathadd(add[k]))));
							madd.push_back(math(shared_ptr<mathdec>(new mathdec(dec[k]))));
							madd.push_back(math(shared_ptr<mathpuls>(new mathpuls(puls[k]))));
							madd.push_back(math(shared_ptr<mathdev>(new mathdev(dev[k]))));
						}

					vec.push_back(madd);
				}

				if (number[i] - number[j] >= 0)
				{
					mdec.push_back(math(shared_ptr<mathdouble>(new mathdouble(number[i], number[j], dec[j].evalue(number[i]), string("(" + s + dec[j].str + ")")))));
					for (k = 0;k < 4;++k)
						if (k != i && k != j)
						{
							mdec.push_back(math(shared_ptr<mathadd>(new mathadd(add[k]))));
							mdec.push_back(math(shared_ptr<mathdec>(new mathdec(dec[k]))));
							mdec.push_back(math(shared_ptr<mathpuls>(new mathpuls(puls[k]))));
							mdec.push_back(math(shared_ptr<mathdev>(new mathdev(dev[k]))));
						}
					vec.push_back(mdec);
				}

				if (!abcd[j][i])
				{
					mpuls.push_back(math(shared_ptr<mathdouble>(new mathdouble(number[i], number[j], puls[j].evalue(number[i]), string("(" + s + puls[j].str + ")")))));
					for (k = 0;k < 4;++k)
						if (k != i && k != j)
						{
							mpuls.push_back(math(shared_ptr<mathadd>(new mathadd(add[k]))));          
							mpuls.push_back(math(shared_ptr<mathdec>(new mathdec(dec[k]))));
							mpuls.push_back(math(shared_ptr<mathpuls>(new mathpuls(puls[k]))));
							mpuls.push_back(math(shared_ptr<mathdev>(new mathdev(dev[k]))));
						}
					vec.push_back(mpuls);
				}

				if (number[i] % number[j] == 0)
				{
					mdev.push_back(math(shared_ptr<mathdouble>(new mathdouble(number[i], number[j], dev[j].evalue(number[i]), string("(" + s + dev[j].str + ")")))));
					for (k = 0;k < 4;++k)
						if (k != i && k != j)
						{
							mdev.push_back(math(shared_ptr<mathadd>(new mathadd(add[k])))); 
							mdev.push_back(math(shared_ptr<mathdec>(new mathdec(dec[k])))); 
							mdev.push_back(math(shared_ptr<mathpuls>(new mathpuls(puls[k])))); 
							mdev.push_back(math(shared_ptr<mathdev>(new mathdev(dev[k]))));  
						}
					vec.push_back(mdev);
				}
			}
		}
	}

	for (auto v1 = vec.begin();v1 != vec.end();++v1)
		for (auto v2 = vec.begin();v2 != vec.end();++v2)
			if (v1 != v2)
			{
				auto m = v2->begin();
				if ((v1->begin())->mathp->l == m->mathp->l 
						|| (v1->begin())->mathp->l == m->mathp->r
						|| (v1->begin())->mathp->r == m->mathp->l
						|| (v1->begin())->mathp->r == m->mathp->r
					)
					continue;

				v1->push_back(math(shared_ptr<mathadd>(new mathadd(m->evalue(), string(" + (" + m->mathp->str + ")")))));
				v1->push_back(math(shared_ptr<mathdec>(new mathdec(m->evalue(), string(" - (" + m->mathp->str + ")")))));
				v1->push_back(math(shared_ptr<mathpuls>(new mathpuls(m->evalue(), string(" x (" + m->mathp->str + ")")))));
				v1->push_back(math(shared_ptr<mathdev>(new mathdev(m->evalue(), string(" / (" + m->mathp->str + ")")))));
			}
}
*/

//vector<string> search(maxtren &max)
//{

//}

maxtren::maxtren(const int number[])
{
	int i, j, k, l, m, flag;
	char c[20];
	weak_ptr<math> shadow;

	for (i = 0;i < 4;++i)
	{
		sprintf(c, "%d", number[i]);
		string s(c);
		sprintf(c, "%d", i);
		string ss(c);
		mathp[i] = math(shared_ptr<mathbase>(new mathbase(number[i], s)), ss, 1, i);
		//cout << "mathp[" << i << "]=" << mathp[i].number << endl;
	}

	k = i;

	for (i = 0;i < 4;++i)
		for (j = 0;j < 4;++j)
			if (i != j)
			{
				sprintf(c, "%d,%d", i,j);
				string s(c);
				mathp[k++] = math(shared_ptr<mathbase>(new mathbase), s, 2, i, j);
				//cout << "mathp[" << k - 1 << "]=" << mathp[k-1].number << endl;
				for (l = 0;l < 4;++l)
					if (i != l && j != l)
					{
						sprintf(c, "%d,%d,%d", i,j,l);
						string s(c);
						mathp[k++] = math(shared_ptr<mathbase>(new mathbase), s, 3, i, j, l);
					  	//cout << "mathp[" << k - 1 << "]=" << mathp[k-1].number << endl;
					}  
			}
	
	for (i = 0;i < k;++i)
	{
		auto ptr = &mathp[i];
		//shadow = ptr;
 		for (j = 0;j < k;++j)
		{
			if (i == j)
				continue;

			flag = 0;
			/*
			cout << "mathp[" << i << "]=" << mathp[i].number << " " << mathp[i].str  << ", mathp[" << j << "]=" << mathp[j].number << " " << mathp[j].str;
			cout << ", index I: ";
			for (l = 0;l < mathp[i].number;++l)
			{
				cout << mathp[i].index[l] << " ";
			}

			cout << ", J: ";
			for (l = 0;l < mathp[j].number;++l)
			{
				cout << mathp[j].index[l] << " ";
			}
			cout << endl;
			*/
			for (l = 0;l < mathp[i].number;++l)
			{
				for (m = 0;m < mathp[j].number;++m)
					if (mathp[i].index[l] == mathp[j].index[m])
					{
						flag = 1;
					  	break;
					}  

				if (flag)
					break;  
			}
			
			if (flag)
				continue;
			
			//cout << "mathp[" << i << "]=" << mathp[i].number << " " << mathp[i].str  << ", mathp[" << j << "]=" << mathp[j].number << " " << mathp[j].str << endl;

			//sprintf(c, "%d", number[j]);
			//string s(c);

			if (j < 4)
			{
				sprintf(c, "%d", number[j]);
				string s(c);
				ptr->next = make_shared<math>(shared_ptr<mathadd>(new mathadd(number[j], string("+"+s), 1, j)), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdec>(new mathdec(number[j], string("-"+s), 1, j)), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathpuls>(new mathpuls(number[j], string("x"+s), 1, j)), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdev>(new mathdev(number[j], string("/"+s), 1, j)), mathp[j].str, 1, j);
				ptr = ptr->next.get();
			}
			else
			{
				ptr->next = make_shared<math>(shared_ptr<mathdoubleadd>(new mathdoubleadd("+", mathp[j].number, mathp[j].index[0], mathp[j].index[1], mathp[j].index[2])), mathp[j].str, mathp[j].number, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdoubledec>(new mathdoubledec("-", mathp[j].number, mathp[j].index[0], mathp[j].index[1], mathp[j].index[2])), mathp[j].str, mathp[j].number, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdoublepuls>(new mathdoublepuls("x", mathp[j].number, mathp[j].index[0], mathp[j].index[1], mathp[j].index[2])), mathp[j].str, mathp[j].number, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdoubledev>(new mathdoubledev("/", mathp[j].number, mathp[j].index[0], mathp[j].index[1], mathp[j].index[2])), mathp[j].str, mathp[j].number, j);
				ptr = ptr->next.get();
			}
		}
	}
}

int mathdoublebase::search()
{
	int i = 0, ret, k, flag = 0, pre = -1, prevalue = -1, ppv = -1;
	string s;
	//stackM<string> sstack;

	if (!mstack.empty())
	{
		for (auto ll = 0;ll < 100;++ll)
			node[ll] = 0;
		
		for (i = 0;i < 4;++i)
		{
			for (k = 0;k < number;++k)
			{
				if (index[k] == i)
					break;
			}

			if (k == number)
				node[i] = 1;
		}

		ret = max->mathp[index[0]].evalue();
		mstack.push(pair<shared_ptr<math>, int>(max->mathp[index[0]].next, ret));
		sstack.push(max->mathp[0].mathp->str);
	}

	while (!mstack.empty())
	{
		auto pa = mstack.pop();
		auto ptr = pa.first;
		if (!sstack.empty())
			sstack.pop();
			
		ret = pa.second;
		prevalue = ret;

		while (1)
		{
			while (ptr != nullptr)
            {																																						
				flag = 0;                                                                                                                                           
				if (node[ptr->index[0]])
				{        
					ptr = ptr->next;
				 	continue;
				}

				auto p = max->mathp[ptr->index[0]];
				for (auto k = 0;k < p.number;++k)
				{
                   if (node[p.index[k]])
				   {
				 	   flag = 1;
					   break;
				   }
				}
				
				if (flag)
					ptr = ptr->next;
				else
				 	break;
			}

			ppv =ret;
			while (ptr != nullptr )
			{
				ret = ptr->evalue(ret);
				if (ret == -1)
					ptr = ptr->next;
				else
					break;
			}

			if (ptr == nullptr)
			{
				if (pre != -1)
					node[pre] = 0;
				//if (ret == 24)
				{
					//while (!sstack.empty())
					//	s = sstack.pop() + s;
					str = s;
					cout << "in result: " << str << endl;
					//vec.p u sh_back(max.mathp[i].mathp->str + s);
		
				}
			
				return ppv; 
			}

			node[ptr->index[0]] = 1;
			pre = ptr->index[0];

			if (ptr->number == 1)
			{
				mstack.push(pair<shared_ptr<math>, int>(ptr->next, prevalue));
				//sstack.push(ptr->mathp->str);
				//cout << "in search: " << ptr->mathp->str << endl;
			}
			else
			{
				mstack.push(pair<shared_ptr<math>, int>(ptr, prevalue));
				//sstack.push("("  + ptr->mathp->str + ")");
				//cout << "in search: " << "(" + ptr->mathp->str + ")" << endl;
			}

			sstack.push(s);
			s = "(" + s + ptr->mathp->str + ")";

			 prevalue = ret;
			ptr = max->mathp[ptr->index[0]].next;
		}
	}

	return -1;
}



vector<string> search(maxtren &max)
{
	int i = 0, ret, flag = 0, pre = -1, prevalue = -1, ppv = -1;
	vector<string> vec;
	stackM<pair<shared_ptr<math>, int>> stack;
	
	auto in = max.mathp[0].next;
	while (in != nullptr)
	{
		auto on = in;

		while (on != nullptr)
		{
			if (on->number > 1)
				on->mathp->max = &max;

			on = on->next;
		}

		in = max.mathp[++i].next;
	}

	for (i = 0;i < 4;++i)
	{
		int node[100] = {0};
		stackM<string> sstack;
		string s;
		pre = -1;
		prevalue = -1;
		//int vv = -2;

		node[i] = 1;
		ret = max.mathp[i].evalue();
		stack.push(pair<shared_ptr<math>, int>(max.mathp[i].next, ret));
		sstack.push(max.mathp[i].mathp->str);

		//sn = max.mathp[i].mathp->str;
		//sp = sn;

		while (!stack.empty())
		{
			auto pa = stack.pop();
			auto ptr = pa.first;
			if (!sstack.empty())
				s = sstack.pop();
			else
				s = "";

			flag = 0;
			cout << "pop stack str " << s << endl;

			if (ptr != nullptr)
			{
				cout << "out stack: " << ptr->mathp->str << ", node[" << ptr->index[0] << "]: " << node[ptr->index[0]] << endl;
				//if (vv == ptr->index[0])
					node[ptr->index[0]] = 0;
				//vv = ptr->index[0];
			}
			else
				node[pa.second] = 0;

			//ret = pa.second;
			//prevalue = ret;
/*
			//while (1)
			{
				if (ptr != nullptr)
				{ 
 					//cout << "1 next node[" <<  ptr->next->index[0] << "] is " << node[ptr->next->index[0]] <<endl;
				 	//flag = 0;
					if (node[ptr->index[0]])
					{
 				 		ptr = ptr->next;
						while (ptr->next != nullptr && node[ptr->next->index[0]])
							ptr = ptr->next;
						stack.push(pair<shared_ptr<math>, int>(ptr->next, pa.second));
						continue;
					}

					//cout << "2 next node[" <<  ptr->next->index[0] << "] is " << node[ptr->next->index[0]] <<endl;

					auto p = max.mathp[ptr->index[0]];
					for (auto k = 0;k < p.number;++k)
					{
				 		if (node[p.index[k]])
						{
							while (ptr->next != nullptr && node[ptr->next->index[0]])
								ptr = ptr->next;
							flag = 1;
							stack.push(pair<shared_ptr<math>, int>(ptr->next, pa.second));
						 	break;
						} 
					}

					if (flag)
						continue;
					//else
					//	break;
				}
*/
				//ppv = ret;
				if (ptr != nullptr )
				{
					ret = ptr->evalue(pa.second);
					if (ret == -1)
					{
						//ptr = ptr->next;
						while (ptr->next != nullptr && check_visited(ptr->next.get(), node))
							ptr = ptr->next;
						if (ptr->next == nullptr)
						{
							cout << "push stack null" << ptr->index[0] << endl;
							stack.push(pair<shared_ptr<math>, int>(ptr->next, ptr->index[0]));
						}
						else
						{
							cout << "push stack " << pa.second << endl;
							stack.push(pair<shared_ptr<math>, int>(ptr->next, pa.second));
						}
						sstack.push(s);
						cout << "push stack str" << s << endl;
						continue;
					}
					//else
					//	break; 
				}
				
				if (ptr == nullptr)
				{
				 	//if (pre != -1)
					//	node[pre] = 0;
					if (pa.second == 24)
					{
				 		//while (!sstack.empty())
						//	s = sstack.pop() + s;
						vec.push_back(s);
						cout << "= ==================================   ";
					}

					cout << "result: " << s << " = " << ret << endl << endl;
					//break;
					continue;
					//return vec; 
				}

				//node[ptr->index[0]] = 1;
				//pre = ptr->index[0];

				//cout << "3 node[" <<  ptr->index[0] << "] is " << node[ptr->index[0]] << endl;
				//if (pre != -1)
				//	cout <<"4 pre node[" <<  pre << "] is " << node[pre] <<endl;

				if (ptr->number == 1)
				{
					//node[ptr->index[0]] = 1;
					cout << ptr->next->index[0] << " " << ptr->index[0] << " "<< node[ptr->next->index[0]] << " " << node[ptr->index[0]] << endl;
					//while (ptr->next != nullptr && node[ptr->next->index[0]])
					while (ptr->next != nullptr && check_visited(ptr->next.get(), node))
						ptr = ptr->next;
					if (ptr->next == nullptr)
					{
						cout << "push stack null" << ptr->index[0] << endl;
						stack.push(pair<shared_ptr<math>, int>(ptr->next, ptr->index[0]));
					}
					else
					{
						cout << "push stack " << pa.second << endl;
						stack.push(pair<shared_ptr<math>, int>(ptr->next, pa.second));
					}
					//node[ptr->index[0]] = 1;
					//sstack.push(ptr->mathp->str);
					//cout << "in stack: " << ptr->next->mathp->str << endl; 
				}
				else
				{
					stack.push(pair<shared_ptr<math>, int>(ptr, pa.second)); 
					//sstack.push("(" + ptr->mathp->str + ")");
					//cout << "in stack: " << "(" + ptr->next->mathp->str + ")" << endl;
				}
				
				node[ptr->index[0]] = 1;
				sstack.push(s);
				s = "(" + s + ptr->mathp->str + ")";
				sstack.push(s);
				cout << "push stack str " << s << endl;
				//s = "(" + s + ptr->mathp->str + ")";

				//prevalue = ret;
				//ptr = max.mathp[ptr->index[0]].next;

				ptr = max.mathp[ptr->index[0]].next;
				while (ptr != nullptr && check_visited(ptr.get(), node))
					ptr = ptr->next;

				stack.push(pair<shared_ptr<math>, int>(ptr, ret));
			}
		}
	

	return vec;
}

int check_visited(math * mathp, int node[])
{
	int i;

	if (node[mathp->index[0]])
		return -1;
	
	if (mathp->mathp->number == 1)
		return 0;

	for (i = 0;i < mathp->mathp->number;++i)
	{
		if (node[mathp->mathp->index[i]])
			return -1;
	}

	return 0;
}

int main(void)
{
	int number[4];
	int i;
	cout << "Please input number: ";
	for (i = 0;i < 4;++i)
		cin >> number[i];

	maxtren max(number);

	
	i = 0;
	while (max.mathp[i].mathp != nullptr)
	{
		auto v = max.mathp[i].next;
		cout << "mathp[" << i << "]: " << max.mathp[i].str << " -> ";
		while (v != nullptr)
		{
			cout << v->str << ", " <<  v->mathp->str << " -> ";
			v = v->next;
		}
		cout << endl << endl;
		++i;
	}

	cout << "The result is: ";
	for (auto &j: number)
		cout << j << " ";
	cout << endl;
	
	
	vector<string> vec(search(max)); 

	if (vec.empty())
	{
		cout << "The result is empty!" << endl;
		return 0;
	}

	for (auto &a: vec)
		cout << a << endl;
	

	return 0;
}
