#include "pomocnicze_introsort.h"

void wstaw(int tab[],int p,int r){

    r++;
    int i=p;
    int w;

    while (i<r){

        int j=i;

        while (j>0 && tab[j - 1] > tab[j]){

            w=tab[j];
            tab[j]=tab[j-1];
            tab[j-1]=w;
            --j;
        }
        ++i;
    }
}

void kopcowanie (int tab[],int rozmiar, int wartosc){

    int max=wartosc;
    int pom;
    int l=2*wartosc+1;
    int p=2*wartosc+2;

    if (l<rozmiar && tab[l]>tab[max]){		//szukanie najwiekszego elementu w 1 czeci tablicy

        max=l;
    }

    if (p<rozmiar && tab[p]>tab[max]){		//szukanie najwiekszego elementu w 2 czeci tablicy

        max=p;
    }

    if (max!=wartosc){						//jesli najwieksza wartosc nie jest rowna wartosci elementu dzielacego, zamien te 2 wartooci i wykonaj ponownie kopcowanie

        pom=tab[wartosc];
        tab[wartosc]=tab[max];
        tab[max]=pom;
        kopcowanie(tab,rozmiar,max);
    }
}

void heapsort(int tab[],int p,int r){

    ++r;
    int liczba_pom;
    int *tab_pom=new int [r-p];

    for (int i=0;i<r-p;i++){

        tab_pom[i]=tab[i+p];
    }

    for (int i=(r-p)/2-1;i>=0;--i){

        kopcowanie(tab_pom,r-p,i);
    }

    for (int i=(r-p)-1;i>=0;--i){

        liczba_pom=tab_pom[0];
        tab_pom[0]=tab_pom[i];
        tab_pom[i]=liczba_pom;
        kopcowanie(tab_pom,i,0);
    }

    for (int i=0;i<r-p;i++){

        tab[i+p]=tab_pom[i];			//nadpisywanie tablicy orginalnej tablica pomocnicza
    }
    delete [] tab_pom;
}
