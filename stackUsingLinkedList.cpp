 #include<iostream>
 #include<limits.h>
 using namespace std;

 class node
 {
    public:
    int data;
    node* next;
    
    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
 };

class stack
{

    node* head;
    int capacity ;
    int currsize;
    public:
    stack(int c )
    {
        this->capacity = c;
        this->currsize = 0;
        head = NULL;
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }
    bool isFull()
    {
        return this->currsize == this->capacity;
    }

    void push(int data)
    {
        if(this->currsize == this->capacity)
        {
            cout << "Overflow" << endl;
            return ;
        }

        if(head == NULL)
        {
            head = new node(data);
            this->currsize++;
            return ;
        }

        node* newnode = new node(data);
        newnode->next = this->head;
        this->head = newnode;
        this->currsize++;
        
    }

    int pop()
    {
        if(head == NULL)
        {
            cout << "underflow " << endl;
            return INT_MIN;
        }
        int result = this->head->data;
        node* newhead = this->head->next;
        this->head->next = NULL;
        delete this->head;
        this->head = newhead;
        return result;
    }

    int getTop()
    {
        if(this->head == NULL)
        {
            cout << "underflow" << endl;
            return INT_MIN;
        }

        return this->head->data;
    }

    int size()
    {
        return this->currsize;
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