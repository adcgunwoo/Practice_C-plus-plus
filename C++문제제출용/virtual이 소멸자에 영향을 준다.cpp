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
		ice = new Ice; //���⼭ ȣ���
	}
	virtual ~Bingsoo() { 
		cout << "~Bingsoo()" << endl; 
		delete ice;
	}
private:
	Ice *ice;
	//������ ȣ���� �ȵ�
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
	//�θ�Ŭ������ �����Ͱ� 
	//�ڽ�Ŭ������ ��ü�� ����Ű�� ��Ȳ

	//Bingsoo �Ҹ��ڿ� virtual�� �߰��ߴ���
	//Patbingsoo �Ҹ��ڸ� ȣ���ߴ�.
	//C++�� �⺻������ �������ε��̶� virtual�� ������
	//p�� Bingsoo�� ����Ű�� �־�
	//������� PatBingsoo �Ҹ��ڸ� ȣ������ ����
	

	delete p;
}