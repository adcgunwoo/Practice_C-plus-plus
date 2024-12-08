#include <iostream>
using namespace std;
int main()
{
	int a = 7; //a를 선언, 7을 대입,C언어와 똑같다
	//이 형식은 a를 7로 초기화 했다고 한다.
	double b = 3.14;
	char c = 'C';
	bool d = 0;
	bool e = 1;
	bool f = 10; //bool은 0 또는 1만 저장하게 됨, 0이 아니라서 1이 출력

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "f = " << f << " " << "f의 크기는 = " << sizeof(f) << "바이트" << endl;
	return 0;
}