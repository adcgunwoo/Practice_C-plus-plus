//전에 알던 정적 할당: int a;
//C++에서 동적 할당:프러그램 실행 중에 변수를 메모리에 할당하는 것
#include <iostream>
using namespace std;
int main()
{
	int *a = new int(5); //마우스를 올려보면 operator가 뜸
						 //operator는 연산자라는 의미
	
	cout << a << endl; //주소값 출력
	cout << *a << endl; //값 출력

	*a = 10;
	cout << a << endl;
	cout << *a << endl;

	delete a;
}    