#include<bits/stdc++.h>

using namespace std;

template<class T>
class Queue
{
private:
    T * arr;
    int sz, arr_cap, l, r;

    void increaseCapp()
    {
        T * temp = new T[arr_cap*2];
        if( l > r)
        {
            int index = 0;
            for(int i = l; i < arr_cap; i++)
            {
                temp[index] = arr[i];
                index++;
            }

            for(int i = 0; i <= r; i++)
            {
                temp[index] = arr[i];
                index++;
            }
            l = 0;
            r = index -1;
        }
        else
        {
            for(int i = 0; i < arr_cap; i++)
                temp[i] = arr[i];

        }
        arr_cap *= 2;
        swap(arr, temp);
        delete []temp;

    }

public:
    Queue()
    {
        arr = new T[1];
        arr_cap = 1;
        sz = 0;
        l = 0;
        r = -1;
    }

    void enqueue(T data)
    {
        if(sz == arr_cap)
        {
            increaseCapp();
        }
        r++;
        if(r >= arr_cap)
            r = 0;

        arr[r] = data;
        sz++;
    }

    void dequeue()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        l++;
        if(l >= arr_cap)
            l = 0;
        sz--;
    }

    T front()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            return T();
        }
        return arr[l];
    }
};

int main()
{
    Queue<double> q;
    q.enqueue(10.10);
    q.enqueue(5.50);
    q.enqueue(5.20);
    q.dequeue();
    q.dequeue();
    cout<<"Front element "<<q.front()<<"\n";
    q.enqueue(20.10);
    q.enqueue(50.50);
    q.enqueue(50.20);
    q.dequeue();
    q.dequeue();
    cout<<"Front element "<<q.front()<<"\n";
    return 0;
}
