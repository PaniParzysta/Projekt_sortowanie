#include "mergesort.h"

void scalanie(int tab[], int p, int q, int r){

    int *tab_pom = new int [r-p+1];
    int i=p,j=q+1;
    int k=0;

    while (i<=q && j<=r){	//jesli oba przedzialy sie nie skonczyly to porownywane sa kolejne elementy i mniejszy element jest wpisywany do tablicy pomocniczej

        if (tab[i]<=tab[j]){

           tab_pom[k]=tab[i];
            i++;
        }

        else{

            tab_pom[k]=tab[j];
            j++;
        }
        k++;
    }

    while (i<=q){			//jesli 1 przedzial sie nie skonczyl to pozostale elementy sa wpisywane do tablicy pomocniczej

        tab_pom[k]=tab[i];
        i++;
        k++;
    }

    while (j<=r){			//jesli 2 przedzial sie nie skonczyl to pozostale elementy sa wpisywane do tablicy pomocniczej

        tab_pom[k]=tab[j];
        j++;
        k++;
    }

    for(int i=p;i<=r;i++){	//nadpisanie tablicy orginalnej pomocnicza

        tab[i]=tab_pom[i-p];
    }
    delete [] tab_pom;
}

void mergesort(int tab[], int p, int r){

    if (p<r){

        int	srodek=p+(r-p)/2;
        mergesort(tab,p,srodek); 		    //wywolanie dla 1 przedzialu
        mergesort(tab,srodek+1,r);		    //wywolanie dla 2 przedzialu
        scalanie(tab,p,srodek,r);			//wywolanie funkci scalajacej oba przedzialy
    }
    return;
}
