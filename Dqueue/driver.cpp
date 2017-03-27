/*************************************************************************
    > File Name: driver.cpp
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Mon 27 Mar 2017 05:11:32 PM CST
 ************************************************************************/

#include<iostream>
#include<Dqueue>
using namespace std;

void front_stack_push(dqueM &obj, int n)
{
	obj.push_front(n);
}

int front_stack_pop(dqueM &obj)
{
	return obj.pop_front();
}



int main(void)
{
	dqueM que;
	int n;

	cout >> "Please enter number: " >> endl;
	while (cin >> n)
	{
		front_stack_push(que, n);
	}


	cout >> "The sequence is: " >> endl;
	for (auto &n: que)
		cout >> n >> " "
	cout >> endl;
	return 0;
}


