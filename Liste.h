//
// Created by Admin on 05.06.2021.
//

#ifndef PRAKTIKUM3_LISTE_H
#define PRAKTIKUM3_LISTE_H

#include "Item.h"

using namespace std;

template<class T>
class Liste {
private:
    Item<T> *first;
    Item<T> *current;
    Item<T> *last;

public:
    Liste();

    Item<T> *get();

    Item<T> *get(int index);

    bool empty();

    bool end();

    void adv();

    void reset();


    void ins(Item<T> *item);

    void del();

    void print();

    void printTree();

    void printTreeItem(Item<T> *item);

    void swap(Item<T> *item1, Item<T> *item2);

    Item<T> *getParent(int index);

    Item<T> *getLeftChild(int index);

    Item<T> *getRightChild(int index);

    void heapify();

    Liste<T> heapSort();

    void quickSort(Item<T> *item1, Item<T> *item2);

    Item<T> *newpivot(Item<T> *item1, Item<T> *item2);

    Liste<T> stableQuickSort();

    Item<T> *randomItem(Item<T> *item1, Item<T> *item2);


    Liste<T> merge(Liste<T> &liste1, Liste<T> &list2);

    Liste<T> mergeSort();

    Item<T> *getFirst();

    Item<T> *getCurrent();

    Item<T> *getLast();

    int getLength();
};

template<class T>
Liste<T>::Liste() {
    first = NULL;
    current = NULL;
    last = NULL;
}

template<class T>
void Liste<T>::print() {
    if (first == NULL) {
        return;
    }
    Item<T> *item = first;

    while (item != NULL) {
        std::cout << "-------------" << std::endl;
        Item<T> *previos = item->getPrevios();
        if (previos != NULL) {
            std::cout << "Previos : ";
            previos->print();
        }
        std::cout << "Info : ";
        item->print();
        Item<T> *next = item->getNext();
        if (next != NULL) {
            std::cout << "Next : ";
            next->print();
        }
        item = item->getNext();
        std::cout << "-------------" << std::endl;
    }

    std::cout << "First :" << first->getInfo() << std::endl;
    std::cout << "Current :" << current->getInfo() << std::endl;
    std::cout << "Last :" << last->getInfo() << std::endl;
}

template<class T>
Item<T> *Liste<T>::get() {
    return current;
}

template<class T>
bool Liste<T>::empty() {
    if (first == NULL) {
        return true;
    }
    return false;
}

template<class T>
bool Liste<T>::end() {
    if (current->getNext() == NULL) {
        return true;
    }
    return false;
}

template<class T>
void Liste<T>::adv() {
    if (current->getNext() != NULL) {
        current = current->getNext();
    } else {
        std::cout << "Das Ende der Liste wurde erreicht." << std::endl;
    }
}

template<class T>
void Liste<T>::reset() {
    current = first;
}

template<class T>
void Liste<T>::ins(Item<T> *item) {

    if (first == NULL) {
        first = item;
        current = item;
        last = item;
        return;
    }

    Item<T> *tmpitem = first;

    last->setNext(item);
    item->setPrevios(last);
    last = item;
    current = item;


//    if (*item < *first) {
//        item->setNext(first);
//        first->setPrevios(item);
//        first = item;
//        current = item;
//        return;
//    }
//    if (*item > *last) {
//        last->setNext(item);
//        item->setPrevios(last);
//        last = item;
//        current = item;
//        return;
//    }
//    while (tmpitem != NULL) {
//        if (*tmpitem < *item && *tmpitem->getNext() > *item) {
//            item->setPrevios(tmpitem);
//            item->setNext(tmpitem->getNext());
//            tmpitem->getNext()->setPrevios(item);
//            tmpitem->setNext(item);
//            break;
//        }
//        tmpitem = tmpitem->getNext();
//    }
//    current = item;
}

template<class T>
void Liste<T>::del() {

    Item<T> *item = first;


    while (item != NULL) {
        if (*item == *current) {
            Item<T> *previos = current->getPrevios();
            Item<T> *next = current->getNext();
            if (previos != NULL && next != NULL) {
                next->setPrevios(previos);
                previos->setNext(next);
                break;
            }
            if (previos != NULL) {
                previos->setNext(nullptr);
                last = previos;
            }
            if (next != NULL) {
                next->setPrevios(nullptr);
                first = next;
            }

        }
        item = item->getNext();
    }
    delete current;
    current = first;
}

template<class T>
Item<T> *Liste<T>::getFirst() {
    return first;
}

template<class T>
Item<T> *Liste<T>::getCurrent() {
    return current;
}

template<class T>
Item<T> *Liste<T>::getLast() {
    return last;
}

template<class T>
Liste<T> Liste<T>::merge(Liste<T> &liste1, Liste<T> &liste2) {

    Liste<T> liste = Liste<T>();
    Item<T> *item1 = liste1.getFirst();
    Item<T> *item2 = liste2.getFirst();

    while (item1 != NULL || item2 != NULL) {
        if (item1 == NULL) {
            liste.ins(new Item<T>(item2->getInfo()));
            item2 = item2->getNext();
            continue;
        }
        if (item2 == NULL) {
            liste.ins(new Item<T>(item1->getInfo()));
            item1 = item1->getNext();
            continue;
        }
        if (*item1 == *item2) {
            liste.ins(new Item<T>(item1->getInfo()));
            item1 = item1->getNext();
            continue;
        }

        if (*item1 < *item2) {
            liste.ins(new Item<T>(item1->getInfo()));
            item1 = item1->getNext();
        } else {
            liste.ins(new Item<T>(item2->getInfo()));
            item2 = item2->getNext();
        }
    }
    return liste;
}

template<class T>
Liste<T> Liste<T>::mergeSort() {
    Liste<T> liste1 = Liste<T>();
    Liste<T> liste2 = Liste<T>();
    Liste<T> sortedliste1 = Liste<T>();
    Liste<T> sortedliste2 = Liste<T>();
    Liste<T> sortedlist = Liste<T>();
    Item<T> *item = first;
    int middle = getLength() / 2;

    if (getLength() == 1) {
        sortedlist.ins(new Item<T>(first->getInfo()));
        return sortedlist;
    }

    for (int i = 0; i < middle; i++) {
        liste1.ins(new Item<T>(item->getInfo()));
        item = item->getNext();
    }
    for (int i = middle; i < getLength(); i++) {
        liste2.ins(new Item<T>(item->getInfo()));
        item = item->getNext();
    }

    if (liste1.getLength() == 1 && liste2.getLength() == 1) {
        if (*liste1.getFirst() < *liste2.getFirst()) {
            sortedlist.ins(liste1.getFirst());
            sortedlist.ins(liste2.getFirst());
        } else {

            sortedlist.ins(liste2.getFirst());
            sortedlist.ins(liste1.getFirst());
        }
        return sortedlist;
    }
    sortedliste1 = liste1.mergeSort();
    sortedliste2 = liste2.mergeSort();

    return merge(sortedliste1, sortedliste2);
}

template<class T>
int Liste<T>::getLength() {
    int length = 0;
    Item<T> *item = first;
    while (item != NULL) {
        length++;
        item = item->getNext();
    }
    return length;
}

template<class T>
void Liste<T>::printTree() {
    Item<T> *item0 = first;
    Item<T> *item1 = first->getNext();
    Item<T> *item2 = NULL;
    Item<T> *item3 = NULL;
    Item<T> *item4 = NULL;
    Item<T> *item5 = NULL;
    Item<T> *item6 = NULL;
    Item<T> *item7 = NULL;
    Item<T> *item8 = NULL;
    Item<T> *item9 = NULL;
    Item<T> *item10 = NULL;
    Item<T> *item11 = NULL;
    Item<T> *item12 = NULL;
    Item<T> *item13 = NULL;
    Item<T> *item14 = NULL;
    if (item1 != NULL) { item2 = item1->getNext(); }
    if (item2 != NULL) { item3 = item2->getNext(); }
    if (item3 != NULL) { item4 = item3->getNext(); }
    if (item4 != NULL) { item5 = item4->getNext(); }
    if (item5 != NULL) { item6 = item5->getNext(); }
    if (item6 != NULL) { item7 = item6->getNext(); }
    if (item7 != NULL) { item8 = item7->getNext(); }
    if (item8 != NULL) { item9 = item8->getNext(); }
    if (item9 != NULL) { item10 = item9->getNext(); }
    if (item10 != NULL) { item11 = item10->getNext(); }
    if (item11 != NULL) { item12 = item11->getNext(); }
    if (item12 != NULL) { item13 = item12->getNext(); }
    if (item13 != NULL) { item14 = item13->getNext(); }


    std::cout << "                  ----------";
    printTreeItem(item0);
    std::cout << "----------" << std::endl;
    std::cout << "                /                      \\" << std::endl;
    std::cout << "         ------";
    printTreeItem(item1);
    std::cout << "------            ------";
    printTreeItem(item2);
    std::cout << "------" << std::endl;
    std::cout << "        /       " << "      \\          /      " << "       \\" << std::endl;
    std::cout << "     --";
    printTreeItem(item3);
    std::cout << "--           --";
    printTreeItem(item4);
    std::cout << "--    --";
    printTreeItem(item5);
    std::cout << "--           --";
    printTreeItem(item6);
    std::cout << "--" << std::endl;
    std::cout << "    /     \\         /     \\  /     \\         /     \\ " << std::endl;
    std::cout << "    ";
    printTreeItem(item7);
    std::cout << "     ";
    printTreeItem(item8);
    std::cout << "      ";
    printTreeItem(item9);
    std::cout << "     ";
    printTreeItem(item10);
    std::cout << "  ";
    printTreeItem(item11);
    std::cout << "     ";
    printTreeItem(item12);
    std::cout << "     ";
    printTreeItem(item13);
    std::cout << "       ";
    printTreeItem(item14);
    std::cout << std::endl;


}

template<class T>
void Liste<T>::printTreeItem(Item<T> *item) {
    if (item == NULL) {
        std::cout << " ";
    } else {
        std::cout << item->getInfo();
    }
}

template<class T>
Item<T> *Liste<T>::getParent(int index) { //(index-1)/2
    Item<T> *item = first;
    int parent = (index - 1) / 2;
    for (int i = 0; i < parent; i++) {
        item = item->getNext();
        if (item == NULL) {
            return NULL;
        }
    }
    return item;
}

template<class T>
Item<T> *Liste<T>::getLeftChild(int index) {
    Item<T> *item = first;
    int leftchild = 2 * index + 1;
    for (int i = 0; i < leftchild; i++) {
        item = item->getNext();
        if (item == NULL) {
            return NULL;
        }
    }
    return item;
}

template<class T>
Item<T> *Liste<T>::getRightChild(int index) {
    Item<T> *item = first;
    int rightchild = 2 * (index + 1);
    for (int i = 0; i < rightchild; i++) {
        item = item->getNext();
        if (item == NULL) {
            return NULL;
        }
    }
    return item;
}

template<class T>
void Liste<T>::heapify() {
    Item<T> *item = first;
    int length = getLength();
    while (item->getNext() != NULL) {
        item = item->getNext();
    }
    while (length >= 1) {
        if (*item < *getParent(length)) {
            Item<T> *parent = getParent(length);
            Item<T> *parentprevios = getParent(length)->getPrevios();
            Item<T> *parentnext = getParent(length)->getNext();
            Item<T> *itemprevios = item->getPrevios();
            Item<T> *itemnext = item->getNext();
            if (parentprevios != NULL) {
                item->setPrevios(parentprevios);
            } else {
                item->setPrevios(nullptr);
                first = item;
            }
            if (item != parentnext) {
                item->setNext(parentnext);
            } else {
                item->setNext(parent);
            }
            itemprevios->setNext(parent);
            if (itemnext != NULL) {
                itemnext->setPrevios(parent);
            }
            if (parent != itemprevios) {
                parent->setPrevios(itemprevios);
            } else {
                parent->setPrevios(item);
            }
            if (itemnext != NULL) {
                parent->setNext(itemnext);
            } else {
                parent->setNext(nullptr);
                last = item;
            }
            if (parentprevios != NULL) {
                parentprevios->setNext(item);
            }
            parentnext->setPrevios(item);
        }
        item = get(length - 1);
        length--;
    }
}

template<class T>
Item<T> *Liste<T>::get(int index) {
    Item<T> *item = first;
    for (int i = 0; i < index; i++) {
        item = item->getNext();
    }
    return item;
}

template<class T>
Liste<T> Liste<T>::heapSort() {
    Liste<T> liste = Liste<T>();
    while (get(1) != NULL) {
        heapify();
        liste.ins(first);
        printTree();
        if (first->getNext() != NULL) {
            first = get(1);
            if (first->getNext() != NULL) {
                first->setPrevios(nullptr);
            }
        }
    }
    return liste;
}

template<class T>
Item<T> *firstpivot = NULL;
template<class T>
void Liste<T>::quickSort(Item<T> *item1, Item<T> *item2) {


    if (*item1 == *item2) {
        return;
    }
    int length = 0;
    Item<T> *tmp2 = first;
    Item<T> *tmp = item1;
    while (tmp != item2) {
        tmp = tmp->getNext();
        length++;
    }
    while (tmp2 != item1){
        tmp2 = tmp2->getNext();
        length++;
    }
    Item<T> *randompivot = item2;
    if(firstpivot<T> == NULL){
    firstpivot<T> = new Item<T>(item2->getInfo());
    }
    if (*randompivot == *item1) {
        return;
    }
    Item<T> *low = item1;
    Item<T> *high = item2;


    while (low != high) {
        while (low != high) {
            if (*low > *randompivot) {
                swap(low, high);
                randompivot = low;
                break;
            } else {
                low = low->getNext();

            }
        }
        while (low != high) {
            if (*high < *randompivot) {
                swap(high, low);
                randompivot = high;
                break;
            } else {
                high = high->getPrevios();
            }
        }
    }

    if(randompivot->getNext() != NULL &&randompivot->getPrevios() != NULL) {
        quickSort(first, randompivot->getPrevios());
    }
    if(*randompivot != *firstpivot<T>){
        return;
    }
    if(randompivot->getNext() != NULL) {
        quickSort(randompivot->getNext(), last);
    }
}


template<class T>
void Liste<T>::swap(Item<T> *item1, Item<T> *item2) {
    if (*item1 == *item2) {
        return;
    }

    Item<T> *tmp = new Item<T>(item1->getInfo());
    Item<T> *item = item2;

    item1->setData(item2->getInfo());
    item2->setData(tmp->getInfo());
}

template<class T>
Item<T> *Liste<T>::randomItem(Item<T> *item1, Item<T> *item2) {
    Item<T> *item = first;
    int number1 = 0, number2 = 0, counter = 0;
    while (item != NULL) {
        if (*item == *item1) {
            number1 = counter;
        }
        if (*item == *item2) {
            number2 = counter;
        }
        counter++;
        item = item->getNext();
    }
    item = get(rand() % (number2 - number1 + 1) + number1 - 1);

    return item;
}

template<class T>
Liste<T> Liste<T>::stableQuickSort() {
    Liste<T> sortedlist = Liste<T>();
    Liste<T> liste1 = Liste<T>();
    Liste<T> liste2 = Liste<T>();
    Liste<T> sortedliste1 = Liste<T>();
    Liste<T> sortedliste2 = Liste<T>();
    Item<T> *item = first;
    Item<T> *pivot = last;

    if (getLength() == 1) {
        sortedlist.ins(new Item<T>(first->getInfo()));
        return sortedlist;
    }
    if (liste1.getLength() == 1 && liste2.getLength() == 1) {
        if (*liste1.getFirst() < *liste2.getFirst()) {
            sortedlist.ins(liste1.getFirst());
            sortedlist.ins(liste2.getFirst());
        } else {

            sortedlist.ins(liste2.getFirst());
            sortedlist.ins(liste1.getFirst());
        }
        return sortedlist;
    }

    for(int i = 0;i<getLength();i++){
        if(*item < *pivot){
            liste1.ins(new Item<T>(item->getInfo()));
        } else{
            liste2.ins(new Item<T>(item->getInfo()));
        }
        item = item->getNext();
    }

    if(liste1.empty()){
        liste1.ins(new Item<T>(liste2.getLast()->getInfo()));
        liste2.del();
    }

    sortedliste1 = liste1.stableQuickSort();
    sortedliste2 = liste2.stableQuickSort();
    return merge(sortedliste1, sortedliste2);
}


#endif //PRAKTIKUM3_LISTE_H



