//묵시적(암시적) 형변환 (implicit conversion)
//명시적 형변환 (explicit conversion)
#include <iostream> //이 헤더에도 스트링이 있지만 아래와 차이가
#include <string> //있어서 추가함

using namespace std;
class Item {
public:
	Item(int num) :num(num) { //변환 생성자의 역할도 함
		cout << "Item(int)" << endl;
	}
	Item(string name) : name(name) {
		cout << "Item(string)" << endl;
	}
	Item(int num,string name):num(num),name(name){
		cout << "Item(int, string)" << endl;
	}
	//보통의 연산자 오버로딩은 int operator 이런 형태지만 형변환은 이런 형태이다.
	
	//아래는 int 로의 형변환 연산자 오버로딩
	operator int() const { //값이 변하지 않으므로 const
		return num;
	}
	//string으로의 형변환 연산자 오버로딩
	operator string() const { //to_string 함수는 숫자를 문자로 바꿔줌
		return to_string(num) + " : " + name;
		//string 헤더파일 사용으로 +로 문자열을 붙힐수 있음
	}
	void print() {
		cout << num << " : " << name << endl;
	}
private:
	int num;
	string name;
};
void println(string s) {
	cout << s << endl;
}
void println(int n) {
	cout << n << endl;
}
int main()
{
	Item i1(1);
	Item i2 = Item(2);
	Item i3 = 3;
	i1 = 4; // 묵시적 변환이 호출이 됨
	Item i4 = (Item)4; //명시적 형변환
	
	Item i5(5);
	i5 = (string)"stone";

	Item i6(1, "grass");
	Item i7 = { 2,"dirt" };
	Item i8{ 3,"wood" };

	int itemNum1 = (int)i8; //명시적 형변환
	int itemNum2 = i7; //묵시적 형변환
	cout << itemNum1 << endl;
	cout << itemNum2 << endl;

	println((string)i8); //명시적 형변환
	//println(i8); 묵시적 형변환, 에러 발생 
	println((int)i8); //묵시적 형변환
}
//explicit을 형변환 오버로딩에 붙여서 
//명시적 형변환만 가능하게 함
