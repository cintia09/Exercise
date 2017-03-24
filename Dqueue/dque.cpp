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
dqueM::duqeM(const dqueM &obj)
{
	auto newdata = copy_n_obj(obj.begin(), obj.end());
	elements = newdata.first;
	end = newdata.second;
	data_front = elements + (obj.data_front - obj.elements);
	free_rear = elements + (obj.free_rear - obj.elements);
}

template <typename T>
dqueM& dqueM::operator=(const dqeue& obj)
{
	auto newdata = copy_n_obj(obj.begin(), obj.end());
	free();
	elements = newdata.first;
	end = newdata.second;
	data_front = elements + (obj.data_front - obj.elements);
	free_rear = elements + (obj.free_rear - obj.elements);
	return *this;
}

template <typename T>
T* dqueM::push_back(const T &data, size_t n)
{
	check_rear_alloc(n);
	for (auto i = 0; i < n; ++n)
		alloc.construct(free_rear++, T);
}




