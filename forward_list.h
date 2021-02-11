#pragma once
#include "interface.h"
#include <stdexcept>

template<class T>
class Forward_list : public List<T> {
private:
	struct Node {
		T val;
		Node* next;
	} *beg = nullptr;
    int _size = 0;
public:
    T insert(T value, int index = 0) override {
        Node* n = new Node{value};
        if (index == 0) {
            n->next = beg;
            beg = n;
        }
        else {
            Node* prevn = getNode(index - 1);
            n->next = prevn->next;
            prevn->next = n;
        }
        _size++;
        return value;
    }
    T push_back(T value) override {
        return insert(value, _size);
    }
    T push_front(T value) override {
        return insert(value, 0);
    }
    bool eraseByValue(T value) override {
        Node *curNode = beg, *prevNode = nullptr;
        while (curNode && curNode->val != value) {
            prevNode = curNode;
            curNode = curNode->next;
        }
        if (curNode) {
            if (prevNode)
                prevNode->next = curNode->next;
            else
                beg = curNode->next;
            delete curNode;
            _size--;
            return true;
        }
        return false;
    }
    void eraseByIndex(int index) override {
        if (index == 0) {
            if (!beg)
                throw std::out_of_range("");
            auto nextNode = beg->next;
            delete beg;
            beg = nextNode;
        }
        else {
            auto node = getNode(index - 1);
            if (!node->next)
                throw std::out_of_range("");
            auto nextNode = node->next->next;
            delete node->next;
            node->next = nextNode;
        }
        _size--;
    }
    void pop_back() override {
        eraseByIndex(_size - 1);
    }
    void pop_front() override {
        eraseByIndex(0);
    }
    void clear() override {
        Node *node = beg, *nextNode;
        beg = nullptr;
        while (node) {
            nextNode = node->next;
            delete node;
            node = nextNode;
        }
        _size = 0;
    }
    T& operator[](int index) override {
        return getNode(index)->val;
    }
    T& front() override {
        return (*this)[0];
    }
    T& back() override {
        return (*this)[_size - 1];
    }
    const T& at(int index) const override {
        return getNode(index)->val;
    }
    const T& front() const override {
        return at(0);
    }
    const T& back() const override {
        return at(_size - 1);
    }
    int getIndexOf(T value) const override {
        auto node = beg;
        int i = 0;
        while (node && node->val != value) {
            node = node->next;
            i++;
        }
        if (node)
            return i;
        else
            return -1;
    }
    int size() const override {
        return _size;
    }
    bool empty() const override {
        return !beg;
    }
    T sum() const override {
        auto node = beg;
        T res = getNode(0)->val;
        node = node->next;
        while (node) {
            res += node->val;
            node = node->next;
        }
        return res;
    }
private:
    Node* getNode(int index) const {
        Node* res = beg;
        for (int i = 0; i < index && res; i++) {
            res = res->next;
        }
        if (!res)
            throw std::out_of_range("");
        return res;
    }
};
