#include <stdio.h>
#include <stdlib.h>

struct s_element {
    int value;
    struct s_element *next;
};

typedef struct s_element element;

element * addElement(element *first, int value);
void printList(element *first);
void emptyList(element *first);

int main(int argc, char** argv) {
    element * first;
    int value;
    
    first = NULL; // lista vuota
    value = 1;
    while(value != 0) {
        printf("Quale numero vuoi aggiungere? 0 per terminare ");
        scanf("%d", &value);
        if(value != 0) {
            first = addElement(first, value);
            if(first == NULL) {
                fprintf(stderr, "Impossibile allocare la memoria richiesta");
                exit(1);
            }
        }
    }
    
    printList(first);
    
    emptyList(first);
    
    return (EXIT_SUCCESS);
}

element * addElement(element *first, int value) {
    element * newElement;
    newElement = (element *)malloc(sizeof(element));
    if(newElement != NULL) {
        newElement->value = value;
        newElement->next = first;
    }
    first = newElement; // non indispensabile: solo per chiarezza
    return first;
}

void printList(element *first) {
    printf("\nStampa della lista\n");

    /* Avrei potuto impiegare direttamente first.
     * Infatti il passaggio dei parametri ad una funzione è per valore:
     * il parametro formale first è una copia del parametro attuale.
     * 
     * Per chiarezza viene, comunque, usato un puntatore per scorrere gli elementi
     * della lista.
     */
    element *current;
    current = first;
    while(current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
    return;
}

void emptyList(element *first) {
    printf("\nSvuotamento della lista in corso... ");
    element *temp;
    while(first != NULL) {
        temp = first;
        first = first->next;
        free(temp);
    }
    printf("completato\n");
    return;
}
