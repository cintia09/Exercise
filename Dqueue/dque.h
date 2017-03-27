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

#define EXPEND_RATE 2

template <typename T>
class dqueM
{
	public:
		friend void swap(dqueM&, dqueM&);
		dqueM(): elements(nullptr), data_front(nullptr), free_rear(nullptr), end(nullptr) {};
		dqueM(const dqueM&);
		dqueM(dqueM &&) noexcept;
		dqueM &operator=(dqueM) &;

		T *begin() const{return data_front;}
		T *end() const{return free_rear;}
		size_t size() const{return free_rear - data_front;}
		size_t front_cap() const{return data_front - elements;}
		size_t rear_cap() const{return end - free_rear;}
		size_t capbility() const{return end - elements;}

		T *push_back(const T&, size_t n = 1) &;
		T *push_back(T&&, size_t n = 1) &;
		T pop_back();
		T *push_front(const T&, size_t n = 1) &;
		T *push_front(T&&, size_t n = 1) &;
		T pop_front();

		virtual ~dqueM() {free();}

	private:
		static allocator<T> alloc;
		pair<T*, T*> copy_n_obj(const T*, const T*);
		void check_front_alloc(size_t n) {if (front_cap() < n) reallocate((n > EXPEND_RATE*size() ? (EXPEND_RATE*n) : EXPEND_RATE*size()), rear_cap());}
		void check_rear_alloc(size_t n) {if (rear_cap() < n) reallocate(front_cap(), (n > EXPEND_RATE*size() ? (EXPEND_RATE*n) : EXPEND_RATE*size()))}
		void reallocate(size_t, size_t);
		size_t is_empty(void) {return !size();}

		void free(void);

		T *elements;
		T *data_front;
		T *free_rear;
		T *end;
						
}

#endif
