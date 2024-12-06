// insert element at bottom or insert element at indx


#include<iostream>
#include<stack>
using namespace std;


void insertAt_bottom(stack<int> &stk , int val)
{

    if(stk.empty())
    {
        stk.push(val);
        return;
    }
    int currtop = stk.top();
    stk.pop();
    insertAt_bottom(stk , val);
    stk.push(currtop);

}


void insertAt_bottomIndx(stack<int> &stk , int val)
{
    stack<int>temp ;
    while(!stk.empty())
    {
        temp.push(stk.top());
        stk.pop();
    }

    stk.push(val);

    while(!temp.empty())
    {
        stk.push(temp.top());
        temp.pop();
    }


}




void insertAt_indx( stack<int> &st , int val , int indx )
{
stack<int> temp ;
int stksize = st.size();

int count = 0;

while(count < stksize-indx)
{
    temp.push(st.top());
    st.pop();
    count++;
}

st.push(val);

while(!temp.empty())
{
    st.push(temp.top());
    temp.pop();
}

}

int main()
{

stack<int> st, bottom;

st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);

insertAt_bottom(st,7);
insertAt_indx(st,100,2);

while(!st.empty())
{
    cout << st.top() << endl;
    st.pop();
}


    return 0;
}