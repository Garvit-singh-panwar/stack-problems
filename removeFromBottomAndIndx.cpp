//  remove element from bottom 

#include<iostream>
#include<stack>
using namespace std;


void removeFromBottom( stack<int> &st)
{

    stack<int>temp;
    while(st.size() != 1)
    {
        temp.push(st.top());
        st.pop();
    }

    st.pop();

    while(!temp.empty())
    { 
        st.push(temp.top());
        temp.pop();
    }
}


void removeFromBottomRec(stack<int> &st)
{
    
    if(st.size() == 1 )
    {
        st.pop();
        return;
    }

    int curr = st.top();
    st.pop();
    removeFromBottomRec(st);
    st.push(curr);
}

void removeFromIndx(stack<int> &st ,int indx)
{
    stack<int> temp;
    int size = st.size();
    while(  st.size() !=  indx+1)
    {
        temp.push(st.top());
        st.pop();
    }

    st.pop();

    while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }

}

void removeFromIndxRec(stack<int> &st ,int indx)
{
    if(st.size() == indx+1)
    {
        st.pop();
        return;
    }

    int curr = st.top();
    st.pop();
    removeFromIndxRec(st,indx);
    st.push(curr);

}

int main()
{

stack<int> stk;
stk.push(1);
stk.push(2);
stk.push(3);
stk.push(4);
stk.push(5);
stk.push(6);

// removeFromBottom(stk);
removeFromIndxRec(stk , 2);

while(!stk.empty())
{
    cout << stk.top() << endl;
    stk.pop();
}
    return 0;
}