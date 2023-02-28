//
// Created by PC on 1.12.2022.
// Name: Berk Sara
// Student Number: 22102354
// Section 2
//

#ifndef CS_HW_NODE_H
#define CS_HW_NODE_H

template <class ItemType, class I2>
class Node {
public:
    Node();
    Node(const ItemType& newItem, const I2& newItem2 );
    Node(const ItemType& newItem, const I2& newItem2, Node<ItemType, I2>* newNext);
    void setItem1(const ItemType& newItem);
    void setItem2(const I2& newItem2);
    void setNext(Node<ItemType, I2>* newNext);
    ItemType getItem1() const;
    I2 getItem2() const;
    Node<ItemType, I2>* getNext() const;
private:
    ItemType item;
    I2 item2;
    Node<ItemType, I2>* next;
};

template<class ItemType, class I2>
Node<ItemType, I2>::Node() : next(nullptr){ }

template<class ItemType, class I2>
Node<ItemType, I2>::Node(const ItemType &newItem, const I2 &newItem2) {
    item = newItem;
    item2 = newItem2;
    next = nullptr;
}

template<class ItemType, class I2>
Node<ItemType, I2>::Node(const ItemType &newItem, const I2 &newItem2, Node<ItemType, I2> *newNext) {
    item = newItem;
    item2 = newItem2;
    next = newNext;
}

template<class ItemType, class I2>
void Node<ItemType, I2>::setItem1(const ItemType &newItem) {
    item = newItem;
}

template<class ItemType, class I2>
void Node<ItemType, I2>::setItem2(const I2 &newItem2) {
    item2 = newItem2;
}

template<class ItemType, class I2>
void Node<ItemType, I2>::setNext(Node<ItemType, I2> *newNext) {
    next = newNext;
}

template<class ItemType, class I2>
ItemType Node<ItemType, I2>::getItem1() const {
    return item;
}

template<class ItemType, class I2>
I2 Node<ItemType, I2>::getItem2() const {
    return item2;
}

template<class ItemType, class I2>
Node<ItemType, I2> *Node<ItemType, I2>::getNext() const {
    return next;
}



#endif //CS_HW_NODE_H
