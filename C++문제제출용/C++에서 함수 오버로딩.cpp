#include <iostream>
//C++의 함수
//over load(오버로드) 다중정의?
//using namespace std;
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void swap(double& a, double& b)
{
	double tmp = a;
	a = b;
	b = tmp;
}
void swap(int *(&a), int *(&b))
{
	int *tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a(20), b(10);
	swap(a, b);
	double da(2.2), db(3.3);
	//swap(da, db); 타입이 안 맞아서 에러가 남
	swap(da, db);
	int *pa(&a), *pb(&b);
	swap(pa, pb); 
	//같은 swap인데 타입을 구분해줌
	//컴파일러가 자동으로 같은 자료형을 찾아
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "da = " << da << std::endl;
	std::cout << "db = " << db << std::endl;
	std::cout << "*pa = " << *pa << std::endl;
	std::cout << "*pb = " << *pb << std::endl;

	return 0;
}