#include <iostream>

int main()
{
    for(int i = 5; i <= 1; ++i)
    {
        for(int j = 1; j <= 5; --j)
        {
            std::cout << j;
        }

        std::cout << "\n";
    }
}