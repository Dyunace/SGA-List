// List v0.1
#include <iostream>

using namespace std;

struct List
{
	int Value;
	List* Back;
};

void AddObject(List* _Next, const int& _Value);

void Output(List* _Next);

// 숙제 : 중간에 추가하기
void insert(List* _Next, const int _where, const int& _Value);

int main(void)
{
	List* NumberList = new List;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		AddObject(NumberList, i * 10 + 10);
	}

	cout << endl;

	Output(NumberList);

	cout << endl;

	return 0;
}

void AddObject(List* _Next, const int& _Value)
{
	if (_Next->Back == nullptr)
	{
		List* Temp = new List;
		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Next->Back = Temp;
	}
	else
		AddObject(_Next->Back, _Value);

}

void Output(List* _Next)
{
	cout << "ShowValue _Value : " << _Next->Value << endl;
	if (_Next->Back != nullptr)
		Output(_Next->Back);
}

void insert(List* _Next, const int _where, const int& _Value)
{
	List* Temp = nullptr;
	List* Temp2 = nullptr;

	for (int i = 0; i < _where + (-1); ++i)
		Temp2 = _Next->Back;
}