//static : ���� <-> ����
#include <iostream>
using namespace std;
//0~1 float R G B �� ����
class color {
public:
	color() :r(0), g(0), b(0) {}
	color(float r, float g, float b) :r(r), g(g), b(b) {}
	float getr() { return r; }
	float getg() { return g; }
	float getb() { return b; }
	
	/*static color mixcolors(color a, color b) {
		return color((a.getr() + b.getr()) / 2, (a.getg() + b.getg()) / 2, (a.getb() + b.getb()) / 2);
	}*/
	static color mixcolors(color a, color b) {
		return color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
	}
	//static�� ���� private�� ���� ��������

private:
	float r, g, b;
};

int main()
{
	color blue(0, 0, 1);
	color red(1, 0, 0);
	color purple = color::mixcolors(blue, red);
	cout << "r = " << purple.getr()<< ", g = " << purple.getg()<< "b = " << purple.getb()<< endl;
	
	return 0;
}