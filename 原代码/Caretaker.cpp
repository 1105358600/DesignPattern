#ifndef _CARETAKER_H_
#define _CARETAKER_H_
#include"UserInfoDTO.cpp"
#include<string>
#include<vector>
#include <iostream>
using namespace std;
class Caretaker{
public:
	CareTaker() {};
	void add(Memento *state) {mementoList.push_back(state);}
	int getsize() 
	{return mementoList.size();
	}
	Memento* get(int index) {return mementoList[index];}
private:
	vector<Memento*> mementoList;
};
#endif 
