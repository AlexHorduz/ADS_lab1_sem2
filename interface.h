#pragma once

template <class T>
class List {
public:
	virtual T insert(T value, int index = 0) = 0;
	virtual T push_back(T value) = 0;
	virtual T push_front(T value) = 0;
	virtual bool eraseByValue(T value) = 0;
	virtual void eraseByIndex(int index) = 0;
	virtual void pop_back() = 0;
	virtual void pop_front() = 0;
	virtual void clear() = 0;
	virtual T& operator[](int index) = 0;
	virtual T& front() = 0;
	virtual T& back() = 0;
	virtual const T& at(int index) const = 0;
	virtual const T& front() const = 0;
	virtual const T& back() const = 0;
	virtual int getIndexOf(T value) const = 0; 
	virtual int size() const = 0;
	virtual bool empty() const = 0;
	virtual T sum() const = 0;
};
