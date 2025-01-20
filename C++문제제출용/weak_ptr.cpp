#include <iostream>
#include <memory>
//����Ʈ ������
//unique_ptr, shared_ptr, weak_ptr
//C++ 11
using namespace std;
class Test {
public:
	Test(int x) : x(x) { cout << "������" << endl; }
	~Test() { cout << "�Ҹ���" << endl; }
	int GetX() const { return x; }
private:
	int x;
};
int main()
{
	weak_ptr<Test> b;
	{
		//a�� ����Ű�� �ִ� ���� b�� �����ѵ�
		//�޸� �������� ��� use_count�� 1�̴�.
		shared_ptr<Test> a(new Test(6));
		b = a;
		cout << a.use_count() << endl; //1
		cout << b.use_count() << endl; //1
	}
	cout << b.use_count() << endl; //0
	
	//cout << b->GetX() << endl;
	//a�� �Ҹ�Ǿ��� ������ �Ұ�(��۸� ������)
	if (!b.expired()) {
		cout << b.lock()->GetX() << endl;
	}//b�� ����ִٸ� �������, �Ҹ�ƴٸ� ���� ����
}