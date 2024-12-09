#include <iostream>
int main()
{
	char i;
	for (i = 32; i <= 126; i++) {
		std::cout << i << ((i % 16 == 15) ? '\n' : ' ');
	}
	return 0;
}