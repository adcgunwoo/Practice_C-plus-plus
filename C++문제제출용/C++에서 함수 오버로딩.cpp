#include <iostream>
//C++�� �Լ�
//over load(�����ε�) ��������?
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
	//swap(da, db); Ÿ���� �� �¾Ƽ� ������ ��
	swap(da, db);
	int *pa(&a), *pb(&b);
	swap(pa, pb); 
	//���� swap�ε� Ÿ���� ��������
	//�����Ϸ��� �ڵ����� ���� �ڷ����� ã��
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "da = " << da << std::endl;
	std::cout << "db = " << db << std::endl;
	std::cout << "*pa = " << *pa << std::endl;
	std::cout << "*pb = " << *pb << std::endl;

	return 0;
}