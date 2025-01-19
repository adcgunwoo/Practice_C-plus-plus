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
	b::n = 20;//같은 n이지만 값이 다름
	//name space
	//이름:cout, 성:std
	std::cout << "Hello World!" << std::endl;
	//'<<'는 흐름, 나중에 더 설명
	int c;
	std::cin >> c;//자료형을 C++이 알아서 해줘서 해석
	std::cout << c<<std::endl;

	return 0;
}