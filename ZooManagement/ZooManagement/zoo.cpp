#include "zoo.h"


Animal::Animal()
{
	cout << "Animal Constructor" << endl;
}

Animal::~Animal()
{
	cout << "Animal Destructor" << endl;
}

void Animal::setName(const string name)
{
	this->name = name;
}

string  Animal::getName()
{
	return name;
}

Dog::Dog()
{
	cout << "Dog Constructor" << endl;
}

Dog::~Dog()
{
	cout << "Dog Destructor" << endl;
}

void Dog::makeSound()
{
	cout << "Woof! Woof!" << endl;
}

void Dog::makeSound(const int times)
{
	cout << "����������������������������������" << endl;
	
	for (int i = 0; i < times; i++)
	{
		cout << "|     woof!     |" << endl;
	}
	
	cout << "����������������������������������" << endl;
}

Cat::Cat()
{
	cout << "Cat Constructor" << endl;
}

Cat::~Cat()
{
	cout << "Cat Destructor" << endl;
}

void Cat::makeSound()
{
	cout << "Meow! Meow!" << endl;
}