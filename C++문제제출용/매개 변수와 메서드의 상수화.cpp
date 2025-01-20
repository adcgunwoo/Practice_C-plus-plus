//우리가 알던 상수형 변수 
//const double pi = 3.14;
//이번 시간은 const의 기능 2가지
//1. 매개변수의 상수화 (모든 함수)
//2. 메서드(클래스에 포함된 함수)의 상수화 (멤버 메서드)

#include <iostream>
using namespace std;
class account {
public:
	account() : money(0) {}
	account(int money) : money(money) {}

	void deposit(const int d) {
		//d=300; 임의로 식이 수정 불가능
		money += d;
		cout << d << "원을 예금했습니다."<<endl;
	}//매개변수의 상수화
	void draw(const int d) {
		if (money >= d) {
			money -= d;
			cout << d << "원을 인출했습니다." << endl;
		}
	}//매개변수의 상수화
	int viewmoney() const {
		return money;
	}//매서드의 상수화
	 //앞에 붙이는게 아닌 뒤에 붙여야함
private :
	int money;
};
int main()
{
	account woori(100);
	woori.deposit(100);
	woori.draw(20);

	cout << "잔액은 " << woori.viewmoney() << "원입니다." << endl;
	
	return 0;
}
