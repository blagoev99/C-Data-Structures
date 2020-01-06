#include <iostream>
using namespace std;


void balance_parentheses();

const int NUM=1000;
template<typename O>
class ArrayStack {
private:
    int n;
    O* arr;
    int t;

public:
    ArrayStack(int cap=NUM)
    {
        n=cap;
        arr=new O[n];
        t=-1;
    }

    ArrayStack(const ArrayStack& st);
    ArrayStack& operator=(const ArrayStack& st);

    ~ArrayStack()
    {
        delete []arr;
    }

    void push(const O& obj)
    {
     if(size()==n)
     {
         cout<<"Stack overflow"<<endl;
         return;
     }
     t++;
     arr[t]=obj;
    }

    O pop()
    {
        if(isEmpty())
        {
            cout<<"Access to empty stack"<<endl;
            return 1;
        }
        return arr[t--];
    }

    O& top() const
    {
        return arr[t];
    }

    bool isEmpty() const
    {
        return (t<0);
    }


    int size() const
    {
        return (t+1);
    }

    void print()
    {
        while(!isEmpty())
        {
            cout<<top();
            pop();
        }
        cout<<endl;
    }
};


template<typename O>
ArrayStack<O>::ArrayStack(const ArrayStack& st)
{
    n=st.n;
    t=st.t;
    arr=new O[n];


    for(int i=0;i<=t;i++)
    {
       arr[i]=st.arr[i];
    }
}

template<typename O>
ArrayStack<O>& ArrayStack<O>::operator=(const ArrayStack& st)
{
    if(this != &st)
    {
       delete []arr;
       n=st.n;
       t=st.t;
       arr=new O[n];


    for(int i=0;i<=t;i++)
    {
        arr[i]=st.arr[i];
    }
}
return *this;
}


/*

int main()
{

    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    cout<<A.top()<<endl;
    A.pop();



    return 0;
}

*/

int main()
{
    int t;
    cout << "Enter number of test cases:";
    cin >> t;

    for (int i = 0; i < t; i++) {
        //calling of function for checking of brackets
        balance_parentheses();
    }

    return 0;
}

void balance_parentheses()
{
    ArrayStack<char> a;
    string s;
    cout << "Enter string may or may not containing parentheses:";
    cin >> s;

    int flag = 0; //flag is an arbitrary variable

    for (int i = 0; i < s.length(); i++)
    //for length of the string calculated by number of letters
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            //push function to enter terms in a stack
            a.push(s[i]);
            flag = 1;
        }
        if (!a.isEmpty()) {
            if (s[i] == '}') {
                if (a.top() == '{')
                // top of the stack
                {
                    a.pop();
                    //pop function to delete terms from the top of array
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ']') {
                if (a.top() == '[') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ')') {
                if (a.top() == '(') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }

    if ((a.isEmpty()) && (flag == 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
