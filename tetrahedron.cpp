#include "tetrahedron.h"

tetrahedron::tetrahedron()
{
	id = ++count;
	a = 0.0F;
}

void tetrahedron::set_data()
{
	std::cout << "Введите длину ребра тетраэдра\n"; a = input<float>();
}

void tetrahedron::display_data()
{
	std::cout << "Объект №: " << id << " - тетраэдр" << std::endl;
	std::cout << "Длина ребра тетраэдра: " << a << std::endl << std::endl;
}

void tetrahedron::volume()
{
	std::cout << "Объем правильного тетраэдра " << id << " : "
		<< pow(a, 3) * sqrt(2) / 12 << std::endl << std::endl;
}

void tetrahedron::diskIn()
{
	static size_t pn = 0;
	std::ifstream infile;
	infile.open("tetrahedron.txt");
	if (!infile)
	{
		throw std::string("Невозможно открыть входной файл!\n");
		exit(1);
	}
	infile.seekg(pn * sizeof(tetrahedron));
	infile.read((char*)this, sizeof(*this));
	if (!infile)
	{
		throw std::string("Невозможно чтение из файла!\n");
		exit(1);
	}
	pn++;
	infile.close();
}

void tetrahedron::diskOut()
{
	std::ofstream outfile;
	outfile.open("tetrahedron.txt", std::ofstream::app);
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