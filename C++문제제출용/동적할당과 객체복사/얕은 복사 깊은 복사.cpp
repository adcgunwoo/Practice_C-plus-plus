//객체 동적 할당
#include <iostream>
using namespace std;

int main()
{
	int* a = new int(5);
	int* b = new int(3);

	//a = b;   얕은 복사(참조만 복사)
	*a = *b; //깊은 복사(값을 복사)
	cout << *a;
	delete a;
	delete b;
	
}
