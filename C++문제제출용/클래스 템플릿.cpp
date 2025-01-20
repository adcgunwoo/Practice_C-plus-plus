//�Լ� ���ø�
//Ŭ���� ���ø�
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Vector2 { //Vector2�� Ŭ������ �ƴ϶�, Ŭ���� ���ø��̴�
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
	//Ŭ���� ���ø��� <�ڷ���>�� ����� ����
	Vector2<float> v1(2, 3);
	Vector2<double> v2(4, 5);
	cout << sizeof(v1) << endl;
	cout << sizeof(v2) << endl;
}