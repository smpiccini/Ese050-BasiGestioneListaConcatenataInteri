#include <stdio.h>
#include <stdlib.h>

struct s_elemento{
    int v;
    struct s_elemento* next;
};
typedef struct s_elemento elemento;

void SvuotaLista(elemento *primo);

int main(int argc, char** argv) {
    elemento *primo=NULL;
    elemento *nuovoElemento;
    elemento *scorri;
    char a;
    
    do {
        nuovoElemento=(elemento*)malloc(sizeof(elemento));
        if (nuovoElemento==NULL){
            fprintf(stderr, "Errore nell'allocazione di mememoria.");
            exit(1);
        }
        printf("Inserisci un numero: ");
        scanf("%d", &(nuovoElemento->v));
        nuovoElemento->next=primo;
        primo=nuovoElemento;
        
        printf("Vuoi Inserire un altro numero? (s/n): ");
        scanf("\n%c", &a);
    }while(a=='s');
    
    printf("In ordine inverso, i numeri inseriti sono:\n");
    scorri=primo;
    while(scorri!=NULL){
        printf("%d\n", scorri->v);
        scorri=scorri->next;
    }
    SvuotaLista(primo);
    return (EXIT_SUCCESS);
}

void SvuotaLista(elemento *primo){
    elemento *temp;
    while(primo!=NULL){
        temp=primo->next;
        free(primo);
        primo=temp;
    }
}