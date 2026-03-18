#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    double sum = 0.0;

    for(int i = 0; i < n; i++)
    {
        double term = 1.0 / (2 * i + 1);

        if(i % 2 == 0)
            sum += term;

        else

            sum -= term;
    }
        double pi = 4 * sum;
        std::cout << "파이 근사값 : ";
        std::cout << pi;
}