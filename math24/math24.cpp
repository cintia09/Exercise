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
		sprintf(c, "%d", i);
		string s(c);
		mathp[i] = math(shared_ptr<mathbase>(new mathbase(number[i], s)), s, 1, i);
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
				ptr->next = make_shared<math>(shared_ptr<mathadd>(new mathadd(number[j], string("+"+s))), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdec>(new mathdec(number[j], string("-"+s))), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathpuls>(new mathpuls(number[j], string("x"+s))), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdev>(new mathdev(number[j], string("/"+s))), mathp[j].str, 1, j);
				ptr = ptr->next.get();
			}
			else
			{
				ptr->next = make_shared<math>(shared_ptr<mathdoubleadd>(new mathdoubleadd("+", mathp[j].number, mathp[j].index[0], mathp[j].index[1], mathp[j].index[2])), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdoubledec>(new mathdoubledec("-", mathp[j].number, mathp[j].index[0], mathp[j].index[1], mathp[j].index[2])), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdoublepuls>(new mathdoublepuls("x", mathp[j].number, mathp[j].index[0], mathp[j].index[1], mathp[j].index[2])), mathp[j].str, 1, j);
				ptr = ptr->next.get();
				ptr->next = make_shared<math>(shared_ptr<mathdoubledev>(new mathdoubledev("/", mathp[j].number, mathp[j].index[0], mathp[j].index[1], mathp[j].index[2])), mathp[j].str, 1, j);
				ptr = ptr->next.get();
			}
		}
	}
}

int mathdoublebase::search()
{
	int i, ret, node[100] = {0};
	string s;
	stackM<string> sstack;

	ret = max.mathp[index[0]];
}

vector<string> search(maxtren &max)
{
	int i = 0, ret;
	vector<string> vec;
	stackM<shared_ptr<math>> stack;
	
	auto in = max.mathp[0].next;
	while (in != nullptr)
	{
		auto on = in->next;

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
		
		ret = max.mathp[i].evalue();
		stack.push(max.mathp[i]->next);
		//sstack.push(max.mathp[i].mathp->str);

		while (!stack.empty())
		{
			auto ptr = stack.pop();
			if (!sstack.empty())
				sstack.pop();

			while (1)
			{
				while ((ptr != nullptr ) && ((ret = ptr->evalue(ret)) == -1))
					ptr = ptr->next;

				while (ptr != nullptr)
				{
					node[ptr->index[0]]
					ptr = ptr->next;
				}

				if (ptr == nullptr)
				{
					node[ptr->index[0]] = 0;
					if (ret == 24)
					{
						while (!sstack.empty())
							s = sstack.pop() + s;
						vec.push_back(max.mathp[i].mathp->str + s);
					}
					break;
				}

				//sstack.push(ptr->mathp->str);
				node[ptr->index[0]] = 1;

				if (ptr->mathp->number == 1)
				{
					stack.push(ptr->next);
					//node[ptr->index[0]] = 1;
					//s = s + ptr->mathp->str;
					sstack.push(ptr->mathp->str);
				}
				else
				{
					stack.push(ptr);
					//s = s + "(" + ptr->mathp->str + ")";
					sstack.push("(" + ptr->mathp->str + ")");
				}
				
				/*
				if (ptr->index[0] == -1)
				{
					if (ret == 24)
						vec.push_back(string(max.mathp[i].mathp->str + s));
					break;
				}
				*/

				//s = s + ptr->mathp->str;
				ptr = max.mathp[ptr->index[0]].next;
			}
		}
	}

	return vec;
}

int main(void)
{
	int number[4];
	int i;
	cout << "Please input number: ";
	for (i = 0;i < 4;++i)
		cin >> number[i];

	maxtren max(number);

	//vector<string> vec(search(max)); 

	cout << "The result is: ";
	for (auto &j: number)
		cout << j << " ";
	cout << endl;

	//for (auto &a: vec)
	//	cout << a << endl;
	
	//auto v = max.mathp[0].next;
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

	return 0;
}
