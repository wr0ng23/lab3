#include "pyramid.h"

pyramid::pyramid()
{
	id = ++count;
	S = 0.0F;
	h = 0.0F;
}

void pyramid::set_data() 
{
	std::cout << "������� ������� ��������� ��������\n"; S = input<float>();
	std::cout << "������� ������ ��������\n"; h = input<float>();
}

void pyramid::display_data() 
{
	std::cout << "������ �: " << id << " - ��������" << std::endl;
	std::cout << "������� ��������� ��������: " << S << std::endl;
	std::cout << "������ ��������: " << h << std::endl << std::endl;
}

void pyramid::volume() 
{
	std::cout << "����� �������� " << id << " : " << (S * h) / 3
		<< std::endl << std::endl;
}

void pyramid::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("pyramid.txt");
	if (!infile)
	{
		throw std::string("���������� ������� ������� ����!\n");
		exit(1);
	}
	infile.seekg(pn * sizeof(pyramid));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("���������� ������ �� �����!\n");
		exit(1);
	}
	pn++;
	infile.close();
}

void pyramid::diskOut()
{
	std::ofstream outfile;
	outfile.open("pyramid.txt", std::ofstream::app);
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