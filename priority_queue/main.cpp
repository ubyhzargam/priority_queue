//Assuming that the entered elements have three levels of priority
//Also assuming that the element with lower numbers have higher priority

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*f1=NULL,*l1=NULL,*f2=NULL,*l2=NULL,*f3=NULL,*l3=NULL;

void enqueue(int x, int prio)
{
    struct Node *p=new Node;
    if(p==NULL)
        cout<<"Memory is full, no more elements can be entered "<<endl;
    else
    {
        p->data=x;
        p->next=NULL;
        switch(prio)
        {
            case 1:
                if(f1==NULL)
                {
                    f1=l1=p;
                }
                else
                {
                    l1->next=p;
                    l1=p;
                }
                break;
            case 2:
                if(f2==NULL)
                {
                    f2=l2=p;
                }
                else
                {
                    l2->next=p;
                    l2=p;
                }
                break;
            case 3:
                if(f3==NULL)
                {
                    f3=l3=p;
                }
                else
                {
                    l3->next=p;
                    l3=p;
                }
                break;
            default:
                p=NULL;
        }
    }
}

int dequeue()
{
    struct Node *p=new Node;
    int x=-1;
    if(f1!=NULL)
    {
        x=f1->data;
        p=f1;
        f1=f1->next;
        free(p);
    }
    else if(f1==NULL&&f2!=NULL)
    {
        x=f2->data;
        p=f2;
        f2=f2->next;
        free(p);
    }
    else if(f1==NULL&&f2==NULL&&f3!=NULL)
    {
        x=f3->data;
        p=f3;
        f3=f3->next;
        free(p);
    }
    else
    {
        cout<<"The queue is empty, there are no elements to be deleted"<<endl;
    }
    free(p);
    return x;
}

void display()
{
    struct Node *p=new Node;
    p=f1;
    if(f1==NULL&&f2==NULL&&f3==NULL)
        cout<<"The queue is empty, there are no elements to be displayed in the queue"<<endl;
    cout<<"The elements with priority 1 are given by : "<<endl;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    p=f2;
    cout<<"The elements with priority 2 are given by : "<<endl;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    p=f3;
    cout<<"The elements with priority 3 are given by : "<<endl;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    free(p);
}

int main()
{
    return 0;
}
