#include <iostream>
#include <string>
using namespace std;

struct TListItem{
    string value;
    TListItem *next{}, *prev{};
};
struct TList{
    TListItem *first, *last;
};

struct TListIterator{
    TListItem* pointer;
};

TList initList(){
    TList t{};
    t.first=nullptr;
    t.last=nullptr;
    return t;
}

void addListItem(TList& list, const string& val){
    if(list.first==nullptr){
        list.first=new TListItem;
        list.first->value=val;
        list.first->next=nullptr;
        list.first->prev=nullptr;
        list.last=list.first;
    }
    else{
        TListItem* newItem = new TListItem;
        newItem->value=val;
        newItem->next=nullptr;
        newItem->prev=list.last;
        list.last->next=newItem;
        list.last=list.last->next;
    }
}

void printList(TList list){
    TListItem* tmp=list.first;
    int count=1;
    while(tmp!=nullptr){
        cout<<count<<". "<<tmp->value<<"\n";
        tmp=tmp->next;
        count++;
    }
}

void destroyList(TList& list){
    TListItem* itemToDelete = list.first, *tmp;
    while(itemToDelete!=nullptr){
        tmp=itemToDelete->next;
        delete itemToDelete;
        itemToDelete=tmp;
    }
    list.first=nullptr;
    list.last=nullptr;
}

TListIterator initListIterator(){
    TListIterator tmp{};
    tmp.pointer=nullptr;
    return tmp;
}

int isValid(TListIterator it){
    return it.pointer!= nullptr;
}

void moveNext(TListIterator &it){
    if(isValid(it))
        it.pointer=it.pointer->next;
}

void movePrev(TListIterator &it){
    if(isValid(it))
        it.pointer=it.pointer->prev;
}

string getValue(const TListIterator &it){
    if(isValid(it))
        return it.pointer->value;
    return "";
}

void setValue(const TListIterator &it, string value){
    if(isValid(it))
        it.pointer->value = value;
}

TListIterator getBegin(TList l){
    TListIterator tmp{};
    tmp.pointer = l.first;
    return tmp;
}

TListIterator getEnd(TList l){
    TListIterator tmp{};
    tmp.pointer = l.last;
    return tmp;
}

string maxEl(TList list){
    TListIterator iterator = getBegin(list);
    string max = getValue(iterator);
    while(isValid(iterator)){
        if(getValue(iterator).length()>max.length()){
            max=getValue(iterator);
        }
        moveNext(iterator);
    }
    return max;
}

string minEl(TList list){
    TListIterator iterator = getBegin(list);
    string min = getValue(iterator);
    while(isValid(iterator)){
        if(getValue(iterator).length()<min.length()){
            min=getValue(iterator);
        }
        moveNext(iterator);
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


