#include<bits/stdc++.h>

using namespace std;

class MaxHeap
{
public:
    vector<int>nodes;
    MaxHeap()
    {

    }

    void upHeapify(int idx)
    {
        while(idx > 0 && nodes[idx] > nodes[(idx-1)/ 2])
        {
            swap(nodes[idx], nodes[(idx-1) / 2]);
            idx = (idx-1) /2;
        }
    }

    void downHeapify(int idx)
    {
        while(1)
        {
            int largest = idx;
            int left = (idx *2) + 1;
            int right = (idx * 2) + 2;
            if(left < nodes.size() && nodes[left] > nodes[largest])
            {
                largest = left;
            }
            if(right < nodes.size() && nodes[right] > nodes[largest])
            {
                largest = right;
            }
            if(largest == idx)
                break;
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }

    void insert(int val)
    {
        nodes.push_back(val);
        upHeapify(nodes.size()-1);
    }

    void Delete(int idx)
    {
        if(idx >= nodes.size())
        {
            cout<<"Index not found\n";
            return;
        }
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        downHeapify(idx);
    }

    int getMax()
    {
        if(nodes.empty())
        {
            cout<<"Heap is empty\n";
            return -1;
        }
        return nodes[0];
    }

    int ExtractMax()
    {
        if(nodes.empty())
        {
            cout<<"Index not found\n";
            return -1;
        }
        int val = nodes[0];
        Delete(0);
        return val;
    }

    void printHeap()
    {
         if(nodes.empty())
        {
            cout<<"Heap is empty\n";
            return;
        }
        for(int i = 0; i< nodes.size(); i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    MaxHeap mh;
    mh.insert(4);
    mh.insert(7);
    mh.insert(9);
    mh.insert(1);
    mh.insert(10);
    mh.insert(20);
    mh.insert(30);
    cout<<"Max element ="<<mh.getMax()<<"\n";
    cout<<"Max element ="<<mh.ExtractMax()<<"\n";
    cout<<"Max element ="<<mh.ExtractMax()<<"\n";
    mh.printHeap();
    return 0;
}
