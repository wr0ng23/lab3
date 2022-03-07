#include "parallelepiped.h"

parallelepiped::parallelepiped()
{
	id = ++count;
	S = 0.0F;
	h = 0.0F;
}

void parallelepiped::set_data() 
{
	std::cout << "������� ������� ��������� ���������������\n"; S = input<float>();
	std::cout << "������� ������ ���������������\n"; h = input<float>();
}

void parallelepiped::display_data()
{
	std::cout << "������ �: " << id << " - ��������������" << std::endl;
	std::cout << "������� ��������� ���������������: " << S << std::endl;
	std::cout << "������ ���������������: " << h << std::endl << std::endl;
}

void parallelepiped::volume() 
{
	std::cout << "����� ��������������� " << id << " : " << S * h
		<< std::endl << std::endl;
}

void parallelepiped::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("parallelepiped.txt");
	if (!infile)
	{
		throw std::string("���������� ������� ������� ����!\n");
	}
	infile.seekg(pn * sizeof(parallelepiped));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("���������� ������ �� �����!\n");
		exit(1);
	}
	pn++;
	infile.close();
}

void parallelepiped::diskOut()
{
	std::ofstream outfile;
	outfile.open("parallelepiped.txt", std::ofstream::app);
	if (!outfile)
	{
		throw std::string("���������� ������� �������� ����!\n");
		exit(1);
	}
	outfile.write((char*)this, sizeof(*this));
	if (!outfile)
	{
		throw std::string("������ � ���� ����������!\n");
		exit(1);
	}
	outfile.close();
}