#include <iostream>
namespace a
{
	int n;
}
namespace b
{
	int n;
}
int main()
{
	a::n = 10;
	b::n = 20;//���� n������ ���� �ٸ�
	//name space
	//�̸�:cout, ��:std
	std::cout << "Hello World!" << std::endl;
	//'<<'�� �帧, ���߿� �� ����
	int c;
	std::cin >> c;//�ڷ����� C++�� �˾Ƽ� ���༭ �ؼ�
	std::cout << c<<std::endl;

	return 0;
}