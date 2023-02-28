//
// Created by PC on 1.12.2022.
// Name: Berk Sara
// Student Number: 22102354
// Section 2

#ifndef CS_HW_SORTEDLINKEDLIST_H
#define CS_HW_SORTEDLINKEDLIST_H
#include "Node.h"

template<class ItemType, class I2>
class SortedLinkedList {
public:
    SortedLinkedList();
    ~SortedLinkedList();
    //SortedLinkedList(const SortedLinkedList<ItemType,I2>& s);
    bool isEmpty() const;
    int getLength() const;
    bool insert(const ItemType& newItem1, const I2& newItem2, bool isBool);
    bool remove(const ItemType& newItem1);
    Node<ItemType, I2>* getNode(const ItemType& newItem1 );
    bool doesExists(const ItemType& newItem1);
    Node<ItemType, I2>* getNodeByPosition(const int position);
private:
    Node<ItemType, I2>* head;
    int size;
};

template<class ItemType, class I2>
SortedLinkedList<ItemType, I2>::SortedLinkedList() : head(nullptr) {
    size = 0;
}

template<class ItemType, class I2>
bool SortedLinkedList<ItemType, I2>::isEmpty() const {
    if(size == 0){ return true;}
    else{ return false;}
}

template<class ItemType, class I2>
int SortedLinkedList<ItemType, I2>::getLength() const {
    return size;
}

template<class ItemType, class I2>
bool SortedLinkedList<ItemType, I2>::insert(const ItemType &newItem1, const I2 &newItem2, bool isBool) {
    if(doesExists(newItem1) && !isBool ){
        return false;
    }
    Node<ItemType, I2>* newNode = new Node<ItemType, I2>(newItem1, newItem2);
    if(size == 0){
        head = newNode;
        size++;
        return true;
    }
    else{
        Node<ItemType,I2>* temp = head;
        Node<ItemType,I2>* tail = head;
        while(temp != nullptr){
            if( newNode->getItem1() < temp->getItem1() ){
                if(temp == head){
                    newNode->setNext(head);
                    head  = newNode;
                    size++;
                    return true;
                }
                newNode->setNext(temp);
                tail->setNext(newNode);
                size++;
                return true;
            }
            else{
                if(temp->getNext() == nullptr){
                    temp->setNext(newNode);
                    size++;
                    return true;
                }
                if(temp != head){
                    tail = tail->getNext();
                }
                temp = temp->getNext();

            }
        }
    }
    return false;
}

template<class ItemType, class I2>
bool SortedLinkedList<ItemType, I2>::remove(const ItemType& newItem1) {
    if( !doesExists(newItem1) ){
        return false;
    }
    Node<ItemType, I2>* temp = head;
    if(newItem1 == head->getItem1()){
        head = head->getNext();
        size--;
        delete temp;
        return true;
    }
    temp = temp->getNext();
    Node<ItemType, I2>* tail = head;
    while(temp != nullptr){
        if(temp->getItem1() == newItem1){
            tail->setNext( temp->getNext() );
            size--;
            delete temp;
            return true;
        }
        temp = temp->getNext();
        tail = tail->getNext();
    }
    return false;
}
/*  Deletes the linkedlist by going to the end and deleting every node
 * */
template<class ItemType, class I2>
SortedLinkedList<ItemType, I2>::~SortedLinkedList() {
    //traverse all and delete
    Node<ItemType,I2>* temp;
    while(head != nullptr){
        temp = head;
        head = head->getNext();
        delete temp;
    }
}

template<class ItemType, class I2>
bool SortedLinkedList<ItemType, I2>::doesExists(const ItemType& newItem1) {
    Node<ItemType, I2>* temp = head;
    while(temp != nullptr){
        if(newItem1 == temp->getItem1() ){
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

template<class ItemType, class I2>
Node<ItemType, I2> *SortedLinkedList<ItemType, I2>::getNode(const ItemType& newItem1) {
    Node<ItemType, I2>* temp = head;
    while(temp != nullptr){
        if(newItem1 == temp->getItem1() ){
            return temp;
        }
        temp = temp->getNext();
    }
    return nullptr;
}

template<class ItemType, class I2>
Node<ItemType, I2> *SortedLinkedList<ItemType, I2>::getNodeByPosition(const int position) {
    if(position <= 0 || position > size){ return nullptr; }
    Node<ItemType, I2>* temp = head;
    for (int i = 1; i < size + 1; ++i) {
        if(position == i){
            return temp;
        }
        temp = temp->getNext();
    }
    return nullptr;
}


#endif //CS_HW_SORTEDLINKEDLIST_H
