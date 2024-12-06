#include<iostream>
#include<limits.h>
using namespace std;

// stack is a fundamental dataStructure
// it is a lifo type of datastructure 
// where element in always inserted at the top and removed from the top
// used in call stack 

// overflow vs underflow condition  
//  when you exceed the capacity of stack and you are still inserting the element this condition is called overflow 
// when your stack is empty and you are still removing the element this condition is called underflow

// how can we implement stacks using array

// we make a class stack with some properties 
// 1.array       in which we insert element 
// 2. top indx   which points to the current topmost indx
// when our top indx is -1 means we are in a underflow condition or not element is added yet or our stack is empty
//  



class stack
{

int capacity ;
int* arr;
int top;

public: 
stack( int c)
{
    this->capacity = c;
    arr = new int[c];
    this->top = -1;
}

void push(int data)
{
    if(this->top == this->capacity-1 )
    {
        cout << "OverFlow" << endl;
        return ;
    }
    this->top++;
    this->arr[this->top] = data;

}


int pop()
{
    if(this->top == -1)
    {
        cout << "underflow " << endl;
        return INT_MIN;
    }
   
    this->top--;


}


int getTop()
{
    if(this->top == -1)
    {
        cout << "underflow" << endl;
        return INT_MIN;
    }
    return this->arr[this->top];
}

bool isEmpty()
{
    return this->top == -1;
}

int size()
{
    return this->top + 1;
}

bool isFull()
{
    return this->top == this->capacity-1;
}



};


int main()
{
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.getTop()<< endl;
    st.push(4);
    st.push(5);
    cout << st.getTop() << endl;
    st.push(8);

    st.pop();
    st.pop();

    cout << st.getTop() << endl;


    return 0;
}