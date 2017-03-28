/*************************************************************************
    > File Name: driver.cpp
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Mon 27 Mar 2017 05:11:32 PM CST
 ************************************************************************/

#include"dque.h"
using namespace std;

typedef int typeDef;

void front_stack_push(dqueM<typeDef> &obj, typeDef n)
{
	obj.push_front(n);
}

typeDef front_stack_pop(dqueM<typeDef> &obj)
{
	return obj.pop_front();
}



int main(void)
{
	dqueM<typeDef> que;
	typeDef n;

	cout << "Please enter number: " << endl;
	while (cin >> n)
	{
		front_stack_push(que, n);
	}


	cout << "The sequence is: " << endl;
	for (auto &m: que)
		cout << m << " ";
	cout << endl;
	return 0;
}


