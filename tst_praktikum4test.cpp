#include <QtTest>

// add necessary includes here
#include<Liste.h>

class Praktikum4Test : public QObject
{
    Q_OBJECT

public:
    Praktikum4Test();
    ~Praktikum4Test();

private slots:

    void testMergeSort();
    void testHeapSort();
    void testQuickSort();
    void testStableQuickSort();


};

Praktikum4Test::Praktikum4Test()
{

}

Praktikum4Test::~Praktikum4Test()
{

}

void Praktikum4Test::testMergeSort()
{
    Liste<int> list = Liste<int>();
    Liste<int> list2 = Liste<int>();
    Item<int> *item1 = new Item<int>(5);
        Item<int> *item2 = new Item<int>(64);
        Item<int> *item3 = new Item<int>(12);
        Item<int> *item4 = new Item<int>(35);
        Item<int> *item5 = new Item<int>(11);
        list.ins(item1);
        list.ins(item2);
        list.ins(item3);
        list.ins(item4);
        list.ins(item5);

        list2 = list.mergeSort();

        Item<int> *item = list2.getFirst();
        while (item->getNext() != NULL) {
            int info1 = item->getInfo();
            item = item->getNext();
            int info2 = item->getInfo();
            QVERIFY(info1<info2);
        }
}

void Praktikum4Test::testHeapSort()
{
    Liste<int> list = Liste<int>();
    Liste<int> list2 = Liste<int>();
    Item<int> *item1 = new Item<int>(5);
        Item<int> *item2 = new Item<int>(64);
        Item<int> *item3 = new Item<int>(12);
        Item<int> *item4 = new Item<int>(35);
        Item<int> *item5 = new Item<int>(11);
        list.ins(item1);
        list.ins(item2);
        list.ins(item3);
        list.ins(item4);
        list.ins(item5);

        list2 = list.heapSort();

        Item<int> *item = list2.getFirst();
        while (item->getNext() != NULL) {
            int info1 = item->getInfo();
            item = item->getNext();
            int info2 = item->getInfo();
            QVERIFY(info1<info2);
        }
}

void Praktikum4Test::testQuickSort()
{
    Liste<int> list = Liste<int>();
    Item<int> *item1 = new Item<int>(5);
        Item<int> *item2 = new Item<int>(64);
        Item<int> *item3 = new Item<int>(12);
        Item<int> *item4 = new Item<int>(35);
        Item<int> *item5 = new Item<int>(11);
        list.ins(item1);
        list.ins(item2);
        list.ins(item3);
        list.ins(item4);
        list.ins(item5);

        list.quickSort(list.getFirst(),list.getLast());


        Item<int> *item = list.getFirst();
        while (item->getNext() != NULL) {
            int info1 = item->getInfo();
            item = item->getNext();
            int info2 = item->getInfo();
            QVERIFY(info1<info2);
        }
}
void Praktikum4Test::testStableQuickSort()
{
    Liste<int> list = Liste<int>();
    Liste<int> list2 = Liste<int>();
    Item<int> *item1 = new Item<int>(5);
        Item<int> *item2 = new Item<int>(64);
        Item<int> *item3 = new Item<int>(12);
        Item<int> *item4 = new Item<int>(35);
        Item<int> *item5 = new Item<int>(11);
        list.ins(item1);
        list.ins(item2);
        list.ins(item3);
        list.ins(item4);
        list.ins(item5);

        list2 = list.stableQuickSort();

        Item<int> *item = list2.getFirst();
        while (item->getNext() != NULL) {
            int info1 = item->getInfo();
            item = item->getNext();
            int info2 = item->getInfo();
            QVERIFY(info1<info2);
        }
}
QTEST_APPLESS_MAIN(Praktikum4Test)

#include "tst_praktikum4test.moc"
