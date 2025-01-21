#include <iostream>
using namespace std;
class Ice {
public:
	Ice() { cout << "Ice()" << endl; }
	~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
public:
	Pat() { cout << "Pat()" << endl; }
	~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
public:
	Bingsoo() { 
		cout << "Bigsoo()" << endl;
		ice = new Ice; //여기서 호출됨
	}
	virtual ~Bingsoo() { 
		cout << "~Bingsoo()" << endl; 
		delete ice;
	}
private:
	Ice *ice;
	//생성자 호출은 안됨
};

class PatBingsoo : public Bingsoo {
public:
	PatBingsoo() { 
		cout << "PatBingsoo()" << endl;
		pat = new Pat;
	}
	~PatBingsoo() { 
		cout << "~PatBingsoo()" << endl; 
		delete pat;
	}
private:
	Pat *pat;
};

int main()
{
	Bingsoo* p = new PatBingsoo;
	//부모클래스의 포인터가 
	//자식클래스의 객체를 가르키는 상황

	//Bingsoo 소멸자에 virtual을 추가했더니
	//Patbingsoo 소멸자를 호출했다.
	//C++은 기본적으로 정적바인딩이라 virtual이 없으면
	//p는 Bingsoo를 가르키고 있어
	//원래라면 PatBingsoo 소멸자를 호출하지 못함
	

	delete p;
}
