#include <QtTest>

#include <Liste.h>

// add necessary includes here

class Praktikum3_Test : public QObject
{
    Q_OBJECT

public:
    Praktikum3_Test();
    ~Praktikum3_Test();

private slots:
    void insStart();
    void insMiddle();
    void insEnd();

    void delStart();
    void delMiddle();
    void delEnd();


};

Praktikum3_Test::Praktikum3_Test()
{
}

Praktikum3_Test::~Praktikum3_Test()
{

}

void Praktikum3_Test::insStart(){
    Item<int> * item1 = new Item<int>(1);
    Item<int> * item2 = new Item<int>(2);
    Item<int> * item3 = new Item<int>(3);
    Liste<int> list = Liste<int>();
    list.ins(item1);


    QCOMPARE(item1->getNext(),nullptr);
    QCOMPARE(item1->getPrevios(),nullptr);
    QCOMPARE(list.getFirst(),item1);
    QCOMPARE(list.getCurrent(),item1);
    QCOMPARE(list.getLast(),item1);
}

void Praktikum3_Test::insMiddle(){
    Item<int> * item1 = new Item<int>(1);
    Item<int> * item2 = new Item<int>(2);
    Item<int> * item3 = new Item<int>(3);
    Liste<int> list = Liste<int>();
    list.ins(item1);
    list.ins(item2);
    list.ins(item3);
//    list.print();



    QCOMPARE(item2,item1->getNext());
    QCOMPARE(item2,item3->getPrevios());
    QCOMPARE(item2->getNext(),item3);
    QCOMPARE(item2->getPrevios(),item1);
    QCOMPARE(list.getFirst(),item1);
    QCOMPARE(list.getCurrent(),item3);
    QCOMPARE(list.getLast(),item3);


}
void Praktikum3_Test::insEnd(){
    Liste<int> list = Liste<int>();
    Item<int> * item1 = new Item<int>(1);
    Item<int> * item2 = new Item<int>(2);
    Item<int> * item3 = new Item<int>(3);
    list.ins(item1);
    list.ins(item2);
    list.ins(item3);

    QCOMPARE(item3,item2->getNext());
    QCOMPARE(item3->getPrevios(),item2);
    QCOMPARE(item3->getNext(),nullptr);
    QCOMPARE(list.getFirst(),item1);
    QCOMPARE(list.getCurrent(),item3);
    QCOMPARE(list.getLast(),item3);
}
void Praktikum3_Test::delStart(){
    Liste<int> list = Liste<int>();
    Item<int> * item1 = new Item<int>(1);
    Item<int> * item2 = new Item<int>(2);
    list.ins(item1);
    list.ins(item2);
    list.reset();
    list.del();

    QCOMPARE(item2->getPrevios(),nullptr);
    QCOMPARE(list.getFirst(),item2);
    QCOMPARE(list.getCurrent(),item2);
    QCOMPARE(list.getLast(),item2);


}
void Praktikum3_Test::delMiddle(){
    Liste<int> list = Liste<int>();
    Item<int> * item1 = new Item<int>(1);
    Item<int> * item2 = new Item<int>(2);
    Item<int> * item3 = new Item<int>(3);
    list.ins(item1);
    list.ins(item2);
    list.ins(item3);
    list.reset();
    list.adv();
    list.del();

    QCOMPARE(item1->getNext(),item3);
    QCOMPARE(item3->getPrevios(),item1);
    QCOMPARE(list.getFirst(),item1);
    QCOMPARE(list.getCurrent(),item1);
    QCOMPARE(list.getLast(),item3);

}
void Praktikum3_Test::delEnd(){
    Liste<int> list = Liste<int>();
    Item<int> * item1 = new Item<int>(1);
    Item<int> * item2 = new Item<int>(2);
    Item<int> * item3 = new Item<int>(3);
    list.ins(item1);
    list.ins(item2);
    list.ins(item3);
    list.del();

    QCOMPARE(item2->getNext(),nullptr);
    QCOMPARE(list.getFirst(),item1);
    QCOMPARE(list.getCurrent(),item1);
    QCOMPARE(list.getLast(),item2);
}

QTEST_APPLESS_MAIN(Praktikum3_Test)

#include "tst_praktikum3_test.moc"
