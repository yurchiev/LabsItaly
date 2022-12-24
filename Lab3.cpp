#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct TQueueItem
{
    string value;
    TQueueItem *next;
};

struct TQueue
{ 
    TQueueItem *head;
    TQueueItem *tail;
};

TQueue initQueue()
{ 
    TQueue q; 
    q.head=NULL;
    q.tail=NULL;
    return q;
}

int isEmpty(const TQueue&q)
{
    return q.head == NULL;
}

void enQueue(TQueue &q, string value)
{ 
    if(isEmpty(q))
    {
        q.head = new TQueueItem();
        q.head->value=value;
        q.head->next=NULL;
        q.tail=q.head;
    }else
    { 
        q.tail->next = new TQueueItem();
        q.tail->next->value = value;
        q.tail->next->next = NULL;
        q.tail = q.tail->next;
    }
}

string deQueue (TQueue &q)
{ 
    if(isEmpty(q))
        return 0;
    else
    { 
        string result = q.head->value;
        TQueueItem *item=q.head;
        q.head=q.head->next;
        delete item;
        if(q.head==NULL) q.tail=q.head;
        return result;
    }
}


int main( )
{
    TQueue q;
    q=initQueue();
    int n;
    string x;
    cout<<"Введіть кількість слів: ";
    cin>>n;
    while(n){
        cin >> x;
        enQueue (q,x);
        n--;
    }
    string max = deQueue(q), tmp;
    while(!isEmpty(q)){
        tmp = deQueue(q);
        if (tmp.length() > max.length())
            max = tmp;
    }
    cout<<endl<<max;
    
    return 0;
}


