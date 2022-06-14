// List v0.2
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
void insert(List* _Next, const int _Where, const int& _Value);

void erase(List* _Next, const int _Where);

int main(void)
{
	List* NumberList = new List;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
		AddObject(NumberList, i * 10 + 10);
	
	Output(NumberList);
	cout << endl;

	insert(NumberList, 0, 666);
	Output(NumberList);
	cout << endl;

	cout << "erase" << endl;
	erase(NumberList, 3);
	Output(NumberList);

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
	if (_Next->Back)
		cout << "ShowValue _Back->Value : " << _Next->Back->Value << endl;
	else cout << "nullptr" << endl;

	if (_Next->Back != nullptr)
		Output(_Next->Back);
}

void insert(List* _Next, const int _Where, const int& _Value)
{
	if (_Where == 0)
	{
		List* Temp = new List;

		Temp->Value = _Value;

		Temp->Back = _Next->Back;
		_Next->Back = Temp;
	}
	else
		insert(_Next->Back, _Where - 1, _Value);
}

List* Temp2 = nullptr;

void erase(List* _Next, const int _Where)
{
	if (_Where == 0)
	{
		List* Temp = _Next;
		_Next = _Next->Back;

		delete Temp;
		Temp = nullptr;
	}
	else if (_Where == 1)
	{
		List* Temp = _Next->Back;
		_Next->Back = _Next->Back->Back;
		
		delete Temp;
		Temp = nullptr;
	}
	else
		erase(_Next->Back, _Where - 1);
}
