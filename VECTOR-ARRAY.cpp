#include <iostream>


class vectorClass {

    // vec_array is the integer pointer
    // which stores the address of our vector
    int* vec_array;

    // capacity is the total storage
    // capacity of the vector
    int capacity;

    int cur_index;

public:
// Default constructor
    vectorClass();
// Function to add an element at the last
    void Push(int number);
// Function to delete the last element
    void Pop();
// function to get size of the vector
    int Size();
//function to insert a certain element at a certain position in the array
    void PushAtIndex(int data, int index);
//function to return the element which is found on a certain position
    int ReturnAtIndex(int index);
//Function to check if the array is empty or not
    bool isEmpty();
// function to print vec_array elements
    void Print();

//Function to remove a chosen item from the array
    bool RemoveItem(int num);
};

int main()
{
  int n, k;

std::cout << "Please enter a number: ";
std::cin >> n;

std::cout << "Please enter a number larger than 3: ";
std::cin >> k;

  while(k<3)
  {
      std::cout<< "WRONG INPUT!Enter a number larger than 3: ";
      std::cin>> k;
  }

  int currentElement = n;
  vectorClass row;
  row.Push(n);
  for (int index = 0; row.Size() < k; index++)
  {
    if (index % 3 == 0)
    {
      currentElement = row.ReturnAtIndex(int(index / 3 ));
    }
    else if (index % 3 == 1)
    {
      row.Push(currentElement + 1);
    }
    else if(index%3 == 2)
    {
      row.Push(currentElement * 2);
    }
  }
  row.Print();


  if(row.isEmpty()){std::cout<<"EMPTY"<<std::endl;
  }else std::cout<<"NOT EMPTY"<<std::endl;

int rem;
std::cout<<"Enter an index to remove: ";
std::cin>>rem;

  if (row.RemoveItem(rem))
  {
    std::cout << "The item is removed" << std::endl;
  }
    row.Print();
  return 0;
}

/// /// /// /// /// /// /// ///
///IMPLEMENTATION OF FUNCTIONS///
/// /// /// /// /// /// /// ///

/////////////////////////////////////
vectorClass::vectorClass()        //
{                                //
        vec_array = new int[1]; //
        capacity = 1;          //
        cur_index = 0;        //
};                           //
//////////////////////////////


/////////////////////////////////////////////////////////
void vectorClass::Push(int number)                    //
{                                                    //
//If the number of elements is equal to the         //
//capacity we double the size of the structure     //
    if (cur_index == capacity)                    //
    {                                            //
    int* temp = new int[ 2 * capacity];         //
                                               //
// Copying contents to the new array          //
    for (int i = 0; i < capacity; i++)       //
    {                                       //
        temp[i]=vec_array[i];              //
    }                                     //
                                         //
// Deleting the old array               //
    delete[] vec_array;                //
    capacity *= 2;                    //
    vec_array = temp;                //
    }                               //
                                   //
// Inserting new element          //
  vec_array[cur_index] = number; //
  cur_index++;                  //
                               //
};                            //
///////////////////////////////



////////////////////////////
void vectorClass::Pop()  //
{                       //
    cur_index--;       //
};                    //
///////////////////////


///////////////////////////
int vectorClass::Size() //
{                      //
    return cur_index; //
};                   //
//////////////////////


/////////////////////////////////////////////////////
void vectorClass::PushAtIndex(int data, int index)//
{                                                //
    if (index == capacity){Push(data);}         //
    else{vec_array[index] = data;}             //
};                                            //
///////////////////////////////////////////////


//////////////////////////////////////////////////////////
int vectorClass::ReturnAtIndex(int index)              //
{                                                     //
    if (index < cur_index){return vec_array[index];} //
    else{std::invalid_argument("Incorrect index");} //
  return -1;                                       //
}                                                 //
///////////////////////////////////////////////////


////////////////////////////////////
bool vectorClass::isEmpty()      //
{                               //
    if(cur_index==0) return 1; //
    else return 0;            //
}                            //
//////////////////////////////


//////////////////////////////////////////////
void vectorClass::Print()                  //
{                                         //
   std::cout<<"THE VECTOR IS: ";             //
    for (int i = 0; i < cur_index; i++) //
        {                              //
       std::cout << vec_array[i] << " ";  //
        }                            //
        std::cout <<std::endl << std::endl;       //
}                                  //
////////////////////////////////////


//////////////////////////////////////////////////////////////////
bool vectorClass::RemoveItem(int num)                          //
{                                                             //
    if(num < cur_index)                                      //
                                                            //
    {                                                      //
    for(int index = num; index + 1 < cur_index; index++)  //
        {                                                //
        vec_array[index] = vec_array[index+1];          //
        }                                              //
        cur_index--;                                  //
        return true;                                 //
    }                                               //
    return false;                                  //
}                                                 //
///////////////////////////////////////////////////
