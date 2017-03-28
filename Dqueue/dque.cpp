/*************************************************************************
    > File Name: dque.cpp
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Fri 24 Mar 2017 04:50:52 PM CST
 ************************************************************************/

#include"dque.h"

template <typename T>
pair<T*, T*> dqueM<T>::copy_n_obj(const T *start, const T *end)
{
	auto ptr = alloc.allocate(end - start);
	return pair<T*, T*>(ptr, uninitialazed_copy(start, end, ptr));
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
			alloc.destroy(p++);
		alloc.deallocate(elements, endq - elements);
	}
}

template <typename T>
dqueM<T>::dqueM(const dqueM<T> &obj)
{
	auto newdata = copy_n_obj(obj.begin(), obj.endq());
	elements = newdata.first;
	endq = newdata.second;
	data_front = elements + (obj.data_front - obj.elements);
	free_rear = elements + (obj.free_rear - obj.elements);
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
	if (is_empty)
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
	auto first = alloc.allocate(offset_front + size() + offset_rear);
	auto last = uninitialized_copy(make_mvoe_iterator(begin()),
									make_move_iterator(end()),
			 						first + offset_front);
	free();
	elements = first;
	data_front = first + offset_front;
	free_rear = last - offset_rear;
	endq = last;
}



