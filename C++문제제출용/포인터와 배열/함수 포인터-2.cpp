//함수 포인터
//함수를 가르키는 포인터
#include <iostream>
int square(int x) { return x * x; }
int myFunc(int x) { return x * (x - 15) / 2; }
int cube(int x) { return x * x * x; }

using namespace std;
int arrFnMin(const int arr[], int n, int (*f)(int)) {
	int min = f(arr[0]);           //int형 매개변수를 받아 int형 값을 
	for (int i = 1; i < n; i++) {  //반환하는 함수를 가르키는 함수 포인터
		if (f(arr[i]) < min) {
			min = f(arr[i]);
		}
	}							   
	return min;
}

int main() {
	int arr[7] = { 3,1,-4,1,5,9,-2 };
	cout << arrFnMin(arr, 7,square) << endl;
	cout << arrFnMin(arr, 7, myFunc) << endl;
	cout << arrFnMin(arr, 7, cube) << endl;
}
