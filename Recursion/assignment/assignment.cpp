#include <iostream>
using namespace std;

int Fibonacci(int n) {
   int fib;
   if (n < 0) {
      return -1;
   } else if (n == 0 || n == 1) {
      return n;
   }
   fib = Fibonacci(n - 1) + Fibonacci(n - 2);
   
   return fib;
}

int main() {
   int startNum;
   
   cin >> startNum;  
   cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;
   
   return 0;
}

