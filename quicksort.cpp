#include "quicksort.h"

int podzial_tabeli(int tab[], int p, int r){

    int element_osiowy=tab[(p+r)/2];        //przypisanie wartosci elementu osiowego
    int i=p;
    int j=r;
    int pom;

    while (true){

        while(tab[j]>element_osiowy)
            j--;
        while (tab[i]<element_osiowy)
            i++;
        if (i<j){
            pom=tab[i];
            tab[i]=tab[j];
            tab[j]=pom;
            i++;
            j--;
        }
        else
            return j;
    }
}

void quicksort (int tab[], int p, int r){

    int q;

    if(p<r){                            //indeks pierwszego elementu < indeks ostatniego elementu
        q=podzial_tabeli(tab,p,r);
        quicksort(tab,p,q);
        quicksort(tab,q+1,r);
    }
}

