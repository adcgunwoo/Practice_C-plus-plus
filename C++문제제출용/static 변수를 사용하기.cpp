#include <iostream>
void func()
{
    int a = 1;
    int static b = 1;
    a++;
    b++;
    std::cout << "a = " << a << " " << "b = " << b << std::endl;
}
int main()
{
    func();
    func();
    func();
    func();
    func();

    return 0;
}