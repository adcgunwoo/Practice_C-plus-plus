//static : ���� <-> ����
#include <iostream>
using namespace std;
//0~1 float R G B �� ����

class color {
public:
	color() :r(0), g(0), b(0),id(idcounter++) {	}
	color(float r, float g, float b) :r(r), g(g), b(b), id(idcounter++) {}
	
	float getr() { return r; }
	float getg() { return g; }
	float getb() { return b; }
	
	int getid() { return id; }
	
	static color mixcolors(color a, color b) {
		return color((a.getr() + b.getr()) / 2, (a.getg() + b.getg()) / 2, (a.getb() + b.getb()) / 2);
	}
	static int idcounter;
private:
	float r, g, b;
	
	int id;
};
int color::idcounter = 1;
//Ŭ���� �ȿ��� �������� ����� ���� 
//�ʱⰪ�� ������ ����. ���� �и��ؾ��Ѵ�.
int main()
{
	color blue(0, 0, 1);
	color red(1, 0, 0);
	color purple = color::mixcolors(blue, red);
	cout << "r = " << purple.getr()<< ", g = " << purple.getg()<< ", b = " << purple.getb()<< endl;

	cout << "blue.getid() = " << blue.getid() << endl;
	cout << "red.getid() = " << red.getid() << endl;
	cout << "purple.getid() = " << purple.getid() << endl;
	
	return 0;
}