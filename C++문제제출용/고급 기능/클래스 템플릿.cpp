//함수 템플릿
//클래스 템플릿
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Vector2 { //Vector2는 클래스가 아니라, 클래스 템플릿이다
public:
	Vector2() :x(0), y(0) {}
	Vector2(T x, T y) :x(x), y(y) {}
	T GetX() const { return x; }
	T GetY() const { return y; }
	Vector2 operator+(const Vector2/*<T>*/& rhs) {
		return Vector2(x + rhs.x, y + rhs.y);
	}
	Vector2 operator-(const Vector2& rhs) {
		return Vector2(x - rhs.x, y - rhs.y);
	}
	Vector2& operator+=(const Vector2& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Vector2& operator-=(const Vector2& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
private:
	T x, y;
};
int main()
{
	//클래스 템플릿은 <자료형>을 지울수 없다
	Vector2<float> v1(2, 3);
	Vector2<double> v2(4, 5);
	cout << sizeof(v1) << endl;
	cout << sizeof(v2) << endl;
}
