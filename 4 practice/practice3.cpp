/*Порядок выполнения:
1.	Определите минимальное количество бит на число.
Если получается так, что в 1 байт вы можете записать 2.5 числа,
например, то задействуйте 2 байта.
2.	Разработайте операции добавления и извлечения чисел.
*/
// 0 ~~~~ 34
// 1 byte = 8 bit

#include <iostream>
int data_size(int x)
{
    for (int i = 1; i < 7; i++)
    {
        if (pow(2, i) < x)
        {
            continue;
        }
        else
        {
            return i;
        }
    }
}

int main()
{
    int num[6] = { 13, 17, 24, 34 ,0 , 1 };
    unsigned int k = 0;
    for (int i = 0; i < std::size(num); i++)
    {       
        k = k | num[i];
        
        if (i < (std::size(num) - 1))
        {
            k = k << data_size(num[i + 1]);
        }
    }
    for (int i = (std::size(num) - 1); i >= 0; i--)
    {
        int cur = ((k << (32 - data_size(num[i]))) >> (32 - data_size(num[i])));
        k = k >> data_size(num[i]);
        std::cout << cur << ' ';
    }
}

