// List v0.3
#include <iostream>

using namespace std;

struct List
{
	List* Front;
	int Value;
	List* Back;
};

void push_back(List* _Current, const int& _Value);
void pop_back(List* _Current);
void insert(List* _Current, const int _Where, const int& _Value);
void erase(List* _Current, const int _Where);

void Output(List* _Current);

List* End;

int main(void)
{
	List* NumberList = new List;

	NumberList->Front = nullptr;
	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
		push_back(NumberList, i * 10 + 10);

	cout << "insert ======" << endl;
	insert(NumberList, 2, 666);
	Output(NumberList);

	cout << "erase ======" << endl;
	erase(NumberList, 3);
	Output(NumberList);

	cout << "pop_back ======" << endl;
	pop_back(NumberList);
	Output(NumberList);

	return 0;
}

void push_back(List* _Current, const int& _Value)
{
	if (_Current->Back == nullptr)
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Current->Back = Temp;

		End = Temp;
	}
	else
		push_back(_Current->Back, _Value);
}

void pop_back(List* _Current)
{
	if (_Current->Back == nullptr)
	{
		End = _Current->Front;
		_Current->Front->Back = nullptr;
		
		delete _Current;
		_Current = nullptr;
	}
	else
		pop_back(_Current->Back);
}

void insert(List* _Current, const int _Where, const int& _Value)
{
	if (_Where == 0)
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = _Current->Back;

		_Current->Back = Temp;
	}
	else
		insert(_Current->Back, _Where - 1, _Value);
}

void erase(List* _Current, const int _Where)
{
	if (_Where == 0)
	{
		_Current->Front->Back = _Current->Back;
		_Current->Back->Front = _Current->Front;

		delete _Current;
		_Current = nullptr;
	}
	else
		erase(_Current->Back, _Where - 1);
}

void Output(List* _Current)
{
	if (_Current->Front)
		cout << "ShowValue Front->Value : " << _Current->Front->Value << endl;
	
	cout << "This Value : " << _Current->Value << endl;

	if (_Current->Back)
		cout << "ShowValue Back->Value : " << _Current->Back->Value << endl;
	else cout << "nullptr" << endl;

	cout << endl;

	if (_Current->Back != nullptr)
		Output(_Current->Back);
}