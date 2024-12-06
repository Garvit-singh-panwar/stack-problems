// Copy content of one stack to another in same order 

#include<iostream>
#include<stack>
using namespace std;

// when we transfer data from 1 stack to another it gets reversed 


stack<int> copystack(stack<int> &input)
{

    stack<int> temp ;
    while(! input.empty())
    {
        // do the process until our input stack become empty 

        int curr = input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result ;
    while(!temp.empty())
    {
        result.push(temp.top());
        temp.pop();
    }
    return result;


}

void copyStk(stack<int> &input , stack<int> &result)
{
    if(input.empty())
    {
        return;
    }
    int currTop = input.top(); 
    input.pop();
    copyStk(input,result);
    result.push(currTop);

}

int main()
{

stack<int > st,copy;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);
st.push(6);

// copy = copystack(st);

copyStk(st,copy);


while(!copy.empty())
{
    cout << copy.top() << endl;
    copy.pop();
}



    return 0;
}