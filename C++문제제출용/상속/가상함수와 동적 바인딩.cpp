//정적바인딩 정리
//부모클래스의 포인터가 자식 클래스의 객체를 가르키는 상황에서
//자식클래스가 부모클래스의 함수를 오버라이딩했다면
//부모클래스의 오버라이딩된 함수가 아닌 부모클래스의 함수가 호출됨

//동적바인딩 정리
//위 상황에서 오버라이딩된 자식클래스의 함수를 실행할수 있게 한다

#include <iostream>
using namespace std;
class Weapon {
public:
	Weapon(int power) :power(power) { //게임속 무기
		cout << "Weapon(int)" << endl;
	}
	virtual void Use() { //무기를 사용하는 순간(클릭, 키보드)
		cout << "Weapon::Use" << endl;
	} //가상함수
protected:
	int power;
};
class Sword :public Weapon{
public:
	Sword(int power) : Weapon(power) {//부모클래스 생성자를 통해 초기화
		cout << "Sword(int)" << endl;
	}
	void Use() { //use함수 오버라이딩
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
	
	Weapon* currentWeapon; //현재 들고있는 무기를 가리키고 있는 포인터
	currentWeapon = &mySword;
	currentWeapon->Use(); //칼이 사용되야하는데, 그냥 무기가 사용됨
	//virtual을 이용해 칼을 휘두르게 함
	//가상함수는 사용자 친화적이라,
	// 자식클래스가 부모의 함수를 오버라이딩했을 때 
	// 동적바인딩이 일어난다. 따라서
	// 컴파일러가 실행하는 시점에서 
	// 사용자가 원하는 방향으로 할수 있게됨
	currentWeapon = &myMagic;
	currentWeapon->Use();
}
