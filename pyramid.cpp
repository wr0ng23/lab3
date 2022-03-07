#include "pyramid.h"

pyramid::pyramid()
{
	id = ++count;
	S = 0.0F;
	h = 0.0F;
}

void pyramid::set_data() 
{
	std::cout << "Введите площадь основания пирамиды\n"; S = input<float>();
	std::cout << "Введите высоту пирамиды\n"; h = input<float>();
}

void pyramid::display_data() 
{
	std::cout << "Объект №: " << id << " - пирамида" << std::endl;
	std::cout << "Площадь основания пирамиды: " << S << std::endl;
	std::cout << "Высота пирамиды: " << h << std::endl << std::endl;
}

void pyramid::volume() 
{
	std::cout << "Объем пирамиды " << id << " : " << (S * h) / 3
		<< std::endl << std::endl;
}

void pyramid::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("pyramid.txt");
	if (!infile)
	{
		throw std::string("Невозможно открыть входной файл!\n");
		exit(1);
	}
	infile.seekg(pn * sizeof(pyramid));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("Невозможно чтение из файла!\n");
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
		throw std::string("Невозможно открыть выходной файл!\n");
		exit(1);
	}
	outfile.write((char*)this, sizeof(*this));
	if (!outfile)
	{
		throw std::string("Запись в файл невозможна!\n");
		exit(1);
	}
	outfile.close();
}