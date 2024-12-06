// reverse all the element in the same stack 

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st , int val)
{
    if(st.empty())
    {
        st.push(val);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottom(st,val);
    st.push(curr);


}

void stackRevRec( stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int curr = st.top();
    st.pop();
    stackRevRec(st);
    insertAtBottom(st , curr);


}

void stackRev(stack<int> &st)
{

    stack<int> temp;
    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    stack<int> temp2;
    while(!temp.empty())
    {
        temp2.push(temp.top());
        temp.pop();
    }

    while(!temp2.empty())
    {
        st.push(temp2.top());
        temp2.pop();
    }

}


stack<int> stackRev2(stack<int>&st)
{
    stack<int> temp;
    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    return temp;
}

int main()
{

stack<int> st,rev;

st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);
st.push(6);
st.push(7);

stackRevRec(st);
// stackRev(st);
// st = stackRev2(st);

while(!st.empty())
{
    cout << st.top() << endl;
    st.pop();
}


    return 0;
}