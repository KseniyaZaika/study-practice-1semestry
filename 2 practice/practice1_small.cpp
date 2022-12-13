#include <fstream>
#include <iostream>

int main()
{
	char a[1000];
	char b[1000];
	std::ifstream in("input.txt", std::ios::in);
	int a1[1000]{};
	int b1[1000]{};
	int addition[10001]{};
	int multy[10001]{};
	for (int i = 0; i < 1000; i++)
	{
		b[i] = 'g';
		a[i] = 'g';
	}
	in >> a;
	in >> b;

	// считывание в массив цифр int

	int a_ind = 999;
	int b_ind = 999;
	for (int i = 999; i >= 0; i--)
	{
		if (a[i] != 'g') 
		{
			a1[a_ind] = a[i] - '0';
			a_ind -= 1;
		}
		if (b[i] != 'g') 
		{
			b1[b_ind] = b[i] - '0';
			b_ind -= 1;
		}
	}

	// сложение

	int ost = 0;
	bool flag = false;
	for (int i = 998; i >= 0; i--)
	{
		int k = a1[i] + b1[i];
		if (flag)
		{
			k += ost;
			flag = false;
			ost = 0;
		}
		if (k / 10 != 0) 
		{
			ost = k / 10;
			flag = true;
		}
		addition[i + 1] = k % 10;
	}

	// вывод сложения

	if (flag) addition[0] = ost;
	ost = 0;
	bool fl_0 = false;
	for (int i = 0; i < 1000; i++) 
	{
		if (addition[i] != 0) 
		{
			fl_0 = true;
		}
		if (fl_0)
		{
			std::cout << addition[i];
		}
	}

	std::cout << '\n';

	// умножение

	int ind_multy = 10000;
	int ind_curr = 0;
	for (int ib = 998; ib >= 0; ib--) 
	{
		for (int ia = 998; ia >= 0; ia--) 
		{
			multy[ind_multy- ind_curr ] += b1[ib] * a1[ia];
			multy[ind_multy - 1 - ind_curr] += multy[ind_multy- ind_curr] / 10;
			multy[ind_multy - ind_curr] = multy[ind_multy - ind_curr] % 10;
			
			ind_curr += 1;
		}
		ind_curr = 0;
		ind_multy -= 1;
	}

	//вывод умножения

	fl_0 = false;
	for (int i = 0; i < 10001; i++)
	{
		if (multy[i] != 0) 
		{
			fl_0 = true;
		}
		if (fl_0) 
		{
			std::cout << multy[i];
		}
	}	
}