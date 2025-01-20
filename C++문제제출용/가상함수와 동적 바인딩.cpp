//�������ε� ����
//�θ�Ŭ������ �����Ͱ� �ڽ� Ŭ������ ��ü�� ����Ű�� ��Ȳ����
//�ڽ�Ŭ������ �θ�Ŭ������ �Լ��� �������̵��ߴٸ�
//�θ�Ŭ������ �������̵��� �Լ��� �ƴ� �θ�Ŭ������ �Լ��� ȣ���

//�������ε� ����
//�� ��Ȳ���� �������̵��� �ڽ�Ŭ������ �Լ��� �����Ҽ� �ְ� �Ѵ�

#include <iostream>
using namespace std;
class Weapon {
public:
	Weapon(int power) :power(power) { //���Ӽ� ����
		cout << "Weapon(int)" << endl;
	}
	virtual void Use() { //���⸦ ����ϴ� ����(Ŭ��, Ű����)
		cout << "Weapon::Use" << endl;
	} //�����Լ�
protected:
	int power;
};
class Sword :public Weapon{
public:
	Sword(int power) : Weapon(power) {//�θ�Ŭ���� �����ڸ� ���� �ʱ�ȭ
		cout << "Sword(int)" << endl;
	}
	void Use() { //use�Լ� �������̵�
		cout << "Sword::Use" << endl;
		Swing();
	}
private:
	void Swing() {
		cout << "Swing Sword" << endl;
	}
};
class Magic : public Weapon {
public:
	Magic(int power, int manaCost) : Weapon(power),manaCost(manaCost) {
		cout << "Magic(int, int)" << endl;
	}
	void Use() {
		cout << "Magic::Use" << endl;
		Cast();
	}
private:
	void Cast() {
		cout << "Cast magic" << endl;
	}
	int manaCost;
};
int main()
{
	Sword mySword(10);
	Magic myMagic(15, 7);

	mySword.Use();
	myMagic.Use();
	
	Weapon* currentWeapon; //���� ����ִ� ���⸦ ����Ű�� �ִ� ������
	currentWeapon = &mySword;
	currentWeapon->Use(); //Į�� ���Ǿ��ϴµ�, �׳� ���Ⱑ ����
	//virtual�� �̿��� Į�� �ֵθ��� ��
	//�����Լ��� ����� ģȭ���̶�,
	// �ڽ�Ŭ������ �θ��� �Լ��� �������̵����� �� 
	// �������ε��� �Ͼ��. ����
	// �����Ϸ��� �����ϴ� �������� 
	// ����ڰ� ���ϴ� �������� �Ҽ� �ְԵ�
	currentWeapon = &myMagic;
	currentWeapon->Use();
}
