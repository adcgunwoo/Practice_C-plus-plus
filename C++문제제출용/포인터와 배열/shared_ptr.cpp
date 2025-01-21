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
	
	//shared_ptr 하나만 되는 unique_ptr과 
	//다르게 여러 포인터가 하나를 가르킬수있게됨
	shared_ptr<Test> a(new Test(5));
	{
		shared_ptr<Test> b = a;
		cout << a.use_count() << endl;
		cout << b.use_count() << endl;
	}//두개가 가르킴
	cout << a.use_count() << endl;
	//여기서는 b가 소멸되면서 하나만 가르킴
}
