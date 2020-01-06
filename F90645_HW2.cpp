//Created by Lyboslav Blagoev
//on 04.01.2020
//for CITB308 Homework #2

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

//using namespace std;

template <typename E>
class VectorCompleteTree
{
    private:
        std::vector<E> V; //Tree contents
    public:
        typedef typename std::vector<E>::iterator Position;
    protected:
        Position pos(int i){return V.begin() + i;}

        int idx(const Position& p) const {return p - V.begin();}
    public:
        VectorCompleteTree() : V(1) {} //Constructor
        int size() const                         { return V.size() - 1; }
        Position left(const Position& p)         { return pos(2*idx(p)); }
        Position right(const Position& p)        { return pos(2*idx(p)+1); }
        Position parent(const Position& p)       { return pos(idx(p)/2); }
        bool hasLeft (const Position& p) const   { return 2*idx(p) <= size(); }
        bool hasRight (const Position& p) const  { return 2*idx(p) + 1 <= size(); }
        bool isRoot (const Position& p) const    { return idx(p) == 1; }
        Position root()                          { return pos(1); }
        Position last()                          { return pos(size()); }
        void addLast(const E& e)                 { V.push_back(e); }
        void removeLast()                        { V.pop_back(); }
        void swap (const Position& p, const Position& q)
        {
            E e = *q;
            *q = *p;
            *p = e;
        }
        void preorder(const Position& p, int i);
};

//Comparator
template <class T>
class LexCompare
{
    public:
        int operator () (const T& p1, const T& p2) const
        {
            return p1 < p2;
        }
};

template <class E, template<class> class C>
class HeapPriorityQueue
{
    public:
        int size() const;
        bool empty() const;
        void insert (const E& e);
        const E& min();
        void removeMin();
    private:
        //Shortcut for tree position
        typedef typename VectorCompleteTree<E>::Position Position;
        VectorCompleteTree<E> T; //Priority queue contents
        C<E> isLess; //Less-than comparator
        void show(Position p, int loc); // Show the values in the heap
    public:
        void print();
};

//Returning the size of the structure
template <class E, template<class> class C>
int HeapPriorityQueue<E,C>::size() const
{
    return T.size();
}

//Boolean to check if the structure is empty
template <class E, template<class> class C>
bool HeapPriorityQueue<E,C>::empty() const
{
    return size() == 0;
}

//Inserting a new element in the back of the structure by calling a member-function
template <class E, template<class> class C>
void HeapPriorityQueue<E,C>::insert(const E& e)
{
    T.addLast(e); //Add element to the heap
    Position v = T.last(); //Get e's position

    //Up-heap bubbling
    while(!T.isRoot(v))
    {
        Position u = T.parent(v);
        if(!isLess(*v,*u)) break; //if v in order
        T.swap(v,u); //swap with parent
        v = u;
    }
}

//Get smallest element
template <class E, template<class> class C>
const E& HeapPriorityQueue<E,C>::min()
{
    return *(T.root());
}

 // Show the values in the heap
template <class E, template<class> class C>
void HeapPriorityQueue<E,C>::show(Position p, int loc)
{
    loc += 2;
    std::cout<<std::setw(loc)<<*p<<std::endl;

    //Check for left child
    if(T.hasLeft(p))
    {
        Position leftChild = T.left(p); //Get left child
        show(leftChild, loc); //Recursive traversal of left subtree
        std::cout<<"\n";
    }

    //Check for right child
    if(T.hasRight(p))
    {
        Position rightChild = T.right(p); //Get right child
        show(rightChild, loc); //Recursive traversal of right subtree
    }
}

// Print Queue
template <class E, template<class> class C>
void HeapPriorityQueue<E,C>::print()
{
    int loc = 8; // To format the output

    Position p = T.root(); // Root position
    std::cout<<"Root: "<< *p <<std::endl; // Show root

    Position leftChild = T.left(p); //Get root left child
    show(leftChild, loc); // Travers the left subtree
    std::cout<<"\n";

    Position rightChild = T.right(p); //Get root right child
    show(rightChild, loc); // Travers the right subtree
}


template <class E, template<class> class C>
void HeapPriorityQueue<E,C>::removeMin()
{
    if(size() == 1) T.removeLast();
    else
    {
        Position u = T.root();
        T.swap(u, T.last()); //Swap last with root
        T.removeLast();

        while (T.hasLeft(u))
        {
            //Down-heap bubbling
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)),*v))
            {
                v = T.right(u); // v is u's smaller child
            }


            //Is u out of order?
            if(isLess(*v,*u))
            {
                T.swap(u,v);
                u = v;
            }
            else break;
        }
    }
}

template <typename E>
void VectorCompleteTree<E>::preorder(const Position& p, int i)
{

    if (idx(p) > size()) return;
    /* first print data of node */
    std::cout << std::setw(i) << *p << std::endl;
    /* then recur on left sutree */
    preorder(left(p), i+3);
    /* now recur on right subtree */
    preorder(right(p), i+3);
}


int main()
{

    //Creating two structures to store the numbers
    HeapPriorityQueue<int, LexCompare> hPQ1;
    HeapPriorityQueue<int, LexCompare> hPQ2;


    //Getting a size from the user and
    // inserting the contents of the two heaps
    int n;
    int entree;
    std::cout<<"Enter a number of elements to be inserted : ";
    std::cin>>n;

    while(n>0)
    {
     std::cin>>entree;
     hPQ1.insert(entree);
     hPQ2.insert(entree);
     n--;
    }

    //hPQ1.print();

    //Getting a number from the user and finding
    //the smallest element with that number as an index
    int kth;
    std::cout<<"Enter k-th : ";
    std::cin>>kth;

    for(int k=1;k<kth;k++)
    {
        hPQ1.removeMin();
    }


    //Declaring a string variable to store the symbols
    std::string num;
    //Switch case to find out the correct
    // symbols for the number (st,nd,rd,th)
    switch(kth)
    {
    case 1:
        num = "st";
        break;
    case 2:
        num = "nd";
        break;
    case 3:
        num = "rd";
        break;
    default:
        num = "th";
    }

    //Creating a variable to use for the
    //next calculations and printing the result
    double kth_smal=hPQ1.min();
    std::cout<<"The "<<kth<<num<<" smallest element is : "<<hPQ1.min()<<std::endl;



    //Getting a number from the user and finding
    //the largest element with that number as an index
    int lth;
    std::cout<<"Enter lth : ";
    std::cin>>lth;

    //Reversing the method by searching not for the
    // n-th largest, but for the "size-n"-th smalest
    int dif = hPQ2.size() - lth;

    for(int i=0;i<dif;i++)
    {
        hPQ2.removeMin();
    }

    //Creating a variable to use for the
    //next calculations and printing the result
    double lth_larg=hPQ2.min();

    //Switch case to find out the correct
    // symbols for the number (st,nd,rd,th)
    switch(lth)
    {
    case 1:
        num = "st";
        break;
    case 2:
        num = "nd";
        break;
    case 3:
        num = "rd";
        break;
    default:
        num = "th";
    }


    std::cout<<"The "<<lth<<num<<" largest element is : "<<hPQ2.min()<<std::endl;

    //Using the two variables we declared previously
    // to find the sum and the average
    std::cout<<"The sum of the two elements is : "<<kth_smal+lth_larg<<std::endl;
    std::cout<<"The average ot the two elements is : "<<(kth_smal+lth_larg)/2;



    return 0;

}
