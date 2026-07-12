#include <stdio.h>
#include <stdlib.h>

void swap1(int p, int q){
    int r ;
    printf ("p = %d, q = %d. &p = %p, &q = %p \n", p, q, &p, &q) ;
    
    r = p ;
    p = q ;
    q = r ;
    
    printf ("p = %d, q = %d. &p = %p, &q = %p \n", p, q, &p, &q) ;
} ;

void swap2(int *p, int *q){
    int r ;
    printf ("*p = %d, *q = %d. p = %p, q = %p \n", *p, *q, p, q) ;
    printf ("&p = %p, &q = %p\n", &p, &q) ;

    r = *p ;
    *p = *q ;
    *q = r ;
    
    printf ("*p = %d, *q = %d. p = %p, q = %p \n", *p, *q, p, q) ;
} ;

int main(){
    int a = 10, b = 20 ;
    printf ("a = %d, b = %d. &a = %p, &b = %p \n\n", a, b, &a, &b) ;
    
    swap1 (a, b);
    printf ("a = %d, b = %d. &a = %p, &b = %p \n\n", a, b, &a, &b) ;
    
    swap2 (&a, &b);
    printf ("a = %d, b = %d. &a = %p, &b = %p \n", a, b, &a, &b) ;
    
    return 0;
}