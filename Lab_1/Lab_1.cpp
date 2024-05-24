// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <conio.h> 
#include <iostream>
#include "Header.h"
#include <fstream>

using namespace std;


void printmenu()
{
	cout << "Меню:" << endl;
	cout << "Выберете 1, чтобы начать" << endl;
	cout << "Выберете 0, чтобы выйти" << endl;
}

bool result_1(float& radius, float &x, float &y)
{
	bool res;
	if (x * x + y * y < radius * radius)
	{
		res = true;
	}
	else
	{
		res = false;
	}
	string path = "data.txt";
	ofstream out_file;
	out_file.open(path);
	if (!out_file.is_open())
	{
		cout << "Не записалось!";
	}
	else
	{
		out_file << "Результаты, если 1 то попал, если 0 то промах" << endl;
		out_file << "RESULT=" << res << endl;
	}
	out_file.close();

	return res;

	/*out_file << "RESULT=" << res << endl;
	out_file.close();*/
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool result;
	int menu_num = 0;
	printmenu();
	float x, y;
	int counter = 0;
	cin >> menu_num;
	while (menu_num != 0)
	{
		counter = 0;
		system("cls");
		printmenu();
		float lenght_sqrt = 0;
		if (menu_num == 1)
		{
			while (lenght_sqrt <= 0)
			{
				system("cls");
				if (counter > 0)
				{
					cout << "Введите кооректно число больше 0" << endl;
				}
				cout << "Данная программа позволяет проверить попадание точки в область, а именно окружности!" << endl;
				cout << "Введите радиус окружности:" << endl;
				cin >> lenght_sqrt;
				if (lenght_sqrt > 0)
				{
					cout << "Введите декартовы координаты, x и y" << endl;
					cin >> x >> y;
					result = result_1(lenght_sqrt, x, y);
					(result == 1) ? (cout << "Попал" << endl) : (cout << "Промах" << endl);
				}
				else
				{
					counter = 1;
					
				}
			}
			cout << "Программа завршила свое действие выберете, действие" << endl;
			printmenu();
		}
		else if (menu_num != 0)
		{
			system("cls");
			cout << "Неверно выбрано число! Выберте число 1 или 0" << endl;
			printmenu();

		}
		cin >> menu_num;
	}
	cout << "Bye Bye!GLHF!" << endl;
}

	