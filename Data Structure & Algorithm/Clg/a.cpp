#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q(5); 
    q.push (3); 
    q.push (5); 
    q.push (9); 
    cout<< q.remove(); 
    q.push(2); 
    q.push (4); 
    cout<< q.remove(); 
    cout<< q.remove();
    q.push(1); 
    q.push (8);

}