#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	//C++에서는 배열의 형태가 아닌데 가능
	cout << "이름 입력 ";
	cin >> str;
	string message="안녕하세요, "+str+" 님";
	//C언어에서는 string.h 헤더 쓰면서 해야되지만
	//C++에서는 '+' 로 가능
	cout << message << endl;
	return 0;
}