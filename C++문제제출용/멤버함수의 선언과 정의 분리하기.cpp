//����+������ �����ε�
//��� �޼����� ����� ���� �и��ϱ�
//����� ���Ǹ� �и��ϴ� ����
//�Լ��� ������ �ʿ��ϰ� ȣ���Ҷ�
//�̸� ���ǵ��� ������ ���� ������� ���� �Լ� ȣ�� �Ұ���
/*
void a(); 
void b();
void c();  ���� ����
void a() {
	c();   �׸��� ����
}*/ 
#include <iostream>
using namespace std;
class vector2 {
public:
	vector2(); //������ ����
	vector2(float x, float y);//������ ����
	float getx() const; //����� �޼���� �̷��� �ۼ�
	float gety() const;
	static vector2 sum(vector2 a, vector2 b) {
		//return vector2(a.getx() + b.getx(), a.gety()+b.gety());
		  return vector2(a.x + b.x, a.y + b.y);
	}   //�����Լ��� ������ ���� �ʴ°� ���� ������ static���� �鿩����
        //private�� ���� �� �� �ֱ⿡ �Լ� ȣ������ �ʰ� �ۼ�����
	vector2 add(vector2 rhs) {
		return vector2(x + rhs.x, y+rhs.y);
	}//����ƽ�� ����������, �� �޼���� �����̴�
	 //������ ���� Ŭ������ �������� ��ü�� ���Ե� ���� �ƴϾ
	 //�� ���� ���Ѵٸ� �� ���� �Ű������� �ʿ�������
	 //������ ��ü�� �Ʒ� ��ü ������ ���� ���ԵǾ� �־ �ϳ��� �޾Ƶ� �ȴ�.
private:
	float x, y;
};

int main()
{
	vector2 a(2, 3);
	vector2 b(-1, 4);
	//vector2 c = a + b; ��ǻ�ʹ� ���� ������ ���� �̷� ����� ����
	vector2 c1 = vector2::sum(a, b); //����ƽ���� �Լ��� �鿴�⿡ ���ӽ����̽��� �ٿ���
	vector2 c2 = a.add(b);

	cout << a.getx() << ", " << a.gety() << endl;
	cout << b.getx() << ", " << b.gety() << endl;
	cout << c1.getx() << ", " << c1.gety() << endl;
	cout << c2.getx() << ", " << c2.gety() << endl;

	return 0;
}
vector2::vector2():x(0),y(0){} 
//������ ����, ���ӽ����̽� �� �ۼ�
vector2::vector2(float x, float y):x(x),y(y){}
//������ ����, ���ӽ����̽� �� �ۼ�
float vector2::getx() const { return x; }
float vector2::gety() const { return y; }