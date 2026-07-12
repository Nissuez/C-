#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode{
    int data ;
    struct LNode *next ;
} *LinkList, LNode ;

/*
bool InitLinkList(LinkList L){
    L = NULL ;
};
*/
bool InitLinkList(LinkList L){
    L = (LNode*) malloc(sizeof(LNode)) ;
    L->next = NULL ;
    return true ;
} ;

bool InsertNextNode(LNode *p, int e){
    if(p!=NULL){
    LNode *s = (LNode*) malloc(sizeof(LNode)) ;
    s->next = p->next ;
    s->data = e ;
    p->next = s ;
    return true ;
    }

    else return false ;
}

bool InsertPriorNode(LNode *p, int e){
    if (p==NULL)
        return false ;
    
    LNode *s = (LNode*) malloc(sizeof(LNode)) ;
    s->data = p->data ;
    s->next = p->next ;
    p->data = e ;
    p->next = s ;
    return true ;
}

bool ListInsert(LinkList L, int i, int e){
    if (i<1)
        return false ;
    
    LNode *p ;
    p = L ;
    int j = 0 ;
    while (p!=NULL && j<i-1){
        p = p->next ;
        j++ ;
    }
    if(p == NULL)
        return false ;

    return InsertNextNode(p,e) ;
} ;

bool ListDelete(LinkList *L, int i, int *e){
    if(i<1)
        return false ;

    LNode *p ;
    p = L ;
    int j = 0 ;
    while (p!=NULL && j<i-1){
        p = p->next ;
        j++ ;
    }
    if(p->next == NULL)
        return false ;

    LNode *s = p->next ;            
    e = s->data ;       //将删除的元素值传回main函数   
    p->next = s->next ;
    return true ;
} ;

int main(){
    LinkList L ;
    InitLinkList(L) ;
    return 0 ;
}