#include <iostream>
#include <cassert>

int triangular_number_iter(int n)
{
    int sum = 0;
    while(n > 0)
        sum += n--;
    return sum;
}

int triangular_number_recursive(int n)
{
    if(n <= 0) return 0;
    return n + triangular_number_recursive(n-1);
}

int main()
{
    for(int i = 0; i < 20; ++i)
        assert(triangular_number_iter(i) == triangular_number_recursive(i));
    return 0;
}
