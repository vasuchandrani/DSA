#include<iostream>
using namespace std;

class Queue {

    public:
    int front;
    int rear;
    int size;
    int *arr;

    Queue(){
        size = 10000;
        rear = front = 0; //-1
        arr = new int[size]; 
    }
    
    void push (int ele) { // enqueue
        if (rear == size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear] = ele;
            rear++;
        }
    }

    int pop () {
        if(front == rear) {
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    bool empty () {
        if (front == rear ) {
            return true;
        }
        else{
            return false;
        }
    }

    int getFront () {
        if (front >= 0){
            return arr[front];
        }
        else{
            cout<<"Queue is empty"<<endl;
            return -1;
        }
    } 
};

int main(){
    Queue Q;
    Q.push(2);
    Q.push(3);
    
    Q.pop();
    Q.empty();
    Q.pop();
    Q.empty();
    
    Q.getFront();
    Q.push(4);
    Q.getFront();
    Q.push(5);
    Q.getFront();
    Q.push(6);

}
