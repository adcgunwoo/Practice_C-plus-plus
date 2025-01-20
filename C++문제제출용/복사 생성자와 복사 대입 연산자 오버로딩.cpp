//char *str="Hello";
//#include <string>
//string s;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class String {
public:
	String() {
		cout << "String() ������ ȣ��" << endl;
		strdata = NULL;
		len = 0;
	}
	String (const char *str){ //���ڸ� �������� �����Ͱ� ������, ���ڿ��� �������� �����Ͱ� �־�� ��
		cout << "String(const char *str) ������ ȣ��" << endl;
		len = strlen(str);
		strdata = new char[len+1];//�� ���� ���� �־ +1
		cout << "strdata �Ҵ� : " << (void*)strdata << endl;
		strcpy(strdata, str); //���� ����
	}
	String(String &rhs) { //���� ������
		cout << "String(String &rhs) ������ ȣ��" << endl;
		strdata = new char[rhs.len + 1];//�� ���� ���� �־ +1
		cout << "strdata �Ҵ� : " << (void*)strdata << endl;
		strcpy(strdata, rhs.strdata); //���� ����
		//strdata = rhs.strdata;  ���� ����
		len = rhs.len; // ���� ����
	}
	~String() {
		cout << "~String() �Ҹ��� ȣ��" << endl;
		delete []strdata;
		cout << "strdata ������ : " << (void*)strdata << endl;
		strdata = NULL;
	}
	String &operator=(const String &rhs) {//������ �����ε��� �ظ��ϸ� ���۷��� ���
		if (this != &rhs) { //�ڱ��ڽ��� ���� ��� ���
			delete[]strdata;
			strdata = new char[rhs.len + 1];//�� ���� ���� �־ +1
			cout << "strdata �Ҵ� : " << (void*)strdata << endl;
			strcpy(strdata, rhs.strdata); //���� ����
			len = rhs.len; // ���� ����
		}
		return *this;
	}
	char *getstrdata() const {
		return strdata;
	}
	int getlen() const {
		return len;
	}
private:
	char *strdata;
	int len;
};
int main()
{
	String s1("�ȳ�");
	String s2(s1); //���� ������
	String s3("Hello");
	//s3 = s1;
	s3.operator=(s3); //�� ������ ����

	cout << s1.getstrdata() << endl;
	cout << s2.getstrdata() << endl;
	cout << s3.getstrdata() << endl;
	cout << "���� �Լ� ����" << endl;
}
