#include<bits/stdc++.h>

using namespace std;

class MyCircularDeque 
{
public:
    typedef struct Node
    {
        int val;
        struct Node* front;
        struct Node* next;
    }Node , *PNode;

public:
    int size=0;
    int limit=0;
    PNode H , T;
    int i=0;

public:
    MyCircularDeque(int k) 
    {
        limit = k;
        size=0;
    }
    
    bool insertFront(int value) 
    {
        if(isFull())
        {
            return false;
        }
        else
        {
            if(i++==0)
            {
                H = new Node;
                H->front = NULL;
                H->next = NULL;
                H->val = value;
                T = H;
            }
            else
            {
                PNode P = new Node;
                P->next = NULL;
                P->front = NULL;
                P->val = value;
                H->front = P;
                P->next = H;
                H = H->front;
            }
            size++;
            return true;
        }
    }
    
    bool insertLast(int value) 
    {
        if(isFull())
        {
            return false;
        }
        else
        {
            if(i++==0)
            {
                H = new Node;
                H->front = NULL;
                H->next = NULL;
                H->val = value;
                T = H;
            }
            else
            {
                PNode P = new Node;
                P->next = NULL;
                P->front = NULL;
                P->val = value;
                T->next = P;
                P->front = T;
                T = T->next;
            }
            size++;
            return true;
        }
    }
    
    bool deleteFront() 
    {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            H = H->next;
            delete H->front;
            H->front = NULL;
            size--;
            return true;
        }
        
    }
    
    bool deleteLast() 
    {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            T = T->front;
            delete T->next;
            T->next = NULL;
            size--;
            return true;
        }
    }
    
    int getFront() 
    {
        return H->val;
    }
    
    int getRear() 
    {
        return T->val;
    }
    
    bool isEmpty() 
    {
        return size == 0;
    }   
    
    bool isFull() 
    {
        return size == limit;
    }
};

int main()
{
    MyCircularDeque S;
    S.insertFront(8);


    return 0;
}