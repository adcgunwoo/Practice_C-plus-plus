#include <iostream>
#include <bitset>
int main()
{
    int a = 123;
    int* pt_a = &a;
    int** pt_pt_a = &pt_a;
    int*** pt_pt_pt_a = &pt_pt_a;

    std::cout << *pt_a <<" "<< **pt_pt_a<<" "<< ***pt_pt_pt_a;
    //������ �����ڴ� �� Ƚ����ŭ *�� �ٿ��� ���� ���� ����
    return 0;
}