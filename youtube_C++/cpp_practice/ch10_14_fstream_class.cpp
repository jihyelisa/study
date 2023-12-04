#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	fstream fs;

	// 출력 모드로 엶
	fs.open("test.txt", ios::out);
	
	if (fs.fail())
		return 0;

	fs << "keyboard" << endl;
	fs << "monitor" << endl;
	fs.close();



	// append 모드로 엶 - 맨 뒤에 내용 추가
	fs.open("test.txt", ios::app);
	fs << "desk" << endl;
	fs.close();



	// 입력 모드로 엶
	fs.open("test.txt", ios::in);
	string temp;

	while (fs >> temp, !fs.eof())
	{
		cout << temp << endl;
	}

	fs.close();



	// 이진파일 출력
	int scoreArr[5] = { 78, 96, 100, 25, 96 };
	fs.open("sample.bin", ios::out | ios::binary); // 출력 이진파일 설정
	fs.write((char*)scoreArr, 20); // score 위치에서 20바이트 출력
	fs.close();



	// 이진파일 입력
	fs.open("sample.bin", ios::in | ios::binary); // 입력 - 이진파일
	if (fs.fail()) // 파일 오픈 실패 시 프로그램 종료
		return 1;

	int score;
	while (fs.read((char*)&score, 4), !fs.eof())
		cout << setw(3) << right << score << endl;

	fs.close();

	return 0;
}