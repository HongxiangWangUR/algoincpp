#include <iostream>
#include <string>
#ifndef LIST
#define LIST
namespace list{
    template <typename T> class SinglyLinkedList{
        private:
        class Node{
            private:
            Node *next;
            T *element;
            public:
            Node(T* e,Node* n);
            T* getElement();
            Node* getNext();
            void setNext(Node *n);
            ~Node();
        };
        Node* head;
        Node* tail;
        int size;
        public:
        SinglyLinkedList();
        T* first();
        bool isEmpty();
        T* last();
        void addFirst(T*);
        void addLast(T*);
        T* removeFirst();
        ~SinglyLinkedList();
        std::string to_string();
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

template<typename T> list::SinglyLinkedList<T>::Node::~Node(){
    std::cout<<"销毁node对象"<<*element<<std::endl;
    next=nullptr;
    delete element;
    element=nullptr;
}
template<class T> list::SinglyLinkedList<T>::SinglyLinkedList():head(nullptr),tail(nullptr),size(0){}

template<class T> T* list::SinglyLinkedList<T>::first(){
    if(isEmpty()){
        return nullptr;
    }
    return this->head->getElement();
}
template<typename T> bool list::SinglyLinkedList<T>::isEmpty(){
    return this->size==0;
}
template<typename T> T* list::SinglyLinkedList<T>::last(){
    if(isEmpty()){
        return nullptr;
    }
    return this->tail->getElement();
}
template<typename T> void list::SinglyLinkedList<T>::addFirst(T* e){
    Node* node=new Node(e,head);
    if(isEmpty()){
        tail=node;
    }
    head=node;
    size++;
}
template<typename T> void list::SinglyLinkedList<T>::addLast(T* e){
    Node* node=new Node(e,nullptr);
    if(isEmpty()){
        head=node;
    }else{
        tail->setNext(node);
    }
    tail=node;
    size++;
}

template<typename T> T* list::SinglyLinkedList<T>::removeFirst(){
    if(isEmpty()){
        return nullptr;
    }
    Node* temp=head;
    head=head->getNext();
    temp->setNext(nullptr);
    T* result=new T(*(temp->getElement()));
    size--;
    if(isEmpty()){
        tail=nullptr;
    }
    delete temp;
    return result;
}

template<typename T> list::SinglyLinkedList<T>::~SinglyLinkedList(){
    Node* cursor=head;
    for(int i=0;i<size;i++){
        Node* temp=cursor->getNext();
        delete cursor;
        cursor=temp;
    }
}

template<typename T> std::string list::SinglyLinkedList<T>::to_string(){
    if(isEmpty()){
        return "null";
    }
    std::string result="head->";
    Node* cursor=head;
    while(cursor!=nullptr){
        result+=(std::to_string(*(cursor->getElement())));
        result+="->";
        cursor=cursor->getNext();
    }
    result+="tail";
    return result;
}
#endif