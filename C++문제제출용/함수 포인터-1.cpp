//�Լ� ������
//�Լ��� ����Ű�� ������
#include <iostream>
using namespace std;
bool compare(int a, int b) {
	return a == b;
	//������ ��, �ٸ��� ������ ����
}
int main()
{
	bool (*fp)(int, int);
	int *a[3];
	fp = &compare;
	bool res =(*fp)(2, 3);

	cout << res << endl;
}