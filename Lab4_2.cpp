#include <iostream>
using namespace std;

struct TListItem{
    int value;
    TListItem *next, *prev;
};
struct TList{
    TListItem *first, *last;
};

TList initList(){
    TList t;
    t.first=NULL;
    t.last=NULL;
    return t;
}

void addListItem(TList& list, int val){
    if(list.first==NULL){
        list.first=new TListItem;
        list.first->value=val;
        list.last=list.first;
        list.first->next=list.last;
        list.first->prev=list.last;
        list.last=list.first;
    }
    else{
        TListItem* newItem = new TListItem;
        newItem->value=val;
        newItem->next=list.first;
        newItem->prev=list.last;
        list.last->next=newItem;
        list.last=list.last->next;
        list.first->prev=list.last;
    }
}

void printList(TList list){
    TListItem* temp=list.first;
    while(temp!=list.last){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<list.last->value<<"\n";
}

void destroyList(TList& list){
    TListItem* itemToDelete = list.first, *tmp;
    while(itemToDelete!=list.last){
        tmp=itemToDelete->next;
        delete itemToDelete;
        itemToDelete=tmp;
    }
    delete list.last;
    list.first=NULL;
    list.last=NULL;
}

int product(TList list){
    int result=1;
    TListItem* temp=list.first;
    while(temp!=list.last){
        result*=temp->value;
        temp=temp->next;
    }
    result*=list.last->value;
    return result;
}

int main()
{
    TList list=initList();
    int n;
    cout<<"Введіть кількість елементів: ";
    cin>>n;
    cout<<"Введіть елементи:\n";
    int num;
    for(int i=0; i<n; i++){
        cout<<i+1<<"-й: ";
        cin>>num;
        addListItem(list, num);
    }
    cout<<"\nДобуток елементів = "<<product(list)<<"\n";
    printList(list);
    destroyList(list);
    printList(list);
    return 0;
}



