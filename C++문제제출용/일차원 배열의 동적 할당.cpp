#include <iostream>
using namespace std;
int main()
{
	int *arr;
	int len;

	cout << "�����Ҵ� �迭 ���� : ";
	cin >> len;
	arr = new int[len];
	for (int i = 0; i < len; i++) {
		arr[i] = len - i;
	}
	for (int i = 0; i < len; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	} //�� �ݺ��� ��°� ������ ����� ������ �� �� ����
	delete[]arr;
}