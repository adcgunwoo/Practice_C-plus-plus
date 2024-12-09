#include <iostream>
int A=3; //전역 변수, 전 함수의 영향을 끼침
int main()
{
	int B = 1; //지역 변수, 함수의 범위 내에서
	double c = 1.2;
	B = int(c);//명시적 변환, 실수형에서 정수형으로 C언어에서 주로 쓰던 방법
	c = A;//암시적 변환, 정수에서 실수로 컴파일러가 필요에 따라 자동으로 수행
	return 0;
}