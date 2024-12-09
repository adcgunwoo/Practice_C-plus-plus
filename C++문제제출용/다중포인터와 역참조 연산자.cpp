#include <iostream>
#include <bitset>
int main()
{
    int a = 123;
    int* pt_a = &a;
    int** pt_pt_a = &pt_a;
    int*** pt_pt_pt_a = &pt_pt_a;

    std::cout << *pt_a <<" "<< **pt_pt_a<<" "<< ***pt_pt_pt_a;
    //역참조 연산자는 그 횟수만큼 *를 붙여야 값에 접근 가능
    return 0;
}