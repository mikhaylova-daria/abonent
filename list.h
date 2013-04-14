

#ifndef LIBR_H
    #include "libr.h"
    #define LIBR_H
#endif


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
    bool list_delete();
    bool push(Type);
    bool pop(Type&);
    bool unshift(Type);
    bool shift(Type&);
    bool reverse();
    void output ();

    void swap (Node* &a, Node* &b)
    {
        Node* w=a;
        a=b;
        b=w;
    }

};

template <typename Type>
void List<Type>::output ()
{
    if ((*this)->head==NULL){
        std::cout<<"empty"<<std::endl;
        return;
    }
    Node* b=(*this)->head;
    std::cout<<b->key<<std::endl;
    while (b!=(*this)->tail)
    {
        b=b->next;
        std::cout<<b->key<<std::endl;
    }

    return;
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
bool List<Type>::list_delete()
{
    while (!((*this)->tail==(*this)->head))
    {
        Node* b=((*this)->tail);
        (*this)->tail=b->last;
        free(b);
    }
    if ((*this)->tail!=NULL){
        free((*this)->head);
    }
    free((*this));
    return true;
}


template <typename Type>
bool List<Type>::push(Type key)
{
    Node* b=(Node*)malloc(sizeof(Node));
    if (b==NULL) return false;
    if ((this->head)==NULL){//
        b->last=NULL;
        this->head=b;
        this->tail=b;
    }else{		//
        (b->last)=this->tail;
        (this->tail)->next=b;
        (this->tail)=b;
    }
     (b->next)=NULL;
     b->key=key;
     return true;
}


template <typename Type>
bool List<Type>::pop( Type &buf)
{
    if (this->head==NULL)
        {
        Type null();
            buf=null;
            std::cerr<<"errer!";
            return false;//
    }
    Node* b=this->tail;
    if(b==this->head){//
        buf=b->key;
        free(b);
        this->head=NULL;
        this->tail=NULL;
    }else{	//
        buf=b->key;
        (b->last)->next=NULL;
        this->tail=(b->last);
        free(b);
    }
    return true;
}


template <typename Type>
bool List<Type>::unshift(Type key)
{
    Node* b=(Node*)malloc(sizeof(Node));
    if (b==NULL) return false;
    if ((this->head)==NULL){    //
        b->next=NULL;
        this->head=b;
        this->tail=b;
    }else{			//
        b->next=this->head;
        this->head->last=b;
        this->head=b;

    }
     b->last=NULL;
     b->key=key;
     return true;
}


template <typename Type>
bool List<Type>::shift(Type &buf)
{
    if (this->head==NULL) {
        Type null();
        buf = null;
        std::cerr<<"errer!";
        return false;
    }//
    Node* b=this->head;
    if(b==this->tail){//
        buf=b->key;
        free(b);
        this->head=NULL;
        this->tail=NULL;
    }else{	//
        buf=b->key;
        (b->next)->last=NULL;
        this->head=(b->next);
        free(b);
    }
    return true;
}


template <typename Type>
bool List<Type>::reverse()
{
    if (this->head==NULL) return true;//
    if (this->head==this->tail) return true;//
    Node* b=this->head;
    while (b!=this->tail)
    {
        swap(b->last,b->next);
        b=(b->last);
    }
    swap(b->last, b->next);
    swap(this->head,this->tail);
    return true;
}
}
