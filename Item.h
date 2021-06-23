//
// Created by Admin on 05.06.2021.
//

#ifndef PRAKTIKUM3_ITEM_H
#define PRAKTIKUM3_ITEM_H

template <class T>
class Item {
public:
    Item(T info);
    void print();
    void setData(T data);
    void setNext(Item *next);
    void setPrevios(Item *previos);
    Item * getNext();
    Item * getPrevios();
    T getInfo();

private:
    T info;
    Item *next;
    Item *previos;
};

template <class T>
Item<T>::Item(T pinfo) {
    info = pinfo;
    next = nullptr;
    previos = nullptr;
}
template <class T>
void Item<T>::print() {
        std::cout << info << std::endl;

}

template <class T>
void Item<T>::setNext(Item *pnext) {
    next = pnext;
}

template <class T>
Item<T> * Item<T>::getNext() {
    return next;
}

template <class T>
T Item<T>::getInfo() {
    return info;
}

template<class T>
void Item<T>::setPrevios(Item *pprevios) {
    previos = pprevios;
}

template<class T>
Item<T> *Item<T>::getPrevios() {
    return previos;
}

template<class T>
void Item<T>::setData(T data) {
    info = data;
}

template<class T>
bool operator==(Item<T> &item1, Item<T> &item2) {
        if(item1.getInfo() == item2.getInfo()) {
            return true;
        }
    return false;
}
template<class T>
bool operator<(Item<T> &item1, Item<T> &item2) {
    if(item1.getInfo() < item2.getInfo()) {
        return true;
    }
    return false;
}
template<class T>
bool operator>(Item<T> &item1, Item<T> &item2) {
    if(item1.getInfo() > item2.getInfo()) {
        return true;
    }
    return false;
}
template<class T>
bool operator<=(Item<T> &item1, Item<T> &item2) {
    if(item1.getInfo() <= item2.getInfo()) {
        return true;
    }
    return false;
}
template<class T>
bool operator!=(Item<T> &item1, Item<T> &item2) {
    if(item1.getInfo() != item2.getInfo()) {
        return true;
    }
    return false;
}





#endif //PRAKTIKUM3_ITEM_H
