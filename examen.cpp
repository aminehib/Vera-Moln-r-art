//EXAMEN C++

//1
#include <iostream>
using namespace std;
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}


//2

int sumArray(int arr[], int size) {
  if (size == 0) {
    return 0;
  } else {
    return arr[0] + sumArray(arr + 1, size - 1);
  }
}

//3
string reverseString(string str) {
  if (str.length() <= 1) {
    return str;
  } else {
    return reverseString(str.substr(1)) + str[0];
  }
}

//4

bool palindrome(char mot){

}

//5

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

//6 
void TourHanoi(int nbr,string noms){

}

//7

//8

int nbchemin(int m, int n) {
  if (m == 1 || n == 1) {
    return 1; 
  } else {
    return nbchemin(m - 1, n) + nbchemin(m, n - 1);
  }
}

//9
void generate_subsets(int index, int current, int array){



    if index == len(array){
    generate_subsets(index + 1, current, array)
        generate_subsets(index + 1, current + [array[index]], array)

    }
}


//10


















