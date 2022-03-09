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
	std::cout << "Введите площадь основания параллелепипеда\n"; S = input<float>();
	std::cout << "Введите высоту параллелепипеда\n"; h = input<float>();
}

void parallelepiped::display_data() const
{
	std::cout << "Объект - параллелепипед" << std::endl;
	std::cout << "Площадь основания параллелепипеда: " << S << std::endl;
	std::cout << "Высота параллелепипеда: " << h << std::endl << std::endl;
}

void parallelepiped::volume() const 
{
	std::cout << "Объем параллелепипеда: " << S * h << std::endl << std::endl;
}

void parallelepiped::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("parallelepiped.txt");
	if (!infile)
	{
		throw std::string("Невозможно открыть входной файл!\n");
	}
	infile.seekg(pn * sizeof(parallelepiped));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("Невозможно чтение из файла!\n");
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
		throw std::string("Невозможно открыть выходной файл!\n");
	}
	outfile.write((char*)this, sizeof(*this));
	if (!outfile)
	{
		throw std::string("Запись в файл невозможна!\n");
	}
	outfile.close();
}