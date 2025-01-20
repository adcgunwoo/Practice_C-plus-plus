//함수 포인터
//함수를 가르키는 포인터
#include <iostream>
using namespace std;
bool compare(int a, int b) {
	return a == b;
	//같으면 참, 다르면 거짓을 리턴
}
int main()
{
	bool (*fp)(int, int);
	int *a[3];
	fp = &compare;
	bool res =(*fp)(2, 3);

	cout << res << endl;
}