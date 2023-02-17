#include<bits/stdc++.h>

using namespace std;

template<class T>
class BST
{
    class Node
    {
    public:
        T value;
        Node * left;
        Node * right;
    };

    Node * root;
    int counter;
public:
    BST()
    {
        root = NULL;
        counter = 0;
    }

    Node* createNode(T value)
    {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    void insertion(T value)
    {
        Node* newNode = createNode(value);
        if(root == NULL)
        {
            root = newNode;
            counter++;
            return;
        }

        Node* cur = root;
        Node* prev = NULL;

        while(cur != NULL)
        {
            if(cur->value > value)
            {
                prev = cur;
                cur = cur->left;
            }
            else
            {
                prev = cur;
                cur = cur->right;
            }
        }
        if(prev->value > value)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
        counter++;

    }

    void BFS()
    {
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node* a = q.front();
            q.pop();
            int l = -1, r = -1;
            if(a->left != NULL)
            {
                q.push(a->left);
                l = a->left->value;
            }

            if(a->right != NULL)
            {
                q.push(a->right);
                r = a->right->value;
            }
            cout<<"current value is "<<a->value<<" left value is "<<l<<" right value is "<<r<<"\n";
        }
    }

    bool search(T value)
    {
        Node* cur = root;

        while(cur != NULL)
        {
            if(value > cur->value)
            {
                cur = cur->right;
            }
            else if(value < cur->value)
            {
                cur = cur->left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    BST<int> bst;
    bst.insertion(5);
    bst.insertion(4);
    bst.insertion(3);
    bst.insertion(9);
    bst.insertion(8);
    bst.BFS();
    cout<<bst.search(2);
    return 0;
}
