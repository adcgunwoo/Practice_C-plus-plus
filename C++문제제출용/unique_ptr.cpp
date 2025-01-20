#include <iostream>
#include <memory>
//스마트 포인터
//unique_ptr, shared_ptr, weak_ptr
//C++ 11
using namespace std;
class Test {
public:
	Test(int x) : x(x) { cout << "생성자" << endl; }
	~Test() { cout << "소멸자" << endl; }
	int GetX() const { return x; }
private:
	int x;
};
int main()
{
	/*
	cout << "main 함수 시작" << endl;
	unique_ptr<Test> a(new Test); 
	//delete가 없는데 메인 끝나니 알아서 소멸
	//unique_ptr는 한 대상만 가르킬 수 있다
	cout << "main 함수 종료" << endl;
	*/
	unique_ptr<Test> a(new Test(5));
	cout << a->GetX() << endl;
	cout << "====" << endl;
	//unique_ptr<int> b(a.release());
	//a의 소유권 끊기, 그리고 소유권 이전
	a.reset(new Test(6));//해제하고 다른 곳을 가르키게 재설정
	//6을 가르키는 생성자가 먼저 생성되고, 소멸하게 됨!
	cout << a->GetX() << endl;
	cout << "====" << endl;
	
	
}