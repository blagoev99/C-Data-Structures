#include <iostream>

using namespace std;


template <typename T>
class NodeList {
    private:
        struct Node {
            T elem; // Element value
            Node* prev; // Previous element
            Node* next; // Next element
        };
    public:
        class Iterator {
            public:
                // Reference to the element
                T& operator*()
                { return v->elem; }

                // Comparison operations
                bool operator==(const Iterator& p) const
                { return v == p.v; }
                bool operator!=(const Iterator& p) const
                { return v != p.v; }

                // Next position
                Iterator& operator++()
                {
                    v = v->next;
                    return *this;
                }

                // Previous position
                Iterator& operator--()
                {
                    v = v->prev; return *this;
                }
                // Previous position

                //friend class NodeList; // Give NodeList access
            public:
                Node* v; // Pointer to the node

                // Constructor from Node*
                Iterator(Node* u)
                { v = u; }
        };
    public:
        NodeList(); // Constructor
        NodeList(const NodeList& nl); // Copy constructor
        ~NodeList(); // Destructor
        NodeList& operator=(const NodeList& p); // Operator Assignment

        int size() const
        { return n; }

        bool empty() const
        { return (n == 0); }

         // Begin position is first item
        Iterator begin() const
        { return Iterator(header->next); }

        // End position is just beyond last
        Iterator end() const
        { return Iterator(trailer); }

        // Insert element before p
        void insert(const Iterator& p, const T& e);
        // Insert at front
        void insertFront(const T& e)
        { insert(begin(), e); }
        // Insert at rear
        void insertBack(const T& e)
        { insert(end(), e); }

        // Remove element
        void erase(const Iterator& p);
        // Remove first
        void eraseFront()
        { erase(begin()); }
        // Remove last
        void eraseBack()
        { erase(--end()); }

        void print();

    private: // data members
        int n; // number of items
        Node* header; // Head-of-list sentinel
        Node* trailer; // Tail-of-list sentinel
};

// Constructor
template <typename T>
NodeList<T>::NodeList()
{
    n = 0;

    // Create sentinels
    header = new Node;
    trailer = new Node;

    // Have them point to each other
    header->next = trailer;
    trailer->prev = header;
}

// Copy constructor (class NodeList)
template <typename T>
NodeList<T>::NodeList(const NodeList& nl)
{
    int index = 0;
    n = 0;

    // Create sentinels
     header = new Node;
     trailer = new Node;

    // Have them point to each other
     header->next = trailer;
     trailer->prev = header;

    Iterator itTemp = Iterator(nl.begin());

    while(index < nl.size())
    {
        Node* nd = itTemp.v;
        insertBack(nd->elem);
        ++itTemp;
        index++;
    }
}

// Destructor
template <typename T>
NodeList<T>::~NodeList()
{
    int index=0;
    Iterator itTemp = Iterator(begin());
    while(index<size())
    {
        Node* nd = itTemp.v;
        delete &nd;
        index++;
        ++itTemp;
    }

    delete &n;
    delete &header;
    delete &trailer;
}

// Operator Assignment
template <typename T>
NodeList<T>& NodeList<T>::operator=(const NodeList<T>& nl)
 {
    if (this != &nl)
    {
        n = nl.size();

        // Sentinels nodes - header
        Iterator itTemp = Iterator(nl.begin());
        --itTemp;
        header = itTemp.v;

        // Sentinels nodes - trailer
        itTemp = Iterator(nl.end());
        trailer = itTemp.v;
    }
 }

// Insert e before p
template <typename T>
void NodeList<T>::insert(const NodeList<T>::Iterator& p, const T& e)
{
    Node* w = p.v; // p’s node
    Node* u = w->prev; // p’s predecessor

    Node* v = new Node; // New node to insert
    v->elem = e;
    v->next = w; w->prev = v; // Link in v before w
    v->prev = u; u->next = v; // Link in v after u
    n++;
}

// Remove p
template <typename T>
void NodeList<T>::erase(const Iterator& p)
{
    Node* v = p.v; // Node to remove
    Node* w = v->next; // Successor
    Node* u = v->prev; // Predecessor
    u->next = w; w->prev = u; // Unlink p
    delete v;
    n--;
}

template <typename T>
void NodeList<T>::print()
{
    int index = 0;
    Iterator item = begin();

    while(index < size())
    {
        Node* nd = item.v;
        cout << nd->elem << " ";
        ++item;
        index++;
    }

    cout << endl;
}

int main()
{
    NodeList<int>* list1 = new NodeList<int>();
    list1->insertFront(1); // Position 0
    list1->insertFront(2); // Position 1
    list1->insertFront(3); // Position 2

    cout<<"The list size: "<<list1->size()<<endl;
    cout<<"List elements: ";
    list1->print();
    cout<<"\n";


    NodeList<int>::Iterator item = list1->begin(); // Return position 0
    ++item; // position 1
    ++item; // position 2
    list1->insert(item, 4);
    cout<<"The new list size: "<<list1->size()<<endl;
    cout<<"List elements: ";
    list1->print();
    cout<<"\n";

    NodeList<int>* list2 = new NodeList<int>(*list1);
    cout<<"Copy list size: "<< list2->size()<<endl;
    cout<<"Copy list: ";
    list2->print();
    cout<<"\n";

    return 0;
}
