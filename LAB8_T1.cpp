#include <iostream>


using namespace std;

template<typename T>
class SimpleCalculator {
public:
    SimpleCalculator() = default;

   
    T add(T a, T b) const {
        return a + b;
    }

   
    T subtract(T a, T b) const {
        return a - b;
    }

    T multiply(T a, T b) const {
        return a * b;
    }

  
    T divide(T a, T b) const {
        if (b == 0) {
            throw invalid_argument("Division by zero");
        }
        return a / b;
    }


    void display(T result) const {
        cout << "Result: " << result << endl;
    }
};

int main() {
    SimpleCalculator<int> intCalculator;
    try {
        int a = 10, b = 5;
        int result = Calculator.add(a, b);
        Calculator.display(result);
        
        result = Calculator.subtract(a, b);
        Calculator.display(result);
        
        result = Calculator.multiply(a, b);
        Calculator.display(result);
        
        result = Calculator.divide(a, b);
        Calculator.display(result);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    SimpleCalculator<double> doubleCalculator;
    try {
        double a = 18.0, b = 0.0;
        double result = doubleCalculator.divide(a, b);
        doubleCalculator.display(result);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

