/*************************************************************************
    > File Name: driver.cpp
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Mon 27 Mar 2017 05:11:32 PM CST
 ************************************************************************/

#include<stackM.h>

using namespace std;

typedef int typeDef;


int main(void)
{
	dqueM<typeDef> que;
	typeDef n;

	cout << "Please enter number: " << endl;
	for (n = 0;n < 100;++n)
	{
		cout << n << " ";
		que.push_back(n);
	}

	cout << endl;

	stackM<typeDef> stack;
	queueM<typeDef> queue(que);

	cout << "The stack is: " << endl;
	
	while (que.size())
		stack.push(que.pop_back());

	auto m = stack.begin();
	do 
	{
		cout << *(m++) << " ";
	}
	while(m != stack.end());

	cout << endl;

	cout << "The queue is: " << endl;
	for (auto m = queue.begin();m != queue.end();++m)
		cout << *m << " ";
	cout << endl;


	stack.swap(queue.getbottle());

	cout << "The swaped stack is: " << endl;
	for (auto m = stack.begin();m != stack.end();++m)
		cout << *m << " ";
	cout << endl;

	cout << "The swaped queue is: " << endl;
	while (!queue.empty())
		cout << queue.pop() << " ";
	cout << endl;


	return 0;
}


