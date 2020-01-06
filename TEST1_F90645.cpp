//Created by Lyuboslav Blagoev
//on 22.11.2019
//F90645

#include <iostream>
#include <string>

const int NUM=1000;

template<typename O>
class ArrayStack {
private:
    int n;
    O* arr;
    int t;

public:
    ArrayStack(); //Default constructor
    ArrayStack(const ArrayStack& st); //Copy constructor
    ArrayStack& operator=(const ArrayStack& st); //Overloaded operator
    ~ArrayStack(); //Destructor


    void push(const O& obj); //Function to put data in the structure

    O pop()          //Function to show the last element
    {
        if(isEmpty())
        {
            std::cout<<"Access to empty stack"<<std::endl;
            return 1;
        }
        return arr[t--];
    }

    O& top() const
    {
        return arr[t];
    }

    bool isEmpty() const //Function to check if the array is empty
    {
        return (t<0);
    }


    int size() const //Function to check the size of the array
    {
        return (t+1);
    }

    void print();  //Function to print all elements

};


template<typename O>
ArrayStack<O>::ArrayStack()
    {
        n=NUM;
        arr=new O[n];
        t=-1;
    }

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
ArrayStack<O>::~ArrayStack()
    {
        delete []arr;
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


template<typename O>
void ArrayStack<O>::push(const O& obj)
    {
     if(size()==n)
     {
         std::cout<<"Stack overflow"<<std::endl;
         return;
     }
     t++;
     arr[t]=obj;
    }

template<typename O>
void ArrayStack<O>::print()  //Function to print all elements
{
    while(!isEmpty())
    {
        std::cout<<top();
        pop();
    }
    std::cout<<std::endl;
}

bool isPair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	else if(opening == '<' && closing == '>') return true;
	return false;
}
bool isCorrect(std::string expression)
{
	ArrayStack<char>  S;
	for(int i =0;i<expression.length();i++)
	{
		if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[' || expression[i] == '<')
			S.push(expression[i]);
		else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']' || expression[i] == '>')
		{
			if(S.isEmpty() || !isPair(S.top(),expression[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.isEmpty() ? true:false;
}

int main()
{
    std::string test;
	std::cout<<"Enter an expression to be checked:  ";

	std::cin>>test;
	if(isCorrect(test))
		std::cout<<"Balanced\n";
	else
		std::cout<<"Not Balanced\n";
}

