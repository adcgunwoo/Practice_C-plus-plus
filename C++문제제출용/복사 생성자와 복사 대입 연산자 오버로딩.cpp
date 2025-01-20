//char *str="Hello";
//#include <string>
//string s;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class String {
public:
	String() {
		cout << "String() 생성자 호출" << endl;
		strdata = NULL;
		len = 0;
	}
	String (const char *str){ //문자만 받으려면 포인터가 없지만, 문자열을 받으려면 포인터가 있어야 함
		cout << "String(const char *str) 생성자 호출" << endl;
		len = strlen(str);
		strdata = new char[len+1];//맨 끝에 널이 있어서 +1
		cout << "strdata 할당 : " << (void*)strdata << endl;
		strcpy(strdata, str); //깊은 복사
	}
	String(String &rhs) { //복사 생성자
		cout << "String(String &rhs) 생성자 호출" << endl;
		strdata = new char[rhs.len + 1];//맨 끝에 널이 있어서 +1
		cout << "strdata 할당 : " << (void*)strdata << endl;
		strcpy(strdata, rhs.strdata); //깊은 복사
		//strdata = rhs.strdata;  얕은 복사
		len = rhs.len; // 깊은 복사
	}
	~String() {
		cout << "~String() 소멸자 호출" << endl;
		delete []strdata;
		cout << "strdata 해제됨 : " << (void*)strdata << endl;
		strdata = NULL;
	}
	String &operator=(const String &rhs) {//연산자 오버로딩은 왠만하면 레퍼런스 사용
		if (this != &rhs) { //자기자신이 들어올 경우 대비
			delete[]strdata;
			strdata = new char[rhs.len + 1];//맨 끝에 널이 있어서 +1
			cout << "strdata 할당 : " << (void*)strdata << endl;
			strcpy(strdata, rhs.strdata); //깊은 복사
			len = rhs.len; // 깊은 복사
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
	String s1("안녕");
	String s2(s1); //복사 생성자
	String s3("Hello");
	//s3 = s1;
	s3.operator=(s3); //위 구문과 같음

	cout << s1.getstrdata() << endl;
	cout << s2.getstrdata() << endl;
	cout << s3.getstrdata() << endl;
	cout << "메인 함수 종료" << endl;
}
