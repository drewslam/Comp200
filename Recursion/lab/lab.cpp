#include <iostream>

using namespace std;

int count = 0;
int midpoint = 999999999;
int radius = 999999999; 

void PrintNumPattern(int num1, int num2) {
   if (num1 < 0) {
      num2 *= -1;
      radius = count;
      count++;
      midpoint = count;
   }
   if (count <= (midpoint + radius)) {
      cout << num1 << " ";
      count++;
      PrintNumPattern(num1 -= num2, num2);
   }
}

int main() {
   int num1;
   int num2;

   cin >> num1;
   cin >> num2;
   PrintNumPattern(num1, num2);
   
   return 0;
}
