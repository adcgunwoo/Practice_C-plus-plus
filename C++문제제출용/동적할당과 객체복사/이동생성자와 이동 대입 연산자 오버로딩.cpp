#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class String {
public:
	String() {
		cout << "String() : " << this << endl;
		strData = NULL;
		len = 0;
	}
	String(const char* str) {
		cout << "String(const char*) : " << this << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
	String(const String& rhs) { //복사 생성자
		cout << "String(const String&) : " << this << endl;
		len = rhs.len;
		alloc(len);
		strcpy(strData, rhs.strData);
	}
	String(String&& rhs) { //이동생성자, &&은 r-value 참조  
		cout << "String(String&&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData;
		rhs.strData = NULL;
	}
	~String() {
		cout << "~String() : " << this << endl;
		release();
		strData = NULL;
	}
	String& operator=(const String& rhs) { //복사 대입 연산자
		cout << "String &operator=(const String&) : " << this << endl;
		if (this != &rhs) {
			release();
			len = rhs.len;
			alloc(len);
			strcpy(strData, rhs.strData);
		}
		return *this;
	}
	String& operator=(String&& rhs) {
		cout << "String &operator=(String&&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData;
		rhs.strData = NULL;
		return *this;
	}
	char* GetStrData() const {
		return strData;
	}
	int GetLen() const {
		return len;
	}
	void SetStrData(const char* str) {
		cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
private:
	void alloc(int len) {
		strData = new char[len + 1];
		cout << "strData allocated : " << (void*)strData << endl;
	}
	void release() {
		delete[] strData;
		if (strData) cout << "strData released : " << (void*)strData << endl;
	}
	char* strData;
	int len;
};
String getName() {
	cout << "===== 2 =====" << endl;
	String res("Doodle");
	cout << "===== 3 =====" << endl;
	return res;
}
int main() {
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;
	
	//r-value 등호의 우변에만 올수 있는 값, 임시객체는 r-value!
	//l-value 좌우변 둘다 가능
}
