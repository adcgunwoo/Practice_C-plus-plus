//생성자:객체가 생성될때 자동으로 호출되는 함수
//소멸자:객체가 소멸될때 자동으로 호출되는 함수
#include <iostream>
using namespace std;
class myclass {
public:
	myclass() {//생성자, 객체가 생성되면 자동 호출
		cout << "생성자가 호출되었다!" << endl;//순서 3
	}//생성자를 수기로 직접 작성했지만
	 //작성하지않아도 디폴트 생성자가 생성됨
	~myclass() {//소멸자
		cout << "소멸자가 호출되었다!" << endl;//순서 5
	}
};
//myclass globalobj;
void testlocalobj() {
	cout << "testlocalobj 함수 시작!" << endl;//순서 2
	myclass localobj;
	cout << "testlocalobj 함수 끝" << endl;//순서 4 
}
int main()
{
	cout << "main함수 시작" << endl;//순서 1
	testlocalobj();
	cout << "main함수 끝" << endl;//순서 6
	return 0;
}
/*
main함수 시작
testlocalobj 함수 시작!
생성자가 호출되었다!
testlocalobj 함수 끝
소멸자가 호출되었다!
main함수 끝
*/