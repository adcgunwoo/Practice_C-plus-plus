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
	/*
	cout << "main �Լ� ����" << endl;
	unique_ptr<Test> a(new Test); 
	//delete�� ���µ� ���� ������ �˾Ƽ� �Ҹ�
	//unique_ptr�� �� ��� ����ų �� �ִ�
	cout << "main �Լ� ����" << endl;
	*/
	unique_ptr<Test> a(new Test(5));
	cout << a->GetX() << endl;
	cout << "====" << endl;
	//unique_ptr<int> b(a.release());
	//a�� ������ ����, �׸��� ������ ����
	a.reset(new Test(6));//�����ϰ� �ٸ� ���� ����Ű�� �缳��
	//6�� ����Ű�� �����ڰ� ���� �����ǰ�, �Ҹ��ϰ� ��!
	cout << a->GetX() << endl;
	cout << "====" << endl;
	
	
}