//���� ó��
#include <iostream>
#include <string>
using namespace std;
int fact(int n) {
	if (n < 0) throw to_string(n) + " : �����Դϴ�.";
	//���ܸ� ����, Ÿ���� ����� ����
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
	catch (const string& e) {//���ܸ� ����, throw�� Ÿ���� ���ƾ���
		cout << e << endl;
	} //�̵� ������ �ȵ�
	catch (int e) {
		cout << e << endl;
	}
	  /*
	while (1) {
		try {
			cin >> n >> r;
			cout << comb(n, r) << endl;
		}
		catch (const string& e) {//���ܸ� ����, throw�� Ÿ���� ���ƾ���
			cout << e << endl;
		}
	}*/
	catch (...) { //���� ���ܸ� ��� ���� ���ϸ�, else�� ����
		cout << "�� �� ���� ���� �߻�" << endl;
	}
}