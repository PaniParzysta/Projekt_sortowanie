#include "tablica.h"
#include "cstdlib"

//tworzy tablice dynamiczną i zwraca ja do main
int* stworz_tablice(int rozmiar, double ile_procent){

    int *tablica = new int [rozmiar];		        //tworzenie tablicy o zadanym rozmiarze

    if(ile_procent==1){                             //wypelnienie tablicy liczbami calkowitymi w kolenosci malejacej (odwrotnie posortowana)
        for(int i=0; i<rozmiar; ++i)
           tablica[i]=rozmiar - i;
        return tablica;
    }

    if(ile_procent!=1) {
        for (int i = 0; i < ile_procent * rozmiar; ++i) {        //procentowe zapelnianie tablicy

            tablica[i] = i;
        }

        for (int i = ile_procent * rozmiar; i < rozmiar; ++i) {  //zapelnienie tablicy losowymi elementami

            tablica[i] = rand() % 1000000 + ile_procent * rozmiar;
        }
        return tablica;
    }
return tablica;
}

