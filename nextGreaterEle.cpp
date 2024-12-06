
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> nextbiggestelement2(int arr[] ,int size)
{

    stack<int> st;
    vector<int>result(size , -1);
    st.push(0);
    for(int i=0 ; i < size ; i++)
    {
        while(!st.empty() && arr[i] > arr[st.top()])
        {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}


vector<int> nextsmallerelement(int arr[] ,int size)
{

    stack<int> st;
    vector<int>result(size , -1);
    st.push(0);
    for(int i=0 ; i < size ; i++)
    {
        while(!st.empty() && arr[i] < arr[st.top()])
        {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

// vector<int> nextbiggestelement(int arr[] ,int size)
// {

//     stack<int> smallele;
//     vector<int>result(size);
//     smallele.push(0);
//     int j = 1;
//     int i = 0;

//     while( j < size)
//     {
//         if(!smallele.empty() && arr[smallele.top()] < arr[j] )
//         {
//             result[smallele.top()] = arr[j];
//             smallele.pop();
//         }
//         else
//         {
//             smallele.push(j);
//             j++;

//         }
        
//     }

//     while(!smallele.empty())
//     {
//         result[smallele.top()] = -1;
//         smallele.pop();
//     }

//     return result;
    
// }



int main()
{

int array[] = {4,3,9,1,6,8,2};
int size = sizeof(array)/sizeof(array[0]);

vector<int> result = nextbiggestelement2(array , size);

for(int i = 0 ; i < result.size() ; i++)
{
    cout << result[i] << " ";
}cout << endl;

    return 0;
}
