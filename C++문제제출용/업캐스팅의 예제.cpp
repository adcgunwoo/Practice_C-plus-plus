#include <iostream>
using namespace std;

class Animal{//������ ��ǥ�� ���ϴ� Ŭ����
public:
	float xpos= 1, ypos = 2;
};

class FlyingAnimal : public Animal { 
public: //���ƴٴϱ� ������ z��ǥ�� �ʿ�
	float zpos = 3;
}; //

void PrintAnimals(Animal **a,int n) {
	for (int i = 0; i < n; i++) {
		cout << "(" << a[i]->xpos << ", " << a[i]->ypos << ")" << endl;
	}
}
int main()
{
	Animal** a = new Animal*[10];
	for (int i = 0; i < 10; i++) {
		a[i] = new FlyingAnimal;
	}
	//������ �迭�� ���� �Ҵ��Ϸ���
	// ���������͸� ����ؾ���
	
	PrintAnimals(a, 10);//��ĳ����

	for (int i = 0; i < 10; i++) {
		delete a[i];
	}
	
	delete []a;
}