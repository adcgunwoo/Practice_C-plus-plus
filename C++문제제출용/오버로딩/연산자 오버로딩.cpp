//벡터+연산자 오버로딩
#include <iostream>
using namespace std;
class vector2 {
public:
	vector2(); //생성자 선언
	vector2(float x, float y);//생성자 선언
	float getx() const; //상수형 메서드는 이렇게 작성
	float gety() const;
	vector2 operator+(const vector2 rhs) const; //더하기
	vector2 operator-(const vector2 rhs) const; //兮
	vector2 operator*(const float rhs) const; //float 곱하기
	vector2 operator/(const float rhs) const; //나누기
	float operator*(const vector2 rhs) const; //벡터 곱하기 이거만 실수
	
	//(벡터 / 벡터) 는 안됨 (벡터 / 실수)는 가능
private:
	float x, y;
};
vector2 operator*(const float a, const vector2 b) /*const*/ {
	return vector2(a * b.getx(),a*b.gety());  //클래스에 속한 멤버 메서드가 아니기에
}                                             //const 못 붙힌다.

int main()
{
	vector2 a(2, 3);
	vector2 b(-1, 4);
	//vector2 c = a + b; 컴퓨터는 벡터 계산법을 몰라서 이런 방식은 오류
	vector2 c1 = a+b; 
	vector2 c2 = a * 1.6;
	vector2 c3 = 1.6 * a; 
	float c4 = a * b;

	cout << a.getx() << ", " << a.gety() << endl;
	cout << b.getx() << ", " << b.gety() << endl;
	cout << c1.getx() << ", " << c1.gety() << endl;
	cout << c2.getx() << ", " << c2.gety() << endl;
	cout << c3.getx() << ", " << c3.gety() << endl;
	cout << c4 << endl;

	return 0;
}
vector2::vector2() :x(0), y(0) {}
//생성자 정의, 네임스페이스 꼭 작성
vector2::vector2(float x, float y) :x(x), y(y) {}
//생성자 정의, 네임스페이스 꼭 작성
vector2 vector2::operator+(const vector2 rhs) const {
	return vector2(x + rhs.x, y + rhs.y);
}
vector2 vector2::operator-(const vector2 rhs) const {
	return vector2(x - rhs.x, y - rhs.y);
}
vector2 vector2::operator*(const float rhs) const {
	return vector2(x * rhs, y * rhs);
}
vector2 vector2::operator/(const float rhs) const {
	return vector2(x / rhs, y / rhs);
}
float vector2::operator*(const vector2 rhs) const {
	return x * rhs.x + y * rhs.y;
}
float vector2::getx() const { return x; }
float vector2::gety() const { return y; }
