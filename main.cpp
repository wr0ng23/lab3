#include <Windows.h>
#include "pyramid.h"
#include "sphere.h"
#include "tetrahedron.h"
#include "parallelepiped.h"

int main()
{
	void creation_objects(shapes**, size_t);
	void display_objects(shapes**, size_t);
	size_t choice_of_object(shapes**, size_t);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	using std::cout;
	using std::cin;
	using std::endl;

	shapes** mass_objects = nullptr;
	cout << "������� ����� ��������\n";
	size_t number = input<size_t>();
	mass_objects = new shapes * [number] {};

	while (1)
	{
		system("cls");
		cout << "1) ������� ����� ������\n"
			<< "2) �������� ������ ���� ��������� ��������\n"
			<< "3) �������� ������ �� ������� � ����������\n"
			<< "4) �������� ������ ������� �� �����\n"
			<< "5) ��������� ����� ���� ��������� ��������\n"
			<< "6) ��������� ������ �� ������� � ����\n"
			<< "7) ������� ������\n"
			<< "8) ����� �� ���������\n";
		int answer = input<int>();
		try
		{
			switch (answer)
			{
			case 1:
				system("cls");
				if (shapes::count == number)
					throw std::string("��������� ������ ��������, ������ ������� ������!\n");
				creation_objects(mass_objects, number);
				break;
			case 2:
				system("cls");
				display_objects(mass_objects, number);
				system("pause");
				break;
			case 3:
			{
				system("cls");
				display_objects(mass_objects, number);
				cout << "\n������� �������� ������ ������� �� ������ ��������\n";
				size_t id = choice_of_object(mass_objects, number);
				system("cls");
				mass_objects[id]->set_data();
				system("cls");
				cout << "������ ��� ������� ���� �����������.\n\n";
				system("pause");
				break;
			}
			case 4:
			{
				system("cls");
				display_objects(mass_objects, number);
				cout << "\n������� �������� ������ ������� �� ������ ��������\n";
				size_t id = choice_of_object(mass_objects, number);
				system("cls");
				mass_objects[id]->diskIn();
				system("cls");
				cout << "������ ������� ������� �� ����� � ������.\n\n";
				system("pause");
				break;
			}
			case 5:
				system("cls");
				if (shapes::count == 0)
					throw std::string("������� ���� �� �������!\n");
				for (size_t i = 0; i < number; i++)
				{
					if (mass_objects[i] != nullptr)
					{
						cout << i + 1 << ") ";
						mass_objects[i]->volume();
					}
				}
				system("pause");
				break;
			case 6:
			{
				system("cls");
				display_objects(mass_objects, number);
				cout << "������� ������ ������ ������� �� ������ ��������� � ����\n";
				size_t id = choice_of_object(mass_objects, number);
				mass_objects[id]->diskOut();
				system("cls");
				cout << "������ ������� ���� ������� �������� � ����� �����.\n\n";
				system("pause");
				system("cls");
				break;
			}
			case 7:
			{
				system("cls");
				display_objects(mass_objects, number);
				cout << "������� ����� ������ �� ������ �������\n";
				size_t id = choice_of_object(mass_objects, number);
				delete mass_objects[id];
				mass_objects[id] = nullptr;
				system("cls");
				cout << "������ ������� ������.\n\n";
				system("pause");
				system("cls");
				break;
			}
			case 8:
				system("cls");
				cout << "����� �� ���������...\n";
				for (size_t i = 0; i < number; i++)
				{
					delete mass_objects[i];
				}
				delete[] mass_objects;
				exit(1);
				break;
			default:
				system("cls");
				cout << "������� �������� �����, ��������� �������!\n";
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

size_t choice_of_object(shapes** mass_objects, size_t number)
{
	size_t id;
	while (1)
	{
		id = input<size_t>() - 1;
		if (mass_objects[id] != nullptr && id >= 0 && id < number)
			break;
		std::cout << "������� � ����� ������� ������ � ��������� ���. "
			<< "��������� ������� �����!\n";
	}
	return id;
}

void display_objects(shapes** mass_objects, size_t number)
{
	if (shapes::count == 0)
		throw std::string("������� ���� �� �������!\n");
	for (size_t i = 0; i < number; i++)
	{
		if (mass_objects[i] != nullptr)
		{
			std::cout << i + 1 << ") ";
			mass_objects[i]->display_data();
		}
	}
}

void creation_objects(shapes** mass_objects, size_t number)
{
	system("cls");
	std::cout << "1) ������� ������ ������ ��������������\n"
		<< "2) ������� ������ ������ ��������\n"
		<< "3) ������� ������ ������ ��������\n"
		<< "4) ������� ������ ������ ���\n";
	int answer = input<int>();
	size_t cnt = 0;
	for (size_t i = 0; i < number; i++)
	{
		if (mass_objects[i] == nullptr)
		{
			cnt = i;
			break;
		}
	}
	switch (answer)
	{
	case 1:
		system("cls");
		mass_objects[cnt] = new parallelepiped;
		std::cout << "������ ������ ������ ��������������.\n\n";
		system("pause");
		break;
	case 2:
		system("cls");
		mass_objects[cnt] = new pyramid;
		std::cout << "������ ������ ������ ��������.\n\n";
		system("pause");
		break;
	case 3:
		system("cls");
		mass_objects[cnt] = new tetrahedron;
		std::cout << "������ ������ ������ ��������.\n\n";
		system("pause");
		break;
	case 4:
		system("cls");
		mass_objects[cnt] = new sphere;
		std::cout << "������ ������ ������ ���.\n\n";
		system("pause");
		break;
	default:
		system("cls");
		std::cout << "������� �������� �����, ��������� �������!\n\n";
		system("pause");
	}
}