#include<iostream>
using namespace std;

class Stack {

    public:
    int top;
    int size; 
    int *arr;
    Stack (int size){ 
        this -> size = size;
        top = -1;
        arr = new int[size];
    }
    void push(int ele){
        if(size - top > 1){
            top++;
            arr[top] = ele;
        }
        else {
            cout<< "stack is full "<<endl;
        }
    }
    void pop () {

        if(top >= 0){
            top--;
        }
        else {
            cout<< "stack is empty "<<endl;
        }
    }

    int peak () {
        if(top >= 0 && top < size) 
            return arr[top];
        else {
            cout<<"Stack is empty"<<endl; 
            return -1;
        }
    }
    bool empty () {

        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Stack st(5);

    st.push(22);
    st.push(23);
    st.push(24);

    cout << st.peak() << endl;
    st.pop();
    cout << st.peak() << endl;

}