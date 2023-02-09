#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};

class Linked_list
{
    public:
    Node * head;
    int sz;
    Linked_list()
    {
        head = NULL;
        sz = 0;
    }

    Node * createNewNode(int data)
    {
        Node * newNode = new Node;
        newNode->next = NULL;
        newNode->data = data;
        return newNode;
    }

    void insertAtLast(int data)
    {
        Node * newNode = createNewNode(data);

        if(head == NULL)
        {
            head = newNode;
            sz++;
            return;
        }

        Node * node = head;

        while(node->next != NULL)
            node = node->next;

        node->next = newNode;
        sz++;
    }

    void insertAtHead(int data)
    {
        Node *newNode = createNewNode(data);
        newNode->next = head;
        head = newNode;
        sz++;
        return;
    }

    void insertAnyindex(int data, int index)
    {
        if(index < 0 || index > sz)
            return;
        if(index == 0)
        {
            insertAtHead(data);
            return;
        }
        Node *newNode = createNewNode(data);
        int cur_index = 0;
        Node * node = head;

        while(node != NULL)
        {
            if(index -1 == cur_index)
                break;

            cur_index++;
            node = node->next;
        }
        newNode->next = node->next;
        node->next = newNode;
        sz++;
        return;
    }

    void printList()
    {
        Node * node = head;

        if(sz == 0)
            return;

        while(node != NULL)
        {
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<"\n";
    }

    int getSize()
    {
        return sz;
    }
};

int main()
{
    Linked_list l;
    l.insertAtLast(5);
    l.insertAtLast(7);
    l.insertAtLast(10);
    l.insertAtHead(20);
    l.insertAtHead(30);
    l.insertAnyindex(100, 0);
    l.insertAnyindex(90, 1);
    l.printList();
    cout<<l.getSize();

    return 0;
}
