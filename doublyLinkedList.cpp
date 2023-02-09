#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    Node * prev;
    int data;
    Node * next;
};


class Doubly_Linked_list
{
    public:
    Node * head;
    int sz;

    Doubly_Linked_list()
    {
        head = NULL;
        sz = 0;
    }

    Node * createNode(int data)
    {
        Node * newNode = new Node;
        newNode->prev = NULL;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void insertAtHead(int data)
    {
        Node * newNode = createNode(data);

        if(head == NULL)
            head = newNode;
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        sz++;
        return;
    }

    int getsize()
    {
        return sz;
    }

    void Traverse()
    {
        Node * node = head;

        while(node != NULL)
        {
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<"\n";
    }

    void insertAtAnyPosition(int data, int position)
    {
        if(position > sz)
            return;

        if(position == 0)
        {
            insertAtHead(data);
            return;
        }

        Node * newNode = createNode(data);
        int indx = 0;
        Node * node = head;

        while(position - 1 != indx)
        {
            node = node->next;
            indx++;
        }

        newNode->prev = node;
        newNode->next = node->next;
        node->next->prev = newNode;
        node->next = newNode;
        sz++;
        return;

    }

    void deleteNode(int index)
    {
        if(index < 0 || sz <= index)
            return;

        Node * node = head;
        int current_index = 0;

        while(current_index < index)
        {
            node = node->next;
            current_index++;
        }

        Node * prevNode = node->prev;
        Node * nextNode = node->next;
        if(prevNode != NULL)
            prevNode->next = nextNode;

        if(nextNode != NULL)
            nextNode->prev = prevNode;

        if(index == 0)
            head = nextNode;
        sz--;
        delete node;
        return;
    }

    void reverseList()
    {
        if(head == NULL)
            return;

        Node * a =head;
        int current_index = 0;
        while(current_index != sz-1)
        {
            current_index++;
            a = a->next;
        }

        Node * node = head;
        while(node != NULL)
        {
            swap(node->next, node->prev);
            node = node->prev;
        }
        head = a;
    }

};


int main()
{
    Doubly_Linked_list dl;
    dl.insertAtHead(10);
    dl.insertAtHead(20);
    dl.insertAtHead(30);
    dl.insertAtAnyPosition(100, 0);
    dl.insertAtAnyPosition(120, 0);
    dl.insertAtAnyPosition(150, 0);
    dl.insertAtAnyPosition(130, 1);
    dl.insertAtAnyPosition(50, 1);
    dl.insertAtAnyPosition(50, 5);
    dl.Traverse();
    dl.deleteNode(3);
    dl.deleteNode(3);
    dl.Traverse();
    dl.reverseList();
    dl.Traverse();
    cout<<dl.getsize()<<"\n";
    return 0;
}
