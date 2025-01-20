//예외 처리
#include <iostream>
#include <string>
using namespace std;
int fact(int n) {
	if (n < 0) throw to_string(n) + " : 음수입니다.";
	//예외를 던짐, 타입은 상관이 없음
	if (n == 1) return 1;
	return n * fact(n - 1);
}
int comb(int n, int r)
{
	int a = fact(n);
	int b = fact(r);
	int c = fact(n - r);
	return a / b / c;
}

int main()
{
	int n, r;
	try {
		throw 12.3;
		while (1) {
			cin >> n >> r;
			cout << comb(n, r) << endl;
		}
	}
	catch (const string& e) {//예외를 받음, throw와 타입이 같아야함
		cout << e << endl;
	} //이동 생성은 안됨
	catch (int e) {
		cout << e << endl;
	}
	  /*
	while (1) {
		try {
			cin >> n >> r;
			cout << comb(n, r) << endl;
		}
		catch (const string& e) {//예외를 받음, throw와 타입이 같아야함
			cout << e << endl;
		}
	}*/
	catch (...) { //위의 예외를 모두 받지 못하면, else이 역할
		cout << "알 수 없는 예외 발생" << endl;
	}
}