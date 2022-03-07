#include <Windows.h>
#include "pyramid.h"
#include "sphere.h"
#include "tetrahedron.h"
#include "parallelepiped.h"

int main()
{
	void creation_objects(shapes**);
	void display_objects(shapes**);
	size_t choice_of_object();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	using std::cout;
	using std::cin;
	using std::endl;
	shapes** mass_objects = nullptr;
	cout << "Введите число объектов\n";
	size_t number = input<size_t>();
	mass_objects = new shapes*[number];
	while (1)
	{
		system("cls");
		cout << "1) Создать новый объект\n"
			<< "2) Расчитать объем всех созданных объектов\n"
			<< "3) Изменить данные об объекте с клавиатуры\n"
			<< "4) Изменить данные объекта из файла\n"
			<< "5) Показать данные всех созданных объектов\n"
			<< "6) Сохранить данные об объекте в файл\n"
			<< "7) Выход из программы\n";
		int answer = input<int>();
		try
		{
			switch (answer)
			{
			case 1:
				system("cls");
				if (shapes::count == number)
					throw std::string("Достигнут предел объектов, больше создать нельзя!\n");
				creation_objects(mass_objects);
				break;
			case 2:
				system("cls");
				if (shapes::count == 0)
					throw std::string("Объекты пока не созданы!\n");
				for (size_t i = 0; i < shapes::count; i++)
				{
					mass_objects[i]->volume();
				}
				system("pause");
				break;
			case 3:
			{
				system("cls");
				display_objects(mass_objects);
				cout << "\nВведите значение какого объекта вы хотите изменить\n";
				size_t id = choice_of_object();
				system("cls");
				mass_objects[id]->set_data();
				system("cls");
				cout << "Данные для объекта были установлены.\n";
				system("pause");
				break;
			}
			case 4:
			{
				system("cls");
				display_objects(mass_objects);
				cout << "\nВведите значение какого объекта вы хотите изменить\n";
				size_t id = choice_of_object();
				system("cls");
				mass_objects[id]->diskIn();
				system("cls");
				cout << "Данные успешно считаны из файла в объект.\n";
				system("pause");
				system("cls");
				break;
			}
			case 5:
				system("cls");
				display_objects(mass_objects);
				system("pause");
				break;
			case 6:
			{
				system("cls");
				display_objects(mass_objects);
				cout << "Введите данные какого объекта хотите сохранить в файл\n";
				size_t id = choice_of_object();
				mass_objects[id]->diskOut();
				system("cls");
				cout << "Данные объекта были успешно записаны в конец файл.\n";
				system("pause");
				system("cls");
				break;
			}
			case 7:
				system("cls");
				cout << "Выход из программы...\n";
				exit(1);
				break;
			default:
				system("cls");
				cout << "Введена неверная цифра, повторите попытку!\n";
				system("pause");
			}
		}
		catch(std::string& ex)
		{
			cout << ex;
			system("pause");
		}
	}
	return 0;
}

size_t choice_of_object()
{
	size_t id;
	while (1)
	{
		id = input<size_t>() - 1;
		if (id < shapes::count && id >= 0)
			break;
		std::cout << "Введеное число меньшее нуля, либо большее чем "
			<< "число созданных объектов. Повторите попытку!\n";
	}
	return id;
}

void display_objects(shapes** mass_objects)
{
	if (shapes::count == 0)
		throw std::string("Объекты пока не созданы!\n");
	for (size_t i = 0; i < shapes::count; i++)
	{
		mass_objects[i]->display_data();
	}
}

void creation_objects(shapes** mass_objects)
{
	system("cls");
	std::cout << "1) Создать объект класса Параллелепипед\n"
		<< "2) Создать объект класса Пирамида\n"
		<< "3) Создать объект класса Тетраэдр\n"
		<< "4) Создать объект класса Шар\n";
	int answer = input<int>();
	static size_t cnt = 0;
	switch (answer)
	{
	case 1:
		system("cls");
		mass_objects[cnt] = new parallelepiped;
		cnt++;
		std::cout << "Создан объект класса параллелепипед.\n";
		system("pause");
		break;
	case 2:
		system("cls");
		mass_objects[cnt] = new pyramid;
		cnt++;
		std::cout << "Создан объект класса пирамида.\n";
		system("pause");
		break;
	case 3:
		system("cls");
		mass_objects[cnt] = new tetrahedron;
		cnt++;
		std::cout << "Создан объект класса тетраэдр.\n";
		system("pause");
		break;
	case 4:
		system("cls");
		mass_objects[cnt] = new sphere;
		cnt++;
		std::cout << "Создан объект класса шар.\n";
		system("pause");
		break;
	default:
		system("cls");
		std::cout << "Введена неверная цифра, повторите попытку!";
		system("pause");
	}
}