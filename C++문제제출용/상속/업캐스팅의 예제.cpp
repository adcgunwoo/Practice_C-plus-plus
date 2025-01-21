#include <iostream>
using namespace std;

class Animal{//동물의 좌표를 구하는 클래스
public:
	float xpos= 1, ypos = 2;
};

class FlyingAnimal : public Animal { 
public: //날아다니기 때문에 z좌표도 필요
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
	//포인터 배열을 동적 할당하려면
	// 더플포인터를 사용해야함
	
	PrintAnimals(a, 10);//업캐스팅

	for (int i = 0; i < 10; i++) {
		delete a[i];
	}
	
	delete []a;
}
