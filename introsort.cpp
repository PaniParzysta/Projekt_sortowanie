#include <math.h>
#include "introsort.h"
#include "quicksort.h"
#include "pomocnicze_introsort.h"

void introsort_czesc_druga (int tab[],int p, int r, int g){

    int rozmiar=r-p+1;

    if(rozmiar<=16){		//dla tablic o rozmiarze <16 sortowanie przez wstawianie

        wstaw(tab,p,r);
    }

    else if(g==0){			//maksymalna liczbe rekurencji - heapsort

        heapsort(tab,p,r);
    }

    else{					//dalszy podzial tablic

        int os=podzial_tabeli(tab,p,r);
        introsort_czesc_druga(tab,p,os,--g);
        introsort_czesc_druga(tab,os+1,r,--g);
    }
}

void introsort(int tab[], int p, int r){

    int glebokosc=(int)log(r-p+1)*2;
    introsort_czesc_druga(tab,p,r,glebokosc);
}
