#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	//C++������ �迭�� ���°� �ƴѵ� ����
	cout << "�̸� �Է� ";
	cin >> str;
	string message="�ȳ��ϼ���, "+str+" ��";
	//C������ string.h ��� ���鼭 �ؾߵ�����
	//C++������ '+' �� ����
	cout << message << endl;
	return 0;
}