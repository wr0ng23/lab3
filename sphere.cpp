#include "sphere.h"

sphere::sphere()
{
	id = ++count;
	R = 0.0F;
}

void sphere::set_data()
{
	std::cout << "Введите радиус шара\n"; R = input<float>();
}

void sphere::display_data() 
{
	std::cout << "Объект №: " << id << " - шар" << std::endl;
	std::cout << "Радиус шара: " << R << std::endl << std::endl;
}

void sphere::volume()
{
	const double pi = acos(-1);
	std::cout << "Объем шара " << id << " : " << pi * pow(R, 3) * 4 / 3
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
		exit(1);
	}
	infile.seekg(pn * sizeof(sphere));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("Невозможно чтение из файла!\n");
		exit(1);
	}
	pn++;
	infile.close();
}

void sphere::diskOut()
{
	std::ofstream outfile;
	outfile.open("sphere.txt", std::ofstream::app);
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