#include <iostream>
#include <stack>

class MyQueue {
public:
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int front = s1.top();
        s1.pop();
        return front;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }

private:
    std::stack<int> s1;
    std::stack<int> s2;
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);

    std::cout << "Peek: " << myQueue.peek() << std::endl;
    std::cout << "Pop: " << myQueue.pop() << std::endl;
    std::cout << "Empty: " << std::boolalpha << myQueue.empty() << std::endl;

    return 0;
}
