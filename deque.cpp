#include<bits/stdc++.h>

using namespace std;

template<class T>
class Deque
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    int sz, isReverse;

    Node* createNode(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }

    void pushAtHead(T data)
    {
        Node* newNode = createNode(data);
        if(sz == 0)
        {
            head = newNode;
            tail = newNode;
            sz++;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        sz++;
        return;
    }

    void pushAtBack(T data)
    {
        Node * newNode = createNode(data);
        if(sz == 0)
        {
            head = newNode;
            tail = newNode;
            sz++;
            return;
        }
        newNode->prev =tail;
        tail->next = newNode;
        tail = newNode;
        sz++;
        return;
    }

    void removeFromBack()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return;
        }

        if(sz == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }

        Node* lastNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete lastNode;
        sz--;
    }

    void removeFromHead()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return;
        }

        if(sz == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        Node* firstNode = head;
        head = head->next;
        head->prev = NULL;
        sz--;
        delete firstNode;
    }

    public:
    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        isReverse = 0;
    }

    void reverse()
    {
        if(isReverse)
            isReverse = 0;
        else
            isReverse = 1;
    }

    void push_front(T data)
    {
        if(isReverse)
            pushAtBack(data);
        else
            pushAtHead(data);
    }

    void push_back(T data)
    {
        if(isReverse)
            pushAtHead(data);
        else
            pushAtBack(data);
    }

    void pop_back()
    {
        if(isReverse)
            removeFromHead();
        else
            removeFromBack();
    }

    void pop_front()
    {
        if(isReverse)
            removeFromBack();
        else
            removeFromHead();
    }

    T front()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }

        if(isReverse)
            return tail->data;
        else
            return head->data;
    }

    T back()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        if(isReverse)
            return head->data;
        else
            return tail->data;
    }
    int size()
    {
        return sz;
    }

    T max()
    {
        Node* temp = head->next;
        if(sz == 0)
            return -1;
        T maxx = head->data;

        while(temp != NULL)
        {
            if(temp->data > maxx)
                maxx = temp->data;
            temp = temp->next;
        }
        return maxx;
    }

    T min()
    {
        Node* temp = head->next;
        if(sz == 0)
            return -1;
        T min = head->data;

        while(temp != NULL)
        {
            if(temp->data < min)
                min = temp->data;
            temp = temp->next;
        }
        return min;
    }
};


int main()
{
    Deque<double> dq;
    dq.push_front(10.10);
    dq.push_front(5);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(100);
    dq.push_back(40);
    dq.pop_back();
    dq.pop_front();
    dq.push_back(50.50);
    dq.push_front(2.2);
    dq.reverse();
    cout<<"First element "<<dq.front()<<" last element "<<dq.back()<<" size is "<<dq.size()<<" Max:"<<dq.max()<<" Min:" <<dq.min();

    return 0;
}
