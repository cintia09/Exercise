/*************************************************************************
    > File Name: dque.h
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Wed 22 Mar 2017 05:34:07 PM CST
 ************************************************************************/

#ifndef __DQUE__
#define __DQUE__

#include<iostream>
#include<memory>
using namespace std;

#define DQUE_SIZE 100

template <typename T>
class dqueM
{
	public:
		dqueM(): elements(nullptr), data_front(nullptr), free_rear(nullptr), end(nullptr) {};
		dqueM(const dqueM&);
		dqueM &operator=(const dqueM&);

		T *begin() const{return data_front;}
		T *end() const{return free_rear;}
		size_t size() const{return free_rear - data_front;}
		size_t front_cap() const{return data_front - elements;}
		size_t rear_cap() const{return end - free_rear}

		T *push_back(const T&, size_t n = 1);
		T pop_back();
		T *push_front(const T&, size_t n = 1);
		T pop_front();

		virtual ~dqueM() {free();}

	private:
		static allocator<T> alloc;
		pair<T*, T*> copy_n_obj(const T*, const T*);
		void check_front_alloc(size_t n) {if (front_cap() < n) realloc_front(n);}
		void check_rear_alloc(size_t n) {if (rear_cap() < n) realloc_rear(n)}
		void realloc_front(void);
		void realloc_rear(void);
		
		void free(void);

		T *elements;
		T *data_front;
		T *free_rear;
		T *end;
						
}

#endif
