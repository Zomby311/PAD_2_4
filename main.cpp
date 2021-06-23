#include <iostream>
#include <time.h>
#include <ctime>

#include "Liste.h"

using namespace std;

int main() {


    Item<int> *item1 = new Item<int>(5);
    Item<int> *item2 = new Item<int>(64);
    Item<int> *item3 = new Item<int>(12);
    Item<int> *item4 = new Item<int>(35);
    Item<int> *item5 = new Item<int>(11);
    Item<int> *item6 = new Item<int>(20);
    Item<int> *item7 = new Item<int>(23);



    Liste<int> liste1 = Liste<int>();
    Liste<int> liste2 = Liste<int>();


    liste1.ins(item1);
    liste1.ins(item2);
    liste1.ins(item3);
    liste1.ins(item4);
    liste1.ins(item5);
    liste1.ins(item6);
    liste1.ins(item7);

    liste1.heapSort();








//    time_t quickstart = time(nullptr);
//    for (int i = 0; i < 1000; i++) {
//        int random = rand() % 10000;
//        liste2.ins(new Item<int>(random));
//    }
//    liste2.quickSort(liste2.getFirst(), liste2.getLast());;
//    time_t quickend = time(nullptr);
//    cout << "Quickstart :" << ctime(&quickstart) << endl;
//    cout << "Quickend : " << ctime(&quickend) << endl;
//
//
//
//
//    time_t mergetart = time(nullptr);
//    for(int i = 0;i<10000;i++){
//        int random = rand()%100000;
//        liste2.ins(new Item<int>(random));
//    }
//    liste2.mergeSort();
//    time_t mergeend = time(nullptr);
//    cout << "Mergestart :" <<  ctime(&mergetart) << endl;
//    cout << "Mergeende : " <<  ctime(&mergeend) << endl;
//
//    time_t heapstart = time(nullptr);
//    for(int i = 0;i<1000;i++){
//        int random = rand()%100000;
//        liste2.ins(new Item<int>(random));
//    }
//    liste2.heapSort();
//    time_t heapend = time(nullptr);
//    cout << "Heapstart : " <<  ctime(&heapstart) << endl;
//    cout <<"Heapend : " <<ctime(&heapend) << endl;































//    int input;
//    bool run = true;
//
//    while (run) {
//        cout << "Bitte waehlen sie eine Option." << endl;
//        cout << "0 - Beenden" << endl;
//        cout << "1 - Aktuelle Element" << endl;
//        cout << "2 - Check ob Liste leer ist." << endl;
//        cout << "3 - Check ob Zeiger am Ende ist." << endl;
//        cout << "4 - Zeiger vorruecken." << endl;
//        cout << "5 - Zeiger auf Anfang setzten" << endl;
//        cout << "6 - Item hinzufuegen." << endl;
//        cout << "7 - Element am Zeiger loeschen." << endl;
//        cout << "8 - Liste ausgeben" << endl;
//
//        try {
//            cin >> input;
//            if(!cin.good()) {
//                throw invalid_argument("Fehlerhafte Eingabe");
//            }
//        } catch (invalid_argument &e) {
//
//        }
//
//        switch (input) {
//            case 0:
//                run = false;
//                break;
//            case 1:
//                liste.get()->print();
//                break;
//            case 2:
//                if (liste.empty()) {
//                    cout << "Liste ist leer." << endl;
//                } else {
//                    cout << "Liste ist nicht leer." << endl;
//                }
//                break;
//            case 3:
//                if (liste.end()) {
//                    cout << "Zeiger ist am Ende" << endl;
//                } else {
//                    cout << "Zeiger ist nicht am Ende" << endl;
//                }
//                break;
//            case 4:
//                liste.adv();
//                cout << "Zeiger wurde um eine Stelle nach vorne gerueckt." << endl;
//                break;
//            case 5:
//                liste.reset();
//                cout << "Zeiger ist wieder am Anfang." << endl;
//                break;
//            case 6:
//                int eingabe;
//                cout << "Bitte eine Info eingeben." << endl;
//                cin >> eingabe;
//                liste.ins(new Item<int>(eingabe));
//                break;
//            case 7:
//                cout << "Element am Zeiger wurde geloescht" << endl;
//                liste.del();
//                break;
//            case 8:
//                liste.print();
//                break;
//            default:
//                cout << "Falsche Eingabe." << endl;
//        }
//    }
    return 0;
}
