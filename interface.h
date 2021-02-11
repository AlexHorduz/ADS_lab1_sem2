#pragma once

template <class T>
class List {
public:
	virtual T insert(T value, int index = 0) = 0; //returns an added value
	virtual T push_back(T value) = 0;
	virtual T push_front(T value) = 0;
	virtual bool eraseByValue(T value) = 0; //returns true if the element was present
	virtual void eraseByIndex(int index) = 0; //returns true if the deletion was successfull
	virtual void pop_back() = 0; //returns true if the deletion was successfull
	virtual void pop_front() = 0; //returns true if the deletion was successfull
	virtual void clear() = 0; //clears the List
	virtual T& operator[](int index) = 0;
	virtual T& front() = 0;
	virtual T& back() = 0;
	virtual const T& at(int index) const = 0; //returns an element at index 'index'
	virtual const T& front() const = 0;
	virtual const T& back() const = 0;
	virtual int getIndexOf(T value) const = 0; //returns -1 if there are no such elements
	virtual int size() const = 0;
	virtual bool empty() const = 0;
	virtual T sum() const = 0;
};