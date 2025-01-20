#include <iostream>
using namespace std;
int main()
{
	int a(5);
	int& p = a;
	//레퍼런스는 아래에서 값이 바뀌면
	//둘다 바뀐다
	p = 10;
	cout << p << endl;
	cout << a << endl;

	int b(5);
	int& r1 = b;
	int& r2 = 3;//상수를 가르킬순 없음
	int& r3 = b * b;//식도 안됨
	//r-value 와 l-value
	//b는 수정 가능, 3은 불가, b*b 불가
	//식 자체에 값을 못 넣기 때문
	
	//r-value
	int c(5);
	int&& r4 = b;//바꿀수 있는 값이기에 안됨
	int&& r5 = 4;//수정 불가하기에 가능
	int&& r6 = b * b;//함수값도 수정 불가하기에 가능


	return 0;
}