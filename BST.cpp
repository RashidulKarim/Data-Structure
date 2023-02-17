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

    void Delete(T value)
    {
        Node * cur = root;
        Node * prev = NULL;

        while(cur != NULL)
        {
            if(value > cur->value)
            {
                prev = cur;
                cur = cur->right;
            }
            else if(value < cur->value)
            {
                prev = cur;
                cur = cur->left;
            }
            else
                break;
        }

        if(cur == NULL)
        {
            cout<<"Value is not present BST\n";
            return;
        }

        //case 1: both child is null
        if(cur->left == NULL && cur->right == NULL)
        {
            if(prev->left && prev->left->value == cur->value)
            {
                prev->left = NULL;
            } else {
                prev->right = NULL;
            }
            delete cur;
            return;
        }

        //case 2: one child is null
        if(cur->left != NULL && cur->right == NULL)
        {
            if(prev->left && prev->left->value == cur->value)
                prev->left = cur->left;
            else
                prev->right = cur->left;
            delete cur;
            return;
        }

        if(cur->left == NULL && cur->right != NULL)
        {
            if(prev->left && prev->left->value == cur->value)
                prev->left = cur->right;
            else
                prev->right = cur->right;
            delete cur;
            return;
        }
    }
};

int main()
{
    BST<int> bst;
    bst.insertion(6);
    bst.insertion(4);
    bst.insertion(3);
    bst.insertion(5);
    bst.insertion(7);
    bst.insertion(8);
    bst.Delete(7);
    bst.BFS();
    //cout<<bst.search(2);
    return 0;
}
