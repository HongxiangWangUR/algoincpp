#include <iostream>
#ifndef LIST
#define LIST
namespace list{
    template <typename T> class SinglyLinkedList{
        private:
        class Node{
            private:
            Node *next;
            public:
            T *element;
            Node(T* e,Node* n);
            T* getElement();
            Node* getNext();
            void setNext(Node *n);
        };
        Node* head;
        public:
        T* first(){
            return this->head->element;
        }
        SinglyLinkedList(){
            int *e=new int(3);
            this->head=new Node(e,nullptr);
        }
    };
}

template<typename T> list::SinglyLinkedList<T>::Node::Node(T* e,Node* n):element(e),next(n){}

template<typename T> T* list::SinglyLinkedList<T>::Node::getElement(){
    return this->element;
}

template<typename T> typename list::SinglyLinkedList<T>::Node* list::SinglyLinkedList<T>::Node::getNext(){
    return this->next;
}

template<class T> void list::SinglyLinkedList<T>::Node::setNext(Node* n){
    this->next=n;
}
#endif