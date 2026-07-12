#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initsize 10

typedef struct{
    int *data ;
    int Maxsize, length ;
} SeqList ;

int InitList(SeqList *N){
    N->length = 0 ;
    N->Maxsize = initsize ;
    N->data = (int*) malloc(initsize * sizeof(int));
};

void BiggerList(SeqList *N){
    int *tempData ;
    tempData = N->data ;
    N->Maxsize += initsize ;
    N->data = (int*) malloc( (N->Maxsize) * sizeof(int) ) ;

    for (int i=0; i<(N->Maxsize); i++){
        *(N->data+i) = *(tempData+i) ;
    }

    free (*tempData) ;
}

int main(){
    SeqList L;

    InitList(&L);

    for (int i=0; i<(L.Maxsize); i++){
        *(L.data+i) = i+1 ;
    }

    for (int j=0; j<(L.Maxsize); j++){
        printf(" data[%d] = %d \n", j, *(L.data+j));
    }

    BiggerList(&L);

    printf("%d", L.Maxsize);
    for (int j=0; j<(L.Maxsize); j++){
        printf(" data[%d] = %d \n", j, *(L.data+j));
    }

    return 0 ;
}