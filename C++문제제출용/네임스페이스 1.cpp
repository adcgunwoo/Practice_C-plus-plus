#include <iostream>
using namespace std;
int n; //��������
void set();//��𿡵� ������ ����
//���ӽ����̽��ȿ� �Լ��� �����ϰ�
//�Ʒ����� ������ �� ����
namespace doodle {
	int n;
	void set(); 
	//���ӽ����̽��ȿ� �Լ��� �����ϰ�
}//�Ʒ����� ������ �� ����            
namespace google {
	int n;
	void set();
	//���ӽ����̽��ȿ� �Լ��� �����ϰ�
}//�Ʒ����� ������ �� ����
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
	n = 10; //����� �������� n
}             //��𿡵� ������ ����
namespace doodle {
	void set() {//������ �Լ� ����
		n = 20;
	}
}
void google::set() {//�̷� ������� �Լ��� 
		n = 30;     //���� ����
}
