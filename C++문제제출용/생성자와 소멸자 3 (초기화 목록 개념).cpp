#include <iostream>
using namespace std;
//������ : ��� ���� �ʱ�ȭ
//�Ҹ��� : �޸� ����, �Ŀ� �� ����

//���Ҽ� ���� Ŭ���� �ۼ�
class complex {
public:
	complex():real(0), imag(0) { }
	complex(double real_, double imag_):real(real_), imag(imag_) { }
  //complex(double real, double imag) : real(real),imag(imag) { }
	//�̷��� ������� �ʱ�ȭ �ϴ°��� �ʱ�ȭ ����̶�� �Ѵ�,		
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
	//�ɹ������� ��ü ������ ������� ��� ����
};
int main()
{

	complex c1;
	complex c2 = complex(2,3);
	complex c3(2, 3); 
	complex c4 = { 2,3 };
	complex c5 = complex{ 2,3 };
	complex c6{ 2,3 }; //2������ 6���� ��� ������ �ǹ�
	cout << "c1 = " << c1.getreal() << ", " << c1.getimg() << endl;
	cout << "c2 = " << c2.getreal() << ", " << c2.getimg() << endl;
	cout << "c3 = " << c3.getreal() << ", " << c3.getimg() << endl;
	cout << "c4 = " << c4.getreal() << ", " << c4.getimg() << endl;
	cout << "c5 = " << c5.getreal() << ", " << c5.getimg() << endl;
	cout << "c6 = " << c6.getreal() << ", " << c6.getimg() << endl;
	return 0;
}