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
	shared_ptr<math> shadow;

	for (i = 0;i < 4;++i)
	{
		mathp[i] = math(shared_ptr<mathbase>(new mathase), i);
	}

	k = i;

	for (i = 0;i < 4;++i)
		for (j = 0;j < 4;++j)
			if (i != j)
			{
				mathp[k++] = math(shared_ptr<mathbase>(new mathbase), 2, i, j);
				for (l = 0;l < 4;++l)
					if (i != l && j != l)
						mathp[k++] = math(shared_ptr<mathbase>(new mathbase), 3, i, j, l);
	
	for (i = 0;i < k;++i)
	{
		shadow = mathp[i];
 		for (j = 0;j < k;++j)
		{
			flag = 0;

			for (l = 0;l < 3;++l)
				for (m = 0;m < 3;++m)
					if (mathp[i].index[l] == mathp[j].index[m])
					{
						flag = 1;
						break;
					}
			
			if (flag)
				continue;
			if (j < 4)
			{
				sprintf(c, "%d", number[j]);
				string s(c);
				shadow->next = make_shared<math>(shared_ptr<mathadd>(new mathadd(number[j], string("+"+s))), j);
				shadow = shadow->next;
				shadow->next = make_shared<math>(shared_ptr<mathdec>(new mathdec(number[j], string("-"+s))), j);
				shadow = shadow->next;
				shadow->next = make_shared<math>(shared_ptr<mathpuls>(new mathpuls(number[j], string("x"+s))), j);
				shadow = shadow->next;
				shadow->next = make_shared<math>(shared_ptr<mathdev>(new mathdev(number[j], string("/"+s))), j);
				shadow = shadow->next;
			}
			else
			{
				shadow->next = make_shared<math>(shared_ptr<mathdoubleadd>(new mathdoubleadd("+", mathp[j].number, mathp[j].n[0], mathp[j].n[1], mathp[j].n[2])), j);
				shadow = shadow->next;
				shadow->next = make_shared<math>(shared_ptr<mathdoubledec>(new mathdoubledec("-", mathp[j].number, mathp[j].n[0], mathp[j].n[1], mathp[j].n[2])), j);
				shadow = shadow->next;
				shadow->next = make_shared<math>(shared_ptr<mathdoublepuls>(new mathdoublepuls("x", mathp[j].number, mathp[j].n[0], mathp[j].n[1], mathp[j].n[2])), j);
				shadow = shadow->next;
				shadow->next = make_shared<math>(shared_ptr<mathdoubledev>(new mathdoubledev("/", mathp[j].number, mathp[j].n[0], mathp[j].n[1], mathp[j].n[2])), j);
			}
		}
	}
}

int main()
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
	
	v = max.mathp[0].next;
	for (i = 0;i < 100;++i)
	{
		v = max.mathp[i].next;
		while (v != nullptr)
		{
			cout << v->index[0] << ", " <<  v.mathp->str << " --> ";
			v = v->next;
		}
		cout << endl << endl;
	}

	return 0;
}
