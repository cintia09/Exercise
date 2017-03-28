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
	obj.push_back(n);
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
	for (n = 0;n < 100;++n)
	{
		cout << n << " ";
		front_stack_push(que, n);
	}

	cout << endl;

	dqueM<typeDef> que1;
	que1 = std::move(que);

	cout << "The sequence is: " << endl;
	
	for (auto &m: que1)
	{
		cout << front_stack_pop(que1) << " ";
	}
	cout << endl;

	front_stack_pop(que);
	return 0;
}


