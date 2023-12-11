#include "zoo.h"

int main()
{

	Dog dog;
	Cat cat;

	dog.makeSound();
	cat.makeSound();


	int woofCount;
	cout << "\nHow many woofs? ";
	cin >> woofCount;
	dog.makeSound(woofCount); // �Ű������� �ִ� �Լ��� �����ε�


	// ���� ��ü ����
	cout << "\n*** dynamic object ***" << endl;

	Dog* dynamicDog = new Dog;
	Cat* dynamicCat = new Cat;
	dynamicDog->setName("Ddi-yong");
	dynamicCat->setName("Sawol");


	// �����Ͱ�ü list ����
	cout << "\n*** animalPointerList ***" << endl;
	
	list<Animal*> animalPointerList;
	list<Animal*>::iterator ListIter;
	animalPointerList.push_back(dynamicDog);
	animalPointerList.push_back(dynamicCat);

	// iterator ����Ͽ� list ��ȸ
	for (ListIter = animalPointerList.begin(); ListIter != animalPointerList.end(); ListIter++)
	{
		cout << "name: " << (*ListIter)->getName() << endl;
		(*ListIter)->makeSound();
	}


	// �����Ͱ�ü vector ����
	cout << "\n*** animalPointerVector ***" << endl;

	vector<Animal*> animalPointerVector;
	vector<Animal*>::iterator vectorIter;
	animalPointerVector.push_back(dynamicDog);
	animalPointerVector.push_back(dynamicCat);

	// iterator ����Ͽ� vector ��ȸ
	for (vectorIter = animalPointerVector.begin(); vectorIter != animalPointerVector.end(); vectorIter++)
	{
		cout << "name: " << (*vectorIter)->getName() << endl;
		(*vectorIter)->makeSound();
	}


	// runtime_error ����ó�� try-catch ���
	cout << "\n*** runtime_error try-catch ***" << endl;

	try
	{
		locale loc("test");
	}
	catch (const exception& e)
	{
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	}

	// ���α׷� ���� �ÿ� ���� ��ü�� �޸� ����
	cout << "\n*** delete animalPointerList ***" << endl;
	for (ListIter = animalPointerList.begin(); ListIter != animalPointerList.end(); ListIter++)
	{
		delete *ListIter;
	}

	return 0;
};