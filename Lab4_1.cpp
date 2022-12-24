#include <iostream>
#include <string>
using namespace std;

struct TListItem{
    string value;
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

void addListItem(TList& list, string val){
    if(list.first==NULL){
        list.first=new TListItem;
        list.first->value=val;
        list.first->next=NULL;
        list.first->prev=NULL;
        list.last=list.first;
    }
    else{
        TListItem* newItem = new TListItem;
        newItem->value=val;
        newItem->next=NULL;
        newItem->prev=list.last;
        list.last->next=newItem;
        list.last=list.last->next;
    }
}

void printList(TList list){
    TListItem* tmp=list.first;
    int count=1;
    while(tmp!=NULL){
        cout<<count<<". "<<tmp->value<<"\n";
        tmp=tmp->next;
        count++;
    }
}

void destroyList(TList& list){
    TListItem* itemToDelete = list.first, *tmp;
    while(itemToDelete!=NULL){
        tmp=itemToDelete->next;
        delete itemToDelete;
        itemToDelete=tmp;
    }
    list.first=NULL;
    list.last=NULL;
}

string maxEl(TList list){
    string max=list.first->value;
    TListItem *temp=list.first;
    while(temp!=NULL){
        if(temp->value.length()>max.length()){
            max=temp->value;
        }
        temp=temp->next;
    }
    return max;
}

string minEl(TList list){
    string min=list.first->value;
    TListItem *temp=list.first;
    while(temp!=NULL){
        if(temp->value.length()<min.length()){
            min=temp->value;
        }
        temp=temp->next;
    }
    return min;
}

int main()
{
    TList list=initList();
    int n;
    string str;
    
    cout<<"Введіть кількість речень: ";
    cin>>n;
    
    getline(cin, str);
    for(int i=0; i<n; i++){
        getline(cin, str);
        addListItem(list, str);
    }
    
    cout<<"Найдовше речення: "<<maxEl(list)<<"\nНайкоротше речення: "<<minEl(list);
    
    cout<<"\nСписок речень: \n";
    printList(list);
    destroyList(list);
    printList(list);
    return 0;
}




