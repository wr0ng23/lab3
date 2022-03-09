#include "sphere.h"

sphere::sphere() : R(0.0F)
{
	count++;
}

sphere::~sphere()
{
	count--;
}

void sphere::set_data()
{
	std::cout << "Введите радиус шара\n"; R = input<float>();
}

void sphere::display_data() const
{
	std::cout << "Объект - шар" << std::endl;
	std::cout << "Радиус шара: " << R << std::endl << std::endl;
}

void sphere::volume() const
{
	const double pi = acos(-1);
	std::cout << "Объем шара: " << pi * pow(R, 3) * 4 / 3
		<< std::endl << std::endl;
}

void sphere::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("sphere.txt");
	if (!infile)
	{
		throw std::string("Невозможно открыть входной файл!\n");
	}
	infile.seekg(pn * sizeof(sphere));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("Невозможно чтение из файла!\n");
	}
	pn++;
	infile.close();
}

void sphere::diskOut() const
{
	std::ofstream outfile;
	outfile.open("sphere.txt", std::ios::app);
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