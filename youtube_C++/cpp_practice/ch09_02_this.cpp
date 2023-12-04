#include <iostream>
using namespace std;

class CopyObj
{
public:
	CopyObj(const double height, const double weight);
	double getHeight();
	double getWeight();
private:
	double height;
	double weight;
};

CopyObj::CopyObj(const double height, const double weight)
{
	//CopyObj::height = height;
	//CopyObj::weight = weight;
	this->height = height; //this °´Ã¼
	this->weight = weight;
}

double CopyObj::getHeight()
{
	return height;
}

double CopyObj::getWeight()
{
	return weight;
}

int main()
{
	CopyObj co(153, 39);

	cout << co.getHeight() << endl;
	cout << co.getWeight() << endl;

	return 0;
}