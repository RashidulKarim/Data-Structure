#include<bits/stdc++.h>

using namespace std;

template<class T>
class BinaryTree
{
    class Node
    {
    public:
        T data;
        int id;
        Node * parent;
        Node * left;
        Node  * right;
    };


    Node * createNode(T value, int id)
    {
        Node * newNode = new Node;
        newNode->data = value;
        newNode->id = id;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
        return newNode;
    }

public:
    Node * root;
    int counter;

    BinaryTree()
    {
        root = NULL;
        counter = 0;
    }

    void Insertion(T value, int id)
    {
        Node* newNode = createNode(value, id);

        if(root == NULL)
        {
            root = newNode;
            counter++;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node * a = q.front();
            q.pop();

            if(a->left != NULL)
            {
                q.push(a->left);
            }
            else
            {
                newNode->parent = a;
                a->left = newNode;
                counter++;

                return;
            }

            if(a->right != NULL)
            {
                q.push(a->right);
            }
            else
            {
                newNode->parent = a;
                a->right = newNode;
                counter++;

                return;
            }
        }
    }

    void Search(T value)
    {
        if(root == NULL)
        {
            cout<<"Binary tree is empty";
            return;
        }

        queue<Node*>q;
        q.push(root);
        int flag = 0;
        while(!q.empty())
        {
            Node* a = q.front();
            q.pop();
            if(a->data == value)
            {
                cout<<"Found Value "<<value<<" on id "<<a->id<<"\n";
                flag++;
            }

            if(a->left != NULL)
            {
                q.push(a->left);
            }

            if(a->right != NULL)
            {
                q.push(a->right);
            }
        }
        if(flag == 0)
            cout<<"value "<< value<<" is not fount on the tree";
    }

    void BFS()
    {
        if(root == NULL)
        {
            cout<<"Binary tree is empty";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node * a = q.front();
            q.pop();
            int l = -1, r = -1, p = -1;
            if(a->left != NULL)
            {
                q.push(a->left);
                l = a->left->id;
            }
            if(a->right != NULL)
            {
                q.push(a->right);
                r = a->right->id;
            }
            if(a->parent != NULL)
                p = a->parent->id;
            cout<<"Node Id = "<<a->id<<" left child = "<<l <<" Right child "<<r<<" parent id = "<<p<<"\n";
        }
    }

    void preOrder(Node * root)
    {
        if(root == NULL)
            return;

        cout<<root->id<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node * root)
    {
        if(root == NULL)
            return;

        inOrder(root->left);
        cout<<root->id<<" ";
        inOrder(root->right);
    }

    void postOrder(Node * root)
    {
        if(root == NULL)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout<<root->id<<" ";
    }

    int height(Node * root)
    {
        if(root == NULL)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }

    bool isPerfact()
    {
        int currentHeight = height(root);
        if(pow(2,currentHeight) -1 == counter)
            return true;
        return false;
    }

    bool isComplete()
    {
        if(root == NULL)
        {
            cout<<"tree is empty";
            return true;
        }
        queue<Node*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty())
        {
            Node * a = q.front();
            q.pop();

            if(flag && (a->right || a->left))
                return false;

            if(a->left == NULL && a->right)
                return false;

            if(a->left)
                q.push(a->left);
            else
                flag = true;

            if(a->right)
                q.push(a->right);
            else
                flag = true;
        }
        return true;
    }

};

int main()
{
    BinaryTree<int> b;
    b.Insertion(10, 1);
    b.Insertion(20, 2);
    b.Insertion(30, 3);
    b.Insertion(40, 4);
    b.Insertion(50, 5);
    b.Insertion(60, 6);
    b.Insertion(70, 7);
    b.BFS();

    b.preOrder(b.root);
    cout<<"\n";
    b.inOrder(b.root);
    cout<<"\n";
    b.postOrder(b.root);
    cout<<"\n";
    //cout<<b.height(b.root);
    if(b.isComplete())
        cout<<"Binary tree is complete\n";
    else
        cout<<"Binary tree is not complete\n";

    if(b.isPerfact())
        cout<<"Binary tree is perfect\n";
    else
        cout<<"Binary tree is not perfect\n";
    return 0;
}
