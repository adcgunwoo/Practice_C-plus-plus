#include <iostream>
int main()
{
    try
    {
        int input;
        std::cout << "���� �� �ϳ��� �Է��ϼ���. : ";
        std::cin >> input;
        if (input > 0) {
            std::cout << "throw 1" << std::endl;
            throw 1;
            std::cout << "after throw 1" << std::endl;
        }
        if (input < 0) {
            std::cout << "throw -1.0f" << std::endl;
            throw - 1.0f;
            std::cout << "after throw 1" << std::endl;
        }
        if (input == 0) {
            std::cout << "throw Z" << std::endl;
            throw 'Z';
            std::cout << "after throw Z" << std::endl;
        }
    }
    catch (int a) {
        std::cout << "catch " << a << std::endl;
    }
    catch (...) { //���� �̿ܿ� ���ܵ��� ���⼭ ó��
        std::cout << "catch all" << std::endl;
    }

    return 0;
}