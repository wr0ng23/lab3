#include "tetrahedron.h"

tetrahedron::tetrahedron() : a(0.0F)
{
	count++;
}

tetrahedron::~tetrahedron()
{
	count--;
}

void tetrahedron::set_data()
{
	std::cout << "������� ����� ����� ���������\n"; a = input<float>();
}

void tetrahedron::display_data() const
{
	std::cout << "������ - ��������" << std::endl;
	std::cout << "����� ����� ���������: " << a << std::endl << std::endl;
}

void tetrahedron::volume() const
{
	std::cout << "����� ����������� ���������: " << pow(a, 3) * sqrt(2) / 12 
		<< std::endl << std::endl;
}

void tetrahedron::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("tetrahedron.txt");
	if (!infile)
	{
		throw std::string("���������� ������� ������� ����!\n");
	}
	infile.seekg(pn * sizeof(tetrahedron));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("���������� ������ �� �����!\n");
	}
	pn++;
	infile.close();
}

void tetrahedron::diskOut() const
{
	std::ofstream outfile;
	outfile.open("tetrahedron.txt", std::ios::app);
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