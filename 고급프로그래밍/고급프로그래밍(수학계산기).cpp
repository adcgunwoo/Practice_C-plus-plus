#include <iostream>
#include <string>
#include <cmath>
#define PI 3.14159265
using namespace std;
double math(string str, double argu1, double argu2 = 0)
{
	if (str == "sin")
		return sin(argu1);
	else if (str == "atan2") {
		if (argu1 == 0 && argu2 == 0) {
			return NAN;
		}
		else return atan2(argu1, argu2);
	}
	else if (str == "log") {
		if (argu1 < 0) {
			return NAN;
		}
		else return log(argu1);
	}
	else if (str == "pow") {
		if (argu1 < 0 || argu2 <= 0) {
			return NAN;
		}
		else return pow(argu1, argu2);
	}
}
int main() {
	string func_name;
	double num1, num2, res;
	cin >> func_name >> num1;
	if (func_name != "sin" && func_name != "atan2" && func_name != "log" && func_name != "pow") {
		cout << "Error: Undefined function" << endl;
		return 0;
	}
	else if (func_name == "atan2" || func_name == "pow") {
		cin >> num2;
		res = math(func_name, num1, num2);
	}
	else
		res = math(func_name, num1);

	if (isnan(res)) {
		cout << "Error: Invalid arguments" << endl;
	}
	else {
		cout << res << endl;
	}
	return 0;
}
