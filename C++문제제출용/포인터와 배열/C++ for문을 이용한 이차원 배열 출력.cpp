#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int arr[2][3] = { {1,2,3},{4,5,6} };
	
	for (auto& ln : arr) { 
		for (auto& col : ln) {
			cout << col << " ";
		}
		cout << endl;
	}//범위 기반 for문
	cout << endl;
	for (int (*ln)[3] = arr; ln < arr + 2; ln++) {
		for (int* c = *ln; c < *ln + 3; c++) {
			cout << *c << " ";
		}
		cout << endl;
	}//포인터 연산
	cout << endl;
	for (int(&ln)[3] : arr) {
		for (int& col : ln) {
			cout << col << " ";
		}
		cout << endl;
	}//참조를 사용한 배열 순회

}
