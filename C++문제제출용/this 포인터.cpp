//this 자기 자신을 가르키는 포인터
#include <iostream>
using namespace std;
class myclass {
public:
	void printthis() {
		cout << "나의 주소는() " << this << endl;
	}//this는 보이지 않는 매개변수
//printthis는 따로 매개변수를 받지 않아도 어디 객체 소속인지를 알 수 있다.
	void printthisptr(myclass *ptr) {
		cout << "나의 주소는(*ptr) " <<ptr <<endl;
	}
};
int main()
{
	myclass a, b;//객체 생성
	cout << "a의 주소는 " << &a << endl;
	cout << "b의 주소는 " << &b << endl;
	a.printthisptr(&a);
	b.printthisptr(&b);
	a.printthis();
	b.printthis();
	//16진수로 출력됨
	//&a와 a.printthis()의 값이 같음
	//따라서 this는 소속된 객체의 주소값을 출력
	
	return 0;
}