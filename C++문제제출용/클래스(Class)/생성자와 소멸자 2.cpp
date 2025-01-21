#include <iostream>
using namespace std;
//생성자 : 멤버 변수 초기화
//소멸자 : 메모리 해제, 후에 더 나옴

//복소수 저장 클래스 작성
class complex {
public:
	complex() {
		real = 0;
		imag = 0;
	}
	complex(double real_,double imag_) {
		real = real_;
		imag = imag_;
	}
	double getreal() {
		return real;
	}
	void setreal(double real_) {
		real = real_;
	}
	double getimg() {
		return imag;
	}
	void setimg(double imag_) {
		imag = imag_;
	}
private:
	double real, imag;
	//맴버변수는 객체 내에서 상관없이 사용 가능
};
int main()
{
	complex c1;
	complex c2 = complex(2,3);
	complex c3(2, 3); 
	complex c4 = { 2,3 };
	complex c5 = complex{ 2,3 };
	complex c6{ 2,3 }; //2번부터 6번은 모두 동일한 의미
	cout << "c1 = " << c1.getreal() << ", " << c1.getimg() << endl;
	cout << "c2 = " << c2.getreal() << ", " << c2.getimg() << endl;
	cout << "c3 = " << c3.getreal() << ", " << c3.getimg() << endl;
	cout << "c4 = " << c4.getreal() << ", " << c4.getimg() << endl;
	cout << "c5 = " << c5.getreal() << ", " << c5.getimg() << endl;
	cout << "c6 = " << c6.getreal() << ", " << c6.getimg() << endl;
	return 0;
}
