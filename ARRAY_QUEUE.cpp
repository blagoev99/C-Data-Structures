#include <iostream>
using namespace std;

int const size=1000;
template <typename T>
class Queue{
public:
    Queue();
    ~Queue();
    Queue(Queue const&);
    void InsertElem(T const &);
    int DeleteElem(T &);
    void print();
    Queue& operator=(Queue<T> const &r);
    T front()
    {
        if(isEmpty())
        {
            cout<<"Access to empty queue"<<endl;
            return 1;
        }
        return queueArr[f];
    }

    bool isEmpty() const
    {
        return (n==0);
    }

    int queueSize()const
    {
        return (n);
    }

private:
        int f,rear,n;
        T* queueArr;
        void copyQueue(Queue const &);
};

template<typename T>
Queue<T>::Queue()
{
    queueArr=new T[size];
    n=0;
    f=0;
    rear=0;
}

template<typename T>
Queue<T>::~Queue()
{
    delete [] queueArr;
}

template<typename T>
Queue<T>::Queue(Queue<T> const& r)
{
    copyQueue(r);
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T> const &r)
{
    if(this != &r)
    {
        delete [] queueArr;
        copyQueue(r);
    }
    return *this;
}

template<typename T>
void Queue<T>::InsertElem(T const &x)
{
    if( n == size)
    {
        cout<<"Impossible"<<endl;
    }else
    {
        queueArr[rear]=x;
        n++;
        rear++;
        rear=rear%size;
    }
}

template<typename T>
int Queue<T>::DeleteElem(T &x)
{
    if(n>0)
    {
       x=queueArr[f];
        n--;
        f++;
        f=f%size;
        return 1;
    }
    else return 0;
}

template<typename T>
void Queue<T>::copyQueue(Queue<T> const &r)
{
    queueArr=new T[size];

    for(int i=0;i<size;i++)
    {
        queueArr[i]=r.a[i];
    }

    n=r.n;
    f=r.f;
    rear=r.rear;

}


template<typename T>
void Queue<T>::print()
{
    T x;
    while(DeleteElem(x))
        cout<<x<<"  ";
    cout<<endl;
}

int main()
{
    Queue<int> q;
    for(int i=0;i<=20;i++)
    {
        q.InsertElem(i);
    }

    q.print();
}





