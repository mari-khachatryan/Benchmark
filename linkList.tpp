#include "linkList.h"


template <typename T>
LinkList<T>::~LinkList() {
    clear();
}

template <typename T>
int LinkList<T>::size() const {
    int count = 0;
	Node* current = head;
	while(current != nullptr){
		count++;
		current = current->next;
	}
	return count;
}

template <typename T>
void LinkList<T>::push_front(const T& val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void LinkList<T>::push_back(const T& val) {
    Node* newNode = new Node(val);
    if(!tail) {
        tail = newNode;
        head  = tail; 
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkList<T>::pop_front() {
    if(empty()) return;
    Node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
void LinkList<T>::pop_back() {
    if(!head) return;
    if(head == tail) {
        clear();
    }
    Node* tmp = head;
    while (tmp->next != tail) {
        tmp = tmp->next;
    }
    delete tail;
    tail = tmp;
    tail->next = nullptr;
    
}

template <typename T>
bool LinkList<T>::empty() {
    return head == nullptr;
}

template <typename T>
void LinkList<T>::clear() {
    while (!empty())
    {
        pop_front();
    }
    
}

template <typename T>
T& LinkList<T>::front() {
    return head->value;
}

template <typename T>
T& LinkList<T>::back() {
    return tail->value;
}

template <typename T>
void LinkList<T>::remove(const T& value) {
    if(head == nullptr) return;
    if(head->value == value) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    Node* curr = head;
    while(head != tail) {
        
        if(head->next->value == value) {
            Node* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
            return;

        }
        if(curr->next != nullptr) {
            curr = curr->next;
        }
    }
}

template <typename T>
void LinkList<T>::erase(int pos) {
    if(empty()){
		std::cout << "List is empty";
	} 
	if(pos < 0 || pos >= size()){
		std::cout << "Index out of range";
	}
	if(pos == 0){
		pop_front();
	}
    Node* current = head;
    Node* previous = nullptr;
    int count = 0;
    while (count < pos) {
        previous = current;
        current = current->next;
        count++;
    }
    previous->next = current->next;
    
    if (current == tail) {
        tail = previous;
    } else {
        current->next->prev = previous;
    }
    
    delete current;

}

template <typename T>
void LinkList<T>::insert(int pos, const T& val) {
    if (pos < 0 || pos > size()) {
        std::cout << "Invalid position";
    }
    
    if (pos == 0) {
        push_front(val);  
        return;
    }
    Node* current = head;
    Node* previous = nullptr;
    int count = 0;
    
    while (count < pos) {
        previous = current;
        current = current->next;
        count++;
    }
    
    Node* new_node = new Node(val);
    new_node->next = current;
    new_node->prev = previous;
    
    previous->next = new_node;
    
    if (current != nullptr) {
        current->prev = new_node;
    } else {
        tail = new_node;  
    }

}

template <typename T>
int LinkList<T>::find(const T& val) {
    Node* tmp = head;
    int index = 0;
    while (tmp != nullptr)
    {
        if(tmp->value == val) {
            return index;
        }
        tmp = tmp->next;
    }
    return -1;
}

template <typename T>
void LinkList<T>::printList(const LinkList<T>& myList) {
    Node* current = myList.head;

    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    std::cout << std::endl;
}