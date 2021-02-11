#pragma once
#include <algorithm>
#include "interface.h"

template <typename T>
class Array : public List<T>
{
public:
	void resize(int size)
	{
		capacity = size;
		if (begin)
		{
			T* temp_b = new int[size], *temp_e = temp_b + this->size();
			std::copy(begin, end, temp_b);
			delete[] begin;
			begin = temp_b; end = temp_e;
		}
		else
		{
			begin = new int[size]; end = begin;
		}
	}
	int size() const override { return end - begin; }
	bool empty() const override { return end == begin; }
	T& operator[](int index) override { return begin[index]; }
	T& front() override { return *begin; }
	T& back() override { return *(end - 1); }
	const T& at(int index) const override { return begin[index]; }
	const T& front() const override { return *begin; }
	const T& back() const override { return *(end - 1); }
	T insert(T value, int index = 0) override
	{
		displaceR(index);
		begin[index] = value;
		return value;
	}
	T push_back(T value) override
	{
		displaceR(size());
		begin[size() - 1] = value;
		return value;
	}
	T push_front(T value) override
	{
		displaceR(0);
		begin[0] = value;
		return value;
	}
	void eraseByIndex(int index) override
	{
		displaceL(index);
	}
	void pop_back() override
	{
		displaceL(size() - 1);
	}
	void pop_front() override
	{
		displaceL(0);
	}
	bool eraseByValue(T value) override
	{
		for (int i = 0; i < size(); i++)
		{
			if (value == begin[i])
			{
				eraseByIndex(i);
				return true;
			}
		}
		return false;
	}
	void clear() override { end = begin; }
	int getIndexOf(T value) const override
	{
		for (int i = 0; i < size(); i++)
		{
			if (value == begin[i])
			{
				return i;
			}
		}
		return -1;
	}
	T sum() const override
	{
		T Sum = 0;
		for (int i = 0; i < size(); ++i)
		{
			Sum += begin[i];
		}
		return Sum;
	}
private:
	void displaceR(int pos, int dist = 1)
	{
		if (size() == capacity)
		{
			if (capacity) resize(size() * 2);
			else resize(1);
		}
		int curr = size() - 1;
		end += dist;
		while (curr >= pos)
		{
			begin[curr + dist] = begin[curr];
			curr--;
		}
	}
	void displaceL(int pos)
	{
		while (++pos < size())
		{
			begin[pos - 1] = begin[pos];
		}
		--end;
	}
	T* begin = nullptr, *end = nullptr;
	int capacity = 0;
};

