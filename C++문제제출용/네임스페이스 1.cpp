#include <iostream>
using namespace std;
int n; //전역변수
void set();//어디에도 속하지 않음
//네임스페이스안에 함수만 선언하고
//아래에서 정의할 수 있음
namespace doodle {
	int n;
	void set(); 
	//네임스페이스안에 함수만 선언하고
}//아래에서 정의할 수 있음            
namespace google {
	int n;
	void set();
	//네임스페이스안에 함수만 선언하고
}//아래에서 정의할 수 있음
int main()
{
	::set();
	doodle::set();
	google::set();
	cout << ::n << endl; //10
	cout << doodle::n << endl; //20
	cout << google::n << endl; //30

	return 0;
}
void ::set() {
	n = 10; //명시적 전역변수 n
}             //어디에도 속하지 않음
namespace doodle {
	void set() {//선언한 함수 정의
		n = 20;
	}
}
void google::set() {//이런 방식으로 함수를 
		n = 30;     //정의 가능
}
