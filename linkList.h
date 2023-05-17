#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

template <typename T>
class LinkList {
public:
    LinkList() : head{nullptr}, tail{nullptr} {}
	~LinkList();
    // Node* gethead() const;
    // Node* gettail() const;
    int size() const;
	void push_front(const T& val);
	void push_back(const T& val);
	void pop_front();
	void pop_back();
	bool empty();
    void clear();
	T& front();
	T& back();
	void remove(const T& value);
	void erase(int pos);
	void insert(int pos, const T& val);
	int find(const T& val);
	void printList(const LinkList<T>& myList);
private:
    struct Node{
        T value;
        Node* next;
        Node* prev; 
        Node(const T& a) : value{a}, next{nullptr}, prev{nullptr} {}
    };
    Node* head;
    Node* tail;
};

#include "linkList.tpp"

#endif //LINKLIST_H