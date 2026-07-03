#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Maxsize 50

typedef struct SqList{
    int data[Maxsize] ;
    int length ;
}SqList ;

void InitList(SqList *L){
    L->length = 0 ;
} ;

bool InsertList(SqList *L, int i, int e){
    if(i > (L->length+1) || i <= 0){
        printf("插入元素不合法\n") ;
        return false ;
    }     //判断预插入位置是否合法    
    if(L->length >= Maxsize){            //判断数组是否已满
        printf("顺序表已经满了\n") ;
        return false ;
    }
    
    for(int j = (L->length) - 1; j > i-1; j--)      //移动预插入位置后的元素
        L->data[j+1] = L->data[j] ;
    L->data[i-1] = e ;                  //插入元素e

    L->length++ ;                       //更新顺序表长度
    return true ;
} ;

bool DeleteList(SqList *L, int i){
    if(i <= 0 || i > (L->length)){
        printf("输入值不合法\n") ;
        return false;
    }                                   // 判断想要删除的这个位置是否合法

    int e = L->data[i-1] ;              // 给出想要删除的这个位置对应的值

    for(int j=i; j<L->length; j++)
        L->data[j-1] = L->data[j];      // 删除这个位置的值
    L->length--;                        // 更新表长
    return true;
} ;

int LocateElem(SqList *L, int e){
    for(int i=1; i <= L->length; i++){
        if(L->data[i-1] == e)
            return i-1 ;
    }
    return 0 ;
} ;

int main(){
    SqList L ;
    InitList(&L) ;          //初始化顺序表L
    
    int i ;
    for(i = 1; i <= Maxsize; i++){
        InsertList(&L, i, i-1) ;
        printf("顺序表的第%d个元素的值为%d。 \n", i, L.data[i-1]);
    }                           // 按顺序插入元素直至插满
    InsertList(&L, i, i-1);     // test1
    InsertList(&L, 0, 1234);    // test2

    if (DeleteList(&L, 3))
        printf("删除成功 \n\n");            //判断是否删除成功
    else
        printf("所以删除失败\n\n");
    for(i = 1; i <= L.length; i++){
        printf("顺序表的第%d个元素的值为%d。 \n", i, L.data[i-1]);
    }                                      // 打印删除后的新表

//查找是否存在值为e的元素
    int e = 10;
    int ElemNumber = LocateElem(&L, e);
    if(ElemNumber != 0)
        printf("等于e的元素在顺序表的第%d个", ElemNumber);

    return 0 ;
}