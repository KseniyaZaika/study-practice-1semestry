/*
Изучите основные операции над вектором и продемонстрируйте их работу:

1.	push_back, erase, insert
2.	emplace_back
3.	resize, reserve, shrink_to_fit, capacity
4.	clear
5.	оператор присваивания и []

Узнайте размер вектора и будьте готовы объяснить, почему именно так.

*/
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

int main()
{
	std::vector<short> practice_short;//создание пустого вектора
	std::vector<int> practice_int; 


	std::cout << sizeof(practice_short) << ' ' << sizeof(practice_int) << std::endl;
	std::cout << size(practice_short) << " " << size(practice_int) << std::endl;

	practice_int.push_back(123);
	practice_int.push_back(554);

	practice_short.push_back(2);
	practice_short.push_back(3);

	std::cout << sizeof(practice_short) << ' ' << sizeof(practice_int) << std::endl;
	std::cout << size(practice_short) << " " << size(practice_int) << std::endl;
	//sizeof: 4(3?) ссылки ( 1 элемент, последний, capacity, Allocator)



	/// emplace_back()

	practice_int.emplace_back(1);
	std::cout << "emplace_back" << std::endl;
	for (int i = 0; i < size(practice_int); i++)
	{
		std::cout << practice_int[i] << ' ';
		//emplace_back создает новый объект и добавляет его  в конец вектора
		//push_back помещает элемент в конец вектора копируя его
	}
	std::cout << '\n';


	
	for (int i = 0; i < 10; i++)
	{
		practice_int.push_back(i);
	}
	std::cout << "push_back" << std::endl;
	for (int i = 0; i < size(practice_int); i++)
	{
		std::cout << practice_int[i] << ' ';
	}
	std::cout << '\n';
	practice_int.erase(practice_int.begin() + 2); 
	// begin() возвращает итератор на 0 элемент
	// erase(p): удаляет элемент, на который указывает итератор p.
	//Возвращает итератор на элемент, следующий после удаленного,
	//	или на конец контейнера, если удален последний элемент
	std::cout << "enrase for 1 elem" << std::endl;
	for (int i = 0; i < size(practice_int); i++)
	{
		std::cout << practice_int[i] << ' ';
		
	}

	std::cout << '\n';
	std::cout << "enrase for sequence" << std::endl;
	practice_int.erase(practice_int.begin() + 3, practice_int.begin() + 6);
	//  erase(begin, end) : удаляет элементы из диапазона, на начало
	//	и конец которого указывают итераторы begin и end(end не включительно).
	//	Возвращает итератор на элемент, следующий после последнего
	//  удаленного,
	//	или на конец контейнера, если удален последний элемент
	for (int i = 0; i < size(practice_int); i++)
	{
		std::cout << practice_int[i] << ' ';
	}

	//insert() добавляет значение на место указываемое итератором
	practice_int.insert(practice_int.begin(), 999);
	practice_int.insert(practice_int.begin()+1, 888);
	std::cout << '\n'<<"insert" << std::endl;
	for (int i = 0; i < size(practice_int); i++)
	{
		std::cout << practice_int[i] << ' ';
	}

	//resize() приводит длинну вектора к указанной в аргументе
	// если указан второй аргумент,
	//то resize добавляет это значение в конец векторастолько раз, на сколько происходит увеличение
	std::cout << '\n' << "resize -" << std::endl;
	practice_int.resize(8);
	for (int i = 0; i < size(practice_int); i++)
	{
		std::cout << practice_int[i] << ' ';
	}

	std::cout << '\n' << "resize + addition" << std::endl;
	practice_int.resize(10, 444);
	for (int i = 0; i < size(practice_int); i++)
	{
		std::cout << practice_int[i] << ' ';
	}

	//capacity() возвращает количество элементов, выделенное для массива
	// когда количество элепентов равно capacity, то происодит перераспределение памяти
	// capacity увеличивается в 2 раза
	std::cout << '\n' << "capasity: "<< practice_int.capacity() << std::endl;


	//reserve презервирует память для элементов массива(она будет возвращаться capacity())
	std::cout << '\n' << "reserve" << std::endl;
	practice_int.reserve(100);
	std::cout << "capasity now: " << practice_int.capacity() << std::endl;
	for (int i = 0; i < size(practice_int); i++)
	{
		std::cout << practice_int[i] << ' ';
	}

	//srint_to_fit уменьшает размер выделенной памяти до минимально возможного значения,
	//т.е. при вызове методы size() и capacity() вернут одинаковые значения
	practice_int.shrink_to_fit();
	std::cout << '\n' << "shrink_to_fit->capacity = "<< practice_int.capacity()  << " size = " << size(practice_int) << std::endl;

	
	//[index] возвращает элемент по индексу или осуществляет доступ к нему
	// = можно присвоить какое либо значение элементу 
	std::cout << '\n' << "[index(3)]: "<< practice_int[3] << std::endl;
	std::cout << '\n' << "=" << std::endl;
	practice_int[3] = 66666;
	std::cout << "[index(3)] now : " << practice_int[3] << std::endl;
	
	//clear удаляет каждый элемент вектора, не освобождая основное хранилище
	practice_int.clear();
	std::cout << "size after clear: " << size(practice_int) << std::endl;
	std::cout << "capasity after clear: " << practice_int.capacity() << std::endl;

	//т.к. capacity не изменяется после clear, то рекомендуется использовать после shrink_to_fit()

	practice_int.shrink_to_fit();
	std::cout << "capacity: " << practice_int.capacity() << std::endl;

	std::string s;
	std::cout << sizeof(s);
	return 0;
}

