#include "pyramid.h"

pyramid::pyramid()
{
	S = 0.0F;
	h = 0.0F;
	count++;
}

pyramid::~pyramid()
{
	count--;
}

void pyramid::set_data() 
{
	std::cout << "������� ������� ��������� ��������\n"; S = input<float>();
	std::cout << "������� ������ ��������\n"; h = input<float>();
}

void pyramid::display_data() const
{
	std::cout << "������ - ��������" << std::endl;
	std::cout << "������� ��������� ��������: " << S << std::endl;
	std::cout << "������ ��������: " << h << std::endl << std::endl;
}

void pyramid::volume() const
{
	std::cout << "����� ��������: " << (S * h) / 3
		<< std::endl << std::endl;
}

void pyramid::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("pyramid.txt");
	if (!infile)
	{
		throw std::string("���������� ������� ������� ����!\n\n");
	}
	infile.seekg(pn * sizeof(pyramid));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("���������� ������ �� �����!\n\n");
	}
	pn++;
	infile.close();
}

void pyramid::diskOut() const
{
	std::ofstream outfile;
	outfile.open("pyramid.txt", std::ios::app);
	if (!outfile)
	{
		throw std::string("���������� ������� �������� ����!\n\n");
	}
	outfile.write((char*)this, sizeof(*this));
	if (!outfile)
	{
		throw std::string("������ � ���� ����������!\n\n");
	}
	outfile.close();
}