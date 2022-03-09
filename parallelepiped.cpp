#include "parallelepiped.h"

parallelepiped::parallelepiped()
{
	S = 0.0F;
	h = 0.0F;
	count++;
}

parallelepiped::~parallelepiped()
{
	count--;
}

void parallelepiped::set_data() 
{
	std::cout << "������� ������� ��������� ���������������\n"; S = input<float>();
	std::cout << "������� ������ ���������������\n"; h = input<float>();
}

void parallelepiped::display_data() const
{
	std::cout << "������ - ��������������" << std::endl;
	std::cout << "������� ��������� ���������������: " << S << std::endl;
	std::cout << "������ ���������������: " << h << std::endl << std::endl;
}

void parallelepiped::volume() const 
{
	std::cout << "����� ���������������: " << S * h << std::endl << std::endl;
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
	}
	pn++;
	infile.close();
}

void parallelepiped::diskOut() const
{
	std::ofstream outfile;
	outfile.open("parallelepiped.txt", std::ios::app);
	if (!outfile)
	{
		throw std::string("���������� ������� �������� ����!\n");
	}
	outfile.write((char*)this, sizeof(*this));
	if (!outfile)
	{
		throw std::string("������ � ���� ����������!\n");
	}
	outfile.close();
}