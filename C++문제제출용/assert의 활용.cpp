#include <iostream>
#include <cassert>
void print_number(int* n)
{
    assert(n != NULL);
    std::cout << *n << std::endl; //
}
int main() 
{
    int a = 100;
    int* b = NULL;
    int* c = NULL;

    b = &a;
    print_number(b);

    return 0;
}