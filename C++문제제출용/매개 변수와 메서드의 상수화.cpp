//�츮�� �˴� ����� ���� 
//const double pi = 3.14;
//�̹� �ð��� const�� ��� 2����
//1. �Ű������� ���ȭ (��� �Լ�)
//2. �޼���(Ŭ������ ���Ե� �Լ�)�� ���ȭ (��� �޼���)

#include <iostream>
using namespace std;
class account {
public:
	account() : money(0) {}
	account(int money) : money(money) {}

	void deposit(const int d) {
		//d=300; ���Ƿ� ���� ���� �Ұ���
		money += d;
		cout << d << "���� �����߽��ϴ�."<<endl;
	}//�Ű������� ���ȭ
	void draw(const int d) {
		if (money >= d) {
			money -= d;
			cout << d << "���� �����߽��ϴ�." << endl;
		}
	}//�Ű������� ���ȭ
	int viewmoney() const {
		return money;
	}//�ż����� ���ȭ
	 //�տ� ���̴°� �ƴ� �ڿ� �ٿ�����
private :
	int money;
};
int main()
{
	account woori(100);
	woori.deposit(100);
	woori.draw(20);

	cout << "�ܾ��� " << woori.viewmoney() << "���Դϴ�." << endl;
	
	return 0;
}
