#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    // Push operation
    void push(int x) {
        // Push x to q2
        q2.push(x);
        
        // Transfer all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap the names of q1 and q2
        swap(q1, q2);
    }

    // Pop operation
    void pop() {
        if (q1.empty()) {
            cout << "Stack underflow\n";
            return;
        }
        q1.pop();
    }

    // Top operation
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    cout << "Top element: " << stack.top() << endl; // Output: 3
    stack.pop();
    
    cout << "Top element: " << stack.top() << endl; // Output: 2
    stack.pop();
    
    cout << "Top element: " << stack.top() << endl; // Output: 1
    stack.pop();
    
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: Yes
    
    return 0;
}