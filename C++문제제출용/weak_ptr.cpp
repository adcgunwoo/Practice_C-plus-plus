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
	weak_ptr<Test> b;
	{
		//a가 가르키고 있는 곳을 b가 가르켜도
		//메모리 소유권이 없어서 use_count는 1이다.
		shared_ptr<Test> a(new Test(6));
		b = a;
		cout << a.use_count() << endl; //1
		cout << b.use_count() << endl; //1
	}
	cout << b.use_count() << endl; //0
	
	//cout << b->GetX() << endl;
	//a가 소멸되었기 때문에 불가(댕글링 포인터)
	if (!b.expired()) {
		cout << b.lock()->GetX() << endl;
	}//b가 살아있다면 정상출력, 소멸됐다면 널을 리턴
}