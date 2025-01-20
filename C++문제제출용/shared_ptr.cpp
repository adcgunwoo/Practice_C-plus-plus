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
	
	//shared_ptr �ϳ��� �Ǵ� unique_ptr�� 
	//�ٸ��� ���� �����Ͱ� �ϳ��� ����ų���ְԵ�
	shared_ptr<Test> a(new Test(5));
	{
		shared_ptr<Test> b = a;
		cout << a.use_count() << endl;
		cout << b.use_count() << endl;
	}//�ΰ��� ����Ŵ
	cout << a.use_count() << endl;
	//���⼭�� b�� �Ҹ�Ǹ鼭 �ϳ��� ����Ŵ
}