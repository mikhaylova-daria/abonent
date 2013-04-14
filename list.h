#ifndef LIST_H
#define LIST_H

#ifndef LIBR_H
    #include "libr.h"
    #define LIBR_H
#endif

using namespace std;

namespace my {
template <typename Type> class List
{
    struct Node
    {
        Node *last;
        Node *next;
        Type key;
    };

    Node* head;
    Node* tail;

public:
    List() {;}
    ~List(){;}
    List* list_new();
    bool list_delete(List*);
    bool push(List*, int );
    bool pop(List*, int&);
    bool unshift(List*, int);
    bool shift(List*, int&);
    bool reverse(List*);
};

template <typename Type>
void List<Type>::output (List<Type> *a)
{
    if (a->head==NULL){
        std:cout<<"empty"<<endl;
        return;
    }
    Node* b=a->head;
    std:cout<<b->key<<endl;
    while (b!=a->tail)
    {
        b=b->next;
        cout<<b->key<<endl;
    }

    return;
}

template <typename Type>
void List<Type>::swap (Node* &a, Node* &b)
{
    Node* w=a;
    a=b;
    b=w;
}

template <typename Type>
List<Type>* List<Type>::list_new()
{
    List<Type>* a=(List<Type>*)malloc(sizeof(List<Type>));
    if (a==NULL) return NULL;
    a->head=NULL;
    a->tail=NULL;
    return a;
}


template <typename Type>
bool List<Type>::list_delete(List<Type>* a)
{
    while (!(a->tail==a->head))
    {
        Node<Type>* b=(a->tail);
        a->tail=b->last;
        free(b);
    }
    if (a->tail!=NULL){
        free(a->head);
    }
    free(a);
    return true;
}


template <typename Type>
bool List<Type>::push(List<Type>* a, Type key)
{
    Node* b=(Node*)malloc(sizeof(Node));
    if (b==NULL) return false;
    if ((a->head)==NULL){//
        b->last=NULL;
        a->head=b;
        a->tail=b;
    }else{		//
        (b->last)=a->tail;
        (a->tail)->next=b;
        (a->tail)=b;
    }
     (b->next)=NULL;
     b->key=key;
     return true;
}


template <typename Type>
bool List<Type>::pop(List<Type>* a, Type &buf)
{
    if (a->head==NULL)
        {
        Type null();
            buf=null;
            std::cerr<<"errer!";
            return false;//
    }
    Node* b=a->tail;
    if(b==a->head){//
        buf=b->key;
        free(b);
        a->head=NULL;
        a->tail=NULL;
    }else{	//
        buf=b->key;
        (b->last)->next=NULL;
        a->tail=(b->last);
        free(b);
    }
    return true;
}


template <typename Type>
bool List<Type>::unshift(List<Type>* a, Type key)
{
    Node* b=(Node*)malloc(sizeof(Node));
    if (b==NULL) return false;
    if ((a->head)==NULL){    //
        b->next=NULL;
        a->head=b;
        a->tail=b;
    }else{			//
        b->next=a->head;
        a->head->last=b;
        a->head=b;

    }
     b->last=NULL;
     b->key=key;
     return true;
}


template <typename Type>
bool List<Type>::shift(List<Type>* a, Type &buf)
{
    if (a->head==NULL) {
        Type null();
        buf = null;
        std::cerr<<"errer!";
        return false;
    }//
    Node* b=a->head;
    if(b==a->tail){//
        buf=b->key;
        free(b);
        a->head=NULL;
        a->tail=NULL;
    }else{	//
        buf=b->key;
        (b->next)->last=NULL;
        a->head=(b->next);
        free(b);
    }
    return true;
}


template <typename Type>
bool List<Type>::reverse(List<Type>* a)
{
    if (a->head==NULL) return true;//
    if (a->head==a->tail) return true;//
    Node<Type>* b=a->head;
    while (b!=a->tail)
    {
        swap(b->last,b->next);
        b=(b->last);
    }
    swap(b->last, b->next);
    swap(a->head,a->tail);
    return true;
}
}
#endif // LIST_H
