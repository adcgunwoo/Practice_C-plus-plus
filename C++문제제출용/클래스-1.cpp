#include <iostream>
using namespace std;
//����ü�� Ŭ������ ����
//Ŭ����=�ڷ� ����+�ڷ� ó��=����+�Լ�
//Ŭ����(Ÿ��):Ư���� �뵵�� �����ϱ� ���� ������ �Լ��� ��� �� Ʋ(�ڷ���)
//��ü(������Ʈ):�� Ʋ�� �̿��Ͽ� �� ��ü(����, �޸� ���� ����)

//�ڸ����� �����
// �������� ���� : public, private, protected
struct tv {
	//struct�� class�� ���� 
	//struct�� private�� �Ⱦ��� public�� �Ӽ�
	//class�� �� �ᵵ private�� �Ӽ��� ����
private:
	bool power;
	int channel;
	int volume;
public:
	void setvolume(int vol) {
		if (vol >= 0 && vol <= 100) {
			volume = vol;
			cout << "������ " << vol << "��(��) �ٲ���ϴ�." << endl;
		}
	}
	void on() {
		power = true;
		cout << "TV�� �׽��ϴ�." << endl;
	}
	void off() {
		power = false;
		cout << "TV�� �����ϴ�." << endl;
	}
	void setchannel(int cnl) {
		if (cnl >= 1 && cnl <= 99) {
			channel = cnl;
			cout << "ä���� " << cnl << "��(��) �ٲ���ϴ�." << endl;
		}
	}
};

int main()
{
	tv lg;
	cout << "TV �⺻ �����Դϴ�." << endl;
	lg.on();
	lg.setchannel(10);
	lg.setvolume(50);
	lg.off();

	return 0;
}