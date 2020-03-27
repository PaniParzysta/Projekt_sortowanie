#include <iostream>
#include "tablica.h"
#include "quicksort.h"
#include "mergesort.h"
#include "introsort.h"
#include <cstdlib>
#include <ctime>
#include <chrono>

int main() {

    using namespace std;

    int dlugosc[5]={10000, 50000, 100000, 500000, 1000000};			            // ilosc elementow w tablicy
    double procent[8]={0.00, 0.25, 0.50, 0.75, 0.95, 0.99, 0.997, 1.00};	    // ile % tablicy jest juz posortowane

    int indeks_p=0;					    // indeks pierwszego elementu
    int suma1=0;						// suma wszystkich czasow dla 100 tablic dla introsort
    int suma2=0;						// suma wszystkich czasow dla 100 tablic dla quicksort
    int suma3=0;						// suma wszystkich czasow dla 100 tablic dla mergesort
    double srednia1;					// sredni czas dzialania introsort
    double srednia2;					// sredni czas dzialania quicksort
    double srednia3;					// sredni czas dzialania mergesort

    for(int i=0; i<8; ++i) {
        double ilosc_procent=procent[i];        //petla wybierajaca procent
        if(ilosc_procent==1) {
            cout<<"Tablica odwrotnie posortowana: "<<endl;
            cout<<endl;
        }
        else {
            cout<<"Jaki procent posortowania wstepnego: "<< procent[i]<<endl;
            cout<<endl;
        }

        for(int j=0; j<5; ++j) {
           int jaka_dlugosc=dlugosc[j];                                        //petla wybierajaca rozmiar tablicy
           int indeks_o=dlugosc[j]-1;			                               // indeks ostatniego elementu

           cout<<"Dlugosc tablicy: "<<dlugosc[j]<<endl;

            for (int k=0; k<100; ++k) {                                        //petla tworzaca i sortujaca 100 tablic

                int *tablica = stworz_tablice(jaka_dlugosc, ilosc_procent);
                int *tab_1 = new int [jaka_dlugosc];
                int *tab_2 = new int [jaka_dlugosc];

                for(int m=0; m<jaka_dlugosc; ++m){

                    tab_1[m]=(int)tablica[m];               //stworzenie dwoch kopii do przekazania
                    tab_2[m]=(int)tablica[m];
                }

                auto czas_przed1 = chrono::high_resolution_clock::now();                                        //czas przed algorytmem
                introsort(tablica, indeks_p, indeks_o);                                                         //sortowanie tablicy
                auto czas_po1 = chrono::high_resolution_clock::now();                                           //czas po algorytmie
                auto roznica1 = chrono::duration_cast<chrono::microseconds>(czas_po1 - czas_przed1).count();    //czas w jakim wykonuje się algorytm
                suma1 += roznica1;

                auto czas_przed2 = chrono::high_resolution_clock::now();
                quicksort(tab_1, indeks_p, indeks_o);
                auto czas_po2 = chrono::high_resolution_clock::now();
                auto roznica2 = chrono::duration_cast<chrono::microseconds>(czas_po2 - czas_przed2).count();
                suma2 += roznica2;

                auto czas_przed3 = chrono::high_resolution_clock::now();
                mergesort(tab_2, indeks_p, indeks_o);
                auto czas_po3 = chrono::high_resolution_clock::now();
                auto roznica3 = chrono::duration_cast<chrono::microseconds>(czas_po3 - czas_przed3).count();
                suma3 += roznica3;

                delete [] tab_1;            //usuwanie miejsca w pamieci dla tablic dynamicznych
                delete [] tab_2;
                delete [] tablica;
            }

            srednia1=suma1/100;             //obliczenie sredniego czasu dzialania poszczegolnego algorytmu
            srednia2=suma2/100;
            srednia3=suma3/100;
            cout<<"Srednia introsort: "<<srednia1/1000000<<" s"<<endl;
            cout<<"Srednia quicksort: "<<srednia2/1000000<<" s"<<endl;
            cout<<"Srednia mergesort: "<<srednia3/1000000<<" s"<<endl;
            cout<<endl;
        }
    }

    return 0;
}