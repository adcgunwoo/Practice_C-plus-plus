//객체지향 프로그램에서 발생하는 문제
//다이아몬드 문제(상속 받는 모양이 마름모 같이 생겨서)
//다중상속 때문에
//한 클래스가 여러 클래스를 상속받을 때
//가상상속

//다중 상속은 인터페이스로부터만 받는다.
//인터페이스:모든 메서드가 순수 가상함수이고 (비정적)멤버 변수는 없는 클래스
//추상 클래스: 순수 가상 함수가 하나 이상 들어 있는 클래스
//다형적 클래스: 가상 함수가 하나 이상 들어 있는 클래스
#include <iostream>
using namespace std;
class IPerson {//인터페이스라는 것을 나타내주기 위해 'I'
public:
	virtual ~IPerson() {}
	virtual void Eat() = 0;
};
class IStudent : virtual public IPerson {
	virtual void Study() = 0;
};
class Student: public IStudent {
public:
	void Eat() {
		cout << "냠냠..." << endl;
	}
	void Study() {
		cout << "공부한다..." << endl;
	}
	void Work() {
		cout << "일한다..." << endl;
	}
};
class IWorker : virtual public IPerson {
	virtual void Work() = 0;
};
class Researcher : public IStudent, public IWorker {//다중상속
	//여기 들어올 내용은 student와 Worker로 부터 상속을 받았지만
	//Person으로부터 직접적으로 받아옴
public:
	void Eat() {
		cout << "먹는다..." << endl;
	}
	void Study() {
		cout << "공부한다..." << endl;
	}
	void Work() {
		cout << "일한다..." << endl;
	}
};
int main()
{
	Researcher r;
	Student s;
	r.Eat();
	s.Eat();
	//다중상속을 받은 경우는 다형성을 활용할 수 없음
}
