#ifndef _ZOO_H_
#define _ZOO_H_

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal();
	~Animal();
	void setName(const string name);
	string getName();
	virtual void makeSound() = 0;
protected:
	string name;
};

class Dog :public Animal
{
public:
	Dog();
	~Dog();
	void makeSound();
	void makeSound(const int times);
};

class Cat :public Animal
{
public:
	Cat();
	~Cat();
	void makeSound();
};

#else
#endif