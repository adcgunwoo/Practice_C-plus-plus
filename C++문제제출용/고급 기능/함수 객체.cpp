//함수 객체(function object/funtor)
//함수처럼 작동하는 객체

#include <iostream>
using namespace std;
class Equals {
public:
	Equals(int value):value(value){}

	bool operator()(int x)const {
		return x == value;
	}
	bool operator()(int x,int y)const {
		return x+y == value;
	}
private:
	int value;
};

int main() {
	Equals eq(123);
	cout << eq(12,111) << endl;
	cout << eq(123) << endl;
}
