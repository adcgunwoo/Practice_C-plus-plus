#include <iostream>
int main()
{
    try
    {
        int input;
        std::cout << "정수 중 하나를 입력하세요. : ";
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
    catch (...) { //정수 이외에 예외들은 여기서 처리
        std::cout << "catch all" << std::endl;
    }

    return 0;
}