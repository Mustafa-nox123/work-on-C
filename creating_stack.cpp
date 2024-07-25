#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
class STACK {
private:
    vector<T> stack;

public:
    STACK() {}

    
    void push(const T& element) {
        stack.push_back(element);
    }

  
    T pop() {
        if (stack.empty()) {
            throw out_of_range("Stack is empty. Cannot pop.");
        }
        T topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

   
    T peek() const {
        if (stack.empty()) {
            throw out_of_range("Stack is empty. Cannot peek.");
        }
        return stack.back();
    }

    
    void clear() {
        stack.clear();
    }

    
    bool Empty() const {
        return stack.empty();
    }
};

int main() {
    STACK<int> iStack;
    
    try {
        iStack.push(10);
        iStack.push(20);
        iStack.push(30);

        cout << "Top element is: " << iStack.peek() << endl;
        
        while (!intStack.isEmpty()) {
            cout << "Popped: " << iStack.pop() << endl;
        }

        cout << " Stack empty? " << (iStack.isEmpty() ? "Yes" : "No") << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}


