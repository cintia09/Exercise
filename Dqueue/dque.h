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
#include<utility>
using namespace std;

#define EXPEND_RATE 2

template <typename T>
class dqueM
{
	public:
		dqueM(): elements(nullptr), data_front(nullptr), free_rear(nullptr), endq(nullptr) {};
		dqueM(const dqueM&);
		dqueM(dqueM &&) noexcept;
		dqueM &operator=(dqueM) &;

		T *begin() const{return data_front;}
		T *end() const{return free_rear;}
		size_t size() const{return free_rear - data_front;}
		size_t front_cap() const{return data_front - elements;}
		size_t rear_cap() const{return endq - free_rear;}
		size_t capbility() const{return endq - elements;}

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
		void check_rear_alloc(size_t n) {if (rear_cap() < n) reallocate(front_cap(), (n > EXPEND_RATE*size() ? (EXPEND_RATE*n) : EXPEND_RATE*size()));}
		void reallocate(size_t, size_t);
		size_t is_empty(void) {return !size();}

		inline void swap(dqueM&, dqueM&);
		void free(void);

		T *elements;
		T *data_front;
		T *free_rear;
		T *endq;
						
};

template <typename T>
std::allocator<T> dqueM<T>::alloc;

template <typename T>
pair<T*, T*> dqueM<T>::copy_n_obj(const T *start, const T *end)
{
	auto ptr = alloc.allocate(end - start);
	return pair<T*, T*>(ptr, uninitialized_copy(start, end, ptr));
}

template <typename T>
inline void dqueM<T>::swap(dqueM<T> &lhs, dqueM<T> &rhs)
{
	using std::swap;
	swap(lhs.elements, rhs.elements);
	swap(lhs.data_front, rhs.data_front);
	swap(lhs.free_rear, rhs.free_rear);
	swap(lhs.endq, rhs.endq);
}

template <typename T>
void dqueM<T>::free()
{
	if (elements != nullptr)
	{
		for (auto p = data_front; p != free_rear; )
		{
			alloc.destroy(p++);
		}
		alloc.deallocate(elements, endq - elements);
	}
}

template <typename T>
dqueM<T>::dqueM(const dqueM<T> &obj)
{
	auto newdata = copy_n_obj(obj.begin(), obj.end());
	elements = data_front = newdata.first;
	endq = free_rear = newdata.second;
}

template <typename T>
dqueM<T>::dqueM(dqueM<T> &&obj) noexcept
:elements(obj.elements), data_front(obj.data_front), free_rear(obj.free_rear), endq(obj.endq)
{
	obj.elements = obj.data_front = obj.free_rear = obj.endq = nullptr;
}

template <typename T>
dqueM<T>& dqueM<T>::operator=(dqueM<T> obj) &
{
	swap(*this, obj);
	return *this;
}

template <typename T>
T* dqueM<T>::push_back(const T &data, size_t n) &
{
	check_rear_alloc(n);
	for (auto i = 0; i < n; ++i)
		alloc.construct(free_rear++, data);
	return free_rear;
}

template <typename T>
T* dqueM<T>::push_back(T &&data, size_t n) &
{
	check_rear_alloc(n);
	for (auto i = 0;i < n; ++i)
		alloc.construct(free_rear++, std::move(data));
	return free_rear;
}

template <typename T>
T dqueM<T>::pop_back()
{
	if (is_empty())
	{
		cout << "The dqueM is empty!" << endl;
		return T();
	}

	T data(*(--free_rear));
	alloc.destroy(free_rear);
	return data;
}

template <typename T>
T* dqueM<T>::push_front(const T& data, size_t n) &
{
	check_front_alloc(n);
	for (auto i = 0;i < n; ++i)
		alloc.construct(--data_front, data);
	return data_front;
}

template <typename T>
T* dqueM<T>::push_front(T &&data, size_t n) &
{
	check_front_alloc(n);
	for (auto i = 0;i < n; ++i)
		alloc.construct(--data_front, data);
	return data_front;
}

template <typename T>
T dqueM<T>::pop_front()
{
	if (is_empty())
	{
		cout << "The dqueM is empty!" << endl;
		return T();
	}

	T data(*data_front);
	alloc.destroy(data_front++);
	return data;
}

template <typename T>
void dqueM<T>::reallocate(size_t offset_front, size_t offset_rear)
{
	auto s = size();
	auto first = alloc.allocate(offset_front + s + offset_rear);
	auto last = uninitialized_copy(make_move_iterator(begin()),
									make_move_iterator(end()),
									first + offset_front);
	
	free();
	elements = first;
	data_front = first + offset_front;
	free_rear = data_front + s;
	endq = first + offset_front + s + offset_rear;
}

#endif
