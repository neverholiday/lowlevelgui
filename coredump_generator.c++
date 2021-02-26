#include <iostream>


void func( int *a )
{
    int test = 2;
    a = &test;
}

int main()
{

    int *x_ptr = nullptr;

    func( x_ptr );

    std::cout << "x_ptr = " << *x_ptr << std::endl;

    return 0;
}