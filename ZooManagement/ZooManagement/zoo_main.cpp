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
	dog.makeSound(woofCount); // 매개변수가 있는 함수로 오버로딩


	// 동적 객체 생성
	cout << "\n*** dynamic object ***" << endl;

	Dog* dynamicDog = new Dog;
	Cat* dynamicCat = new Cat;
	dynamicDog->setName("Ddi-yong");
	dynamicCat->setName("Sawol");


	// 포인터객체 list 생성
	cout << "\n*** animalPointerList ***" << endl;
	
	list<Animal*> animalPointerList;
	list<Animal*>::iterator ListIter;
	animalPointerList.push_back(dynamicDog);
	animalPointerList.push_back(dynamicCat);

	// iterator 사용하여 list 순회
	for (ListIter = animalPointerList.begin(); ListIter != animalPointerList.end(); ListIter++)
	{
		cout << "name: " << (*ListIter)->getName() << endl;
		(*ListIter)->makeSound();
	}


	// 포인터객체 vector 생성
	cout << "\n*** animalPointerVector ***" << endl;

	vector<Animal*> animalPointerVector;
	vector<Animal*>::iterator vectorIter;
	animalPointerVector.push_back(dynamicDog);
	animalPointerVector.push_back(dynamicCat);

	// iterator 사용하여 vector 순회
	for (vectorIter = animalPointerVector.begin(); vectorIter != animalPointerVector.end(); vectorIter++)
	{
		cout << "name: " << (*vectorIter)->getName() << endl;
		(*vectorIter)->makeSound();
	}


	// runtime_error 예외처리 try-catch 블록
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

	// 프로그램 종료 시에 동적 객체들 메모리 해제
	cout << "\n*** delete animalPointerList ***" << endl;
	for (ListIter = animalPointerList.begin(); ListIter != animalPointerList.end(); ListIter++)
	{
		delete *ListIter;
	}

	return 0;
};