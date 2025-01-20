//��ü���� ���α׷����� �߻��ϴ� ����
//���̾Ƹ�� ����(��� �޴� ����� ������ ���� ���ܼ�)
//���߻�� ������
//�� Ŭ������ ���� Ŭ������ ��ӹ��� ��
//������

//���� ����� �������̽��κ��͸� �޴´�.
//�������̽�:��� �޼��尡 ���� �����Լ��̰� (������)��� ������ ���� Ŭ����
//�߻� Ŭ����: ���� ���� �Լ��� �ϳ� �̻� ��� �ִ� Ŭ����
//������ Ŭ����: ���� �Լ��� �ϳ� �̻� ��� �ִ� Ŭ����
#include <iostream>
using namespace std;
class IPerson {//�������̽���� ���� ��Ÿ���ֱ� ���� 'I'
public:
	virtual ~IPerson() {}
	virtual void Eat() = 0;
};
class IStudent : virtual public IPerson {
	virtual void Study() = 0;
};
class Student: public IStudent {
public:
	void Eat() {
		cout << "�ȳ�..." << endl;
	}
	void Study() {
		cout << "�����Ѵ�..." << endl;
	}
	void Work() {
		cout << "���Ѵ�..." << endl;
	}
};
class IWorker : virtual public IPerson {
	virtual void Work() = 0;
};
class Researcher : public IStudent, public IWorker {//���߻��
	//���� ���� ������ student�� Worker�� ���� ����� �޾�����
	//Person���κ��� ���������� �޾ƿ�
public:
	void Eat() {
		cout << "�Դ´�..." << endl;
	}
	void Study() {
		cout << "�����Ѵ�..." << endl;
	}
	void Work() {
		cout << "���Ѵ�..." << endl;
	}
};
int main()
{
	Researcher r;
	Student s;
	r.Eat();
	s.Eat();
	//���߻���� ���� ���� �������� Ȱ���� �� ����
}