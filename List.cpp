#include <iostream>
using namespace std;

typedef int Elem;

class NodeList{
private:
    struct Node
    {
        Elem elem;
        Node* prev;
        Node* next;
    };
public:
    class Iterator{
    public:
       Elem& operator*();
       bool operator==(const Iterator& p) const;
       bool operator!=(const Iterator& p) const;
       Iterator& operator++();
       Iterator& operator--();
       friend class NodeList;
    private:
        Node* v;
        Iterator(Node* u);
    };
public:
    NodeList();
    int size()const{ return n; }
    bool empty(); const
    Iterator begin()const{ return Iterator(header->next); }
    Iterator end()const{ return Iterator(trailer); }

    void insert(const Iterator& p, const Elem& e)
    {
    Node* w = p.v;
    Node* u = w->prev;

    Node* v = new Node;
    v->elem = e;
    v->next = w;
    w->prev = v;
    v->prev = u;
    u->next = v;
    n++;
    }

    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void eraseFront();
    void eraseBack();
    void print();
    void erase(const Iterator& p);

private:
    int n;
    Node* header;
    Node* trailer;
};

NodeList::NodeList()
{
    n = 0;

    // Create sentinels
    header = new Node;
    trailer = new Node;

    // Have them point to each other
    header->next = trailer;
    trailer->prev = header;
}



NodeList::Iterator::Iterator(Node* u)
{
    v = u;
}

Elem& NodeList::Iterator::operator*()
{
    return v->elem;
}

bool NodeList::Iterator::operator==(const Iterator& p) const
{
    return v == p.v;
}

bool NodeList::Iterator::operator!=(const Iterator& p) const
{
    return v != p.v;
}

NodeList::Iterator& NodeList::Iterator::operator++()
{
    v = v->next;
    return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--()
{
    v = v->prev;
    return *this;
}

/*
void NodeList::insert(const NodeList::Iterator& p, const Elem& e)
{
    Node* w = p.v;
    Node* u = w->prev;

    Node* v = new Node;
    v->elem = e;
    v->next = w;
    w->prev = v;
    v->prev = u;
    u->next = v;
    n++;
}

*/

void NodeList::insertFront(const Elem& e)
{
    insert(begin(), e);
}

void NodeList::insertBack(const Elem& e)
{
    insert(end(), e);
}

void NodeList::erase(const Iterator& p)
{
    Node* v = p.v;
    Node* w = v->next;
    Node* u = v->prev;
    u->next = w;
    w->prev = u;
    delete v;
    n--;
}

void NodeList::eraseFront()
{
    erase(begin());
}

void NodeList::eraseBack()
{
    erase(end());
}

void NodeList::print()
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
    NodeList list1;

    list1.insertFront(4);
    list1.print();





    return 0;
}
