#include <iostream>
using namespace std;
int main()
{
	int *arr;
	int len;

	cout << "동적할당 배열 길이 : ";
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
	} //위 반복문 출력과 동일한 결과가 나옴을 알 수 있음
	delete[]arr;
}
