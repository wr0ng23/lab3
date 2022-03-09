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
	std::cout << "Введите длину ребра тетраэдра\n"; a = input<float>();
}

void tetrahedron::display_data() const
{
	std::cout << "Объект - тетраэдр" << std::endl;
	std::cout << "Длина ребра тетраэдра: " << a << std::endl << std::endl;
}

void tetrahedron::volume() const
{
	std::cout << "Объем правильного тетраэдра: " << pow(a, 3) * sqrt(2) / 12 
		<< std::endl << std::endl;
}

void tetrahedron::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("tetrahedron.txt");
	if (!infile)
	{
		throw std::string("Невозможно открыть входной файл!\n");
	}
	infile.seekg(pn * sizeof(tetrahedron));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("Невозможно чтение из файла!\n");
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
		throw std::string("Невозможно открыть выходной файл!\n");
	}
	outfile.write((char*)this, sizeof(*this));
	if (!outfile)
	{
		throw std::string("Запись в файл невозможна!\n");
	}
	outfile.close();
}