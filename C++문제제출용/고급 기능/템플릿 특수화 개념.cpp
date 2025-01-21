//템플릿 특수화

#include <iostream>
#include <string>

using namespace std;

template <typename T>
T getArraySum(const T arr[], int n)
{
	cout << "템플릿" << endl;
	T sum = arr[0];
	for (int i = 1; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

template<>//템플릿 특수화, string일때
string getArraySum<string>(const string arr[], int n) {
	cout << "특수화" << endl;
	string sum = arr[0];
	for (int i = 1; i < n; i++) {
		sum += ' ' + arr[i];//공백 넣기
	}
	return sum;
}
int main()
{
	string sarr[3] = { "Hello","world","doodle" };
	string ssum = getArraySum(sarr, 3);
	cout << ssum << endl;
	int iarr[5] = { 3,1,4,1,5 };
	int isum = getArraySum(iarr, 5);
	
	cout << isum << endl;
}
