/*************************************************************************
    > File Name: stackM.h
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Wed 29 Mar 2017 09:30:15 AM CST
 ************************************************************************/

#ifndef __STACK_M__
#define __STACK_M__

#include<iostream>
#include<dque.h>
using namespace std;

template <typename T, typename B = dqueM<T>>
class stackM
{
	public:
		stackM() {}
		stackM(const B& obj):bottle(obj) {}

		T *begin() const {return bottle.begin();}
		T *end() const {return bottle.end();}
		bool empty() const {return !bottle.size();}
		size_t size() const {return bottle.size();}
		void swap(B &rhs) {return bottle.swap(bottle, rhs);}

		T *push(const T& obj) {return bottle.push_back(obj);}
		T pop() {return bottle.pop_back();}

		B& getbottle() {return bottle;}
	private:
		B bottle;

};

template <typename T, typename B = dqueM<T>>
class queueM
{
	public:
		queueM() {}
		queueM(const B& obj):bottle(obj) {}

		T *begin() const {return bottle.begin();}
		T *end() const {return bottle.end();}
		bool empty() const {return !bottle.size();}
		size_t size() const {return bottle.size();}
		void swap(B &rhs) {return bottle.swap(bottle, rhs);}

		T *push(const T& obj) {return bottle.push_back(obj);}
		T pop() {return bottle.pop_front();}

		B& getbottle() {return bottle;}
	private:
		B bottle;
};

#endif
