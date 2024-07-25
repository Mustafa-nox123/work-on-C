#include<iostream>
using namespace std;

bool isPrime(int num, int i = 2) {
   // if (num <= 2) {
     //   return (num == 2);
    //}
    if (num % i == 0) {
        return false;
    }
    if (i * i > num) {
        return true;
    }
    return isPrime(num, i + 1);
}



int main(){
	
	int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (isPrime(num)) {
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }
}
