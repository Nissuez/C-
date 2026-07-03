#include <stdlib.h>
#include <stdio.h>

int main(){
    int *p , a = 10 ;
    
    p = &a ;

    printf ("a的地址是%p，值是%d\n", &a, a) ;
    printf ("p存放的地址是%p，值是%d， 自己的地址是%p\n", p, *p, &p) ;
    
    return 0 ;
}