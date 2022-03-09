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
	std::cout << "Введите площадь основания пирамиды\n"; S = input<float>();
	std::cout << "Введите высоту пирамиды\n"; h = input<float>();
}

void pyramid::display_data() const
{
	std::cout << "Объект - пирамида" << std::endl;
	std::cout << "Площадь основания пирамиды: " << S << std::endl;
	std::cout << "Высота пирамиды: " << h << std::endl << std::endl;
}

void pyramid::volume() const
{
	std::cout << "Объем пирамиды: " << (S * h) / 3
		<< std::endl << std::endl;
}

void pyramid::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("pyramid.txt");
	if (!infile)
	{
		throw std::string("Невозможно открыть входной файл!\n\n");
	}
	infile.seekg(pn * sizeof(pyramid));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("Невозможно чтение из файла!\n\n");
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
		throw std::string("Невозможно открыть выходной файл!\n\n");
	}
	outfile.write((char*)this, sizeof(*this));
	if (!outfile)
	{
		throw std::string("Запись в файл невозможна!\n\n");
	}
	outfile.close();
}