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
	cout << "忙式式式式式式式式式式式式式式式忖" << endl;
	
	for (int i = 0; i < times; i++)
	{
		cout << "|     woof!     |" << endl;
	}
	
	cout << "戌式式式式式式式式式式式式式式式戎" << endl;
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