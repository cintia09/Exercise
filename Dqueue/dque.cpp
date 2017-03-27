/*************************************************************************
    > File Name: dque.cpp
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Fri 24 Mar 2017 04:50:52 PM CST
 ************************************************************************/

#include"deque"

template <typename T>
pair<T*, T*> dqueM::copy_n_obj(const T *start, const T *end)
{
	auto ptr = alloc.allocate(end - start);
	return pair<T*, T*>(ptr, uninitialazed_copy(start, end, ptr));
}

inline void swap(dqueM &lhs, dqueM &rhs)
{
	using std::swap;
	swap(lhs.elements, rhs.elements);
	swap(lhs.data_front, rhs.data_front);
	swap(lhs.free_rear, rhs.free_rear);
	swap(lhs.end, rhs.end);
}

template <typename T>
void dqueM::free(void)
{
	if (elements != nullptr)
	{
		for (auto p = data_front; p != free_rear; )
			alloc.destroy(p++);
		alloc.deallocate(elements, end - elements);
	}
}

template <typename T>
dqueM::dqueM(const dqueM &obj)
{
	auto newdata = copy_n_obj(obj.begin(), obj.end());
	elements = newdata.first;
	end = newdata.second;
	data_front = elements + (obj.data_front - obj.elements);
	free_rear = elements + (obj.free_rear - obj.elements);
}

template <typename T>
dqueM::dqueM(dqueM &&obj):elements(obj.elements), data_front(obj.data_front), free_rear(obj.free_rear), end(obj.end) noexcept
{
	obj.elements = obj.data_front = obj.free_rear = obj.end = nullptr;
}

template <typename T>
dqueM& dqueM::operator=(dqueM obj) &
{
	swap(*this, obj);
	return *this;
}

template <typename T>
T* dqueM::push_back(const T &data, size_t n) &
{
	check_rear_alloc(n);
	for (auto i = 0; i < n; ++i)
		alloc.construct(free_rear++, data);
	return free_rear;
}

template <typename T>
T* dqueM::push_back(T &&data, size_t n) &
{
	check_rear_alloc(n);
	for (auto i = 0;i < n; ++i)
		alloc.construct(free_rear++, std::move(data));
	return free_rear;
}

template <typename T>
T dqueM::pop_back(void)
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
T* dqueM::push_front(const T& data, size_t n) &
{
	check_front_alloc(n);
	for (auto i = 0;i < n; ++i)
		alloc.construct(--data_front, data);
	return data_front;
}

template <typename T>
T* dqueM::push_front(T &&data, size_t n) &
{
	check_front_alloc(n);
	for (auto i = 0;i < n; ++i)
		alloc.construct(--data_front, data);
	return data_front;
}

template <typename T>
T dqueM::pop_front(void)
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
void dqueM::reallocate(size_t offset_front, size_t offset_rear)
{
	auto first = alloc.allocate(offset_front + size() + offset_rear);
	auto last = uninitialized_copy(make_mvoe_iterator(begin()),
									make_move_iterator(end()),
									first + offset_front);
	free();
	elements = first;
	data_front = first + offset_front;
	free_rear = last - offset_rear;
	end = last;
}



