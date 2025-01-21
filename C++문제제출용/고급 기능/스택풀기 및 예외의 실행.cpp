#include <iostream>
void func_throw()
{
    std::cout << "func_throw()" << std::endl;
    std::cout << "throw -1" << std::endl;
    throw - 1;
    std::cout << "throw -1" << std::endl;
}
int main()
{
    try {
        func_throw();
    }
    catch (int exec)
    {
        std::cout << "catch " << exec << std::endl;
    }
    return 0;
}
