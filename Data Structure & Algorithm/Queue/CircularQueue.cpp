#include<iostream>
using namespace std;

class CircularQueue {
    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(){
        size = 10000;
        arr = new int [size];
        front = rear = -1;
    }

    bool empty () {
        if (front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool push (int ele) {
        if((front == 0 && rear == size-1) || (rear == front-1)) {
            cout<<"Queue is Full"<<endl;
            return -1;   
        }
        else if (front == -1) {
            front = rear = 0;
        }
        else if (rear == size-1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = ele;
        return true;
    }

    int pop () {
        if (front == -1) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        int ans = arr[front];
        arr[front] = -1;
        return ans;
    }
};

int main(){
    CircularQueue cq;

    cq.push(1);
    cq.push(2);
    
    cq.pop();
    cq.empty();
    cq.pop();
    cq.empty();
    
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cq.push(6);
    cq.push(7);
    
}