#include "../includes/Serializer.hpp"

void printData(Data &d)
{
	std::cout << "Data:" << std::endl << "Name: " << d.name << std::endl << "Number: " << d.number << std::endl;
}

int main()
{
	{
	Data d;
	d.name = "Fernanda";
	d.number = 99459756;

	printData(d);
	uintptr_t i = Serializer::serialize(&d);
	std::cout << "Serial number: " << i << std::endl;
	Data *n = deserialize(i);
	std::cout << "Deserialized data: " << std::endl;
	printData(*n);
	}
	{
	Data t;
	t.name = "Antonia";
	t.number = 178888888;

	printData(t);
	uintptr_t i = Serializer::serialize(&t);
	std::cout << "Serial number: " << i << std::endl;
	Data *n = deserialize(i);
	std::cout << "Deserialized data: " << std::endl;
	printData(*n);
	}
	return 0;
}