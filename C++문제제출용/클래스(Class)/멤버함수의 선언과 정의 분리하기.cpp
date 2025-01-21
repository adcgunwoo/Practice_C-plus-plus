//벡터+연산자 오버로딩
//멤버 메서드의 선언과 정의 분리하기
//선언과 정의를 분리하는 이유
//함수가 여러개 필요하고 호출할때
//미리 정의되지 않으면 아직 선언되지 않은 함수 호출 불가능
/*
void a(); 
void b();
void c();  선언 먼저
void a() {
	c();   그리고 정의
}*/ 
#include <iostream>
using namespace std;
class vector2 {
public:
	vector2(); //생성자 선언
	vector2(float x, float y);//생성자 선언
	float getx() const; //상수형 메서드는 이렇게 작성
	float gety() const;
	static vector2 sum(vector2 a, vector2 b) {
		//return vector2(a.getx() + b.getx(), a.gety()+b.gety());
		  return vector2(a.x + b.x, a.y + b.y);
	}   //전역함수는 가능한 쓰지 않는게 좋기 때문에 static으로 들여오고
        //private에 접근 할 수 있기에 함수 호출하지 않고 작성가능
	vector2 add(vector2 rhs) {
		return vector2(x + rhs.x, y+rhs.y);
	}//스태틱은 정적이지만, 이 메서드는 동적이다
	 //정적인 것은 클래스에 속하지만 객체에 포함된 것은 아니어서
	 //두 개를 더한다면 두 개의 매개변수가 필요하지만
	 //동적은 객체에 아래 객체 생성과 같이 포함되어 있어서 하나만 받아도 된다.
private:
	float x, y;
};

int main()
{
	vector2 a(2, 3);
	vector2 b(-1, 4);
	//vector2 c = a + b; 컴퓨터는 벡터 계산법을 몰라서 이런 방식은 오류
	vector2 c1 = vector2::sum(a, b); //스태틱으로 함수를 들였기에 네임스페이스를 붙여줌
	vector2 c2 = a.add(b);

	cout << a.getx() << ", " << a.gety() << endl;
	cout << b.getx() << ", " << b.gety() << endl;
	cout << c1.getx() << ", " << c1.gety() << endl;
	cout << c2.getx() << ", " << c2.gety() << endl;

	return 0;
}
vector2::vector2():x(0),y(0){} 
//생성자 정의, 네임스페이스 꼭 작성
vector2::vector2(float x, float y):x(x),y(y){}
//생성자 정의, 네임스페이스 꼭 작성
float vector2::getx() const { return x; }
float vector2::gety() const { return y; }
