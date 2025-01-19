#include <iostream>
using namespace std;
int main()
{
	int a(10);//C++에서는 이렇게 정의 가능
	//int a=10; 이건 C언어 스타일
	//C++도 이렇게 써도 됨
	
	//a(5)는 오류, 함수인지 변수인지 모름
	int b(a);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}