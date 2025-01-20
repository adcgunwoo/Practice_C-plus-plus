//함수 객체(function object/funtor)
//함수처럼 작동하는 객체

//람다식(익명 함수)
#include <iostream>
//#include <functional>
using namespace std;

class Square {
public:
	int operator()(int n) { return n * n; }
}square;

class MyFunc {
public:
	int operator()(int n) { return n * (n - 15) / 2; }
}myFunc;

template<typename T>
int arrFnMin(const int arr[], int n, /*function<int(int)>*/T f) {
	int min = f(arr[0]);           //int를 넣어서 int가 나오게 함
	for (int i = 1; i < n; i++) {  
		if (f(arr[i]) < min) {
			min = f(arr[i]);
		}
	}
	return min;
}

int main() {
	int arr[7] = { 3,1,-4,1,5,9,-2 };

	cout << arrFnMin<Square>(arr, 7, square) << endl;
	cout << arrFnMin(arr, 7, [](int n)-> int{return n * n; }) << endl;
	//위가 람다식, 이름이 없음
	cout << arrFnMin<MyFunc>(arr, 7, myFunc) << endl;
	
	auto a = [](int n)-> int { return n * (n - 15) / 2; };
	//컴파일러가 자동으로 좌변의 자료형을 설정함
	//auto b = arr[0];
}