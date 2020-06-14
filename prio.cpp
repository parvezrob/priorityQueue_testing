#include <iostream>
#include <cmath>
using namespace std;

 struct Data{

     double key;
     double x;
     double y;

};


class PriorityQueue{
  Data heaparray[100];
  int Size;

    public:
    PriorityQueue()
    {
        Size=0;
    }
    void Heapify(int index)
    {
    int largest = index;
    int left = 2*index;
    int right = 2*index + 1;


    if (left <= Size && heaparray[left].key < heaparray[index].key)
       {
        largest= left;
       }

    if (right <= Size && heaparray[right].key < heaparray[largest].key)
       {
       largest = right;
       }

    if (largest != index)
    {
        swap(heaparray[index].key, heaparray[largest].key);
        swap(heaparray[index].x, heaparray[largest].x);
        swap(heaparray[index].y, heaparray[largest].y);
        Heapify(largest);
    }
}
    void MaxHeapify()
    {
        int i;
        for(i = Size/2; i >= 1; i--)
        {
            Heapify(i);
        }
    }

    void Insert(double x, double y)
    {
        Size++;
        heaparray[Size].key=-100;
        double item = sqrt(x*x + y*y);
        ChangeKey(Size-1,item,x,y);

    }

    void ChangeKey(int i,double newKey, double x, double y)
    {
        heaparray[i+1].key=newKey;
        heaparray[i+1].x=x;
        heaparray[i+1].y=y;
        MaxHeapify();
    }


    void Print()
    {
        for(int i=1;i<=Size;i++)
        {
            cout<<"[ "<<heaparray[i].x<<","<<heaparray[i].y<<","<<heaparray[i].key<<"]"<<endl;
        }
    }


};


int main()
{
    PriorityQueue p;

    p.Insert(2,3);
    p.Insert(9,0);
    p.Print();
    cout<<"-----"<<endl;
    
    p.Insert(1,0);
    p.Print();
    cout<<"-----"<<endl;

return 0;
}
