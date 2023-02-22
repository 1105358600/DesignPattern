#include "Account.h"
#include"DeliveryObserver.cpp"
#include"MessageStrategy.h"
#include <iostream>
#include <string>
#include<list>
#include <cstring>   
#include <sstream>
using namespace std;
Account::Account(string owner,double init)
{	
	this->owner = owner;
	this->state = new GreenState(init, this);
	cout<<"�˻�:"<<this->owner<<"��ʼ���:"<<init<<endl;
}
Account::~Account()
{
}
void Account::setState(AccountState* state)
{
	this->state = state;
}
void Account::setStrategy(MessageStrategy* msStrategy)
{
	this->msStrategy=msStrategy;
}
void Account::Response(string message)
{
	msStrategy->AlgrithmInterface(message);
}
void Account::Notify(string message)
{
	MessageStrategy* m1=new MessageStrategy1();
	this->setStrategy(m1);
	Response(message);
}
double Account::getbalance()
{
	return this->state->balance;
}
void Account::deposit(double amount)
{
	state->deposit(amount);
	double a=state->balance;
	MessageStrategy* m1=new MessageStrategy2();
	this->setStrategy(m1);
	stringstream s;
	s<<a<<endl;
	string stramount;
    stringstream ss;
    ss<<amount;
    ss>>stramount;
	string s1;s>>s1;
	string s2=state->getName();
	string s3=this->owner;
	string message1="�����˻��Ѵ���"+stramount+"Ԫ��"+" �������Ϊ��"+s1+" �˻�״̬Ϊ��"+s2; 
	this->Response(message1);

}
 
 
void Account::withdraw(double amount)
{	string s2=state->getName();
	state->withdraw(amount);
	if(s2=="GreenState")
	{
	double a=state->balance;
	MessageStrategy* m2=new MessageStrategy2();
	this->setStrategy(m2);
	stringstream s;
	s<<a<<endl;
	string s1;s>>s1;
	string stramount;
    stringstream ss;
    ss<<amount;
    ss>>stramount;
	s2=state->getName();
	string s3=this->owner;
	string message2="�����˻�������"+stramount+"Ԫ��"+" �������Ϊ��"+s1+" �˻�״̬Ϊ��"+s2; 
	this->Response(message2);
	}
	else if(s2=="VIP")
	{
	double a=state->balance;
	MessageStrategy* m2=new MessageStrategy1();
	this->setStrategy(m2);
	stringstream s;
	s<<a<<endl;
	string s1;s>>s1;
	string stramount;
	string stramount1;
    stringstream ss;
    ss<<amount;
    ss>>stramount;
    stringstream ss1;
    ss1<<amount*0.8;
    ss1>>stramount1;
	s2=state->getName();
	string s3=this->owner;
	string message2="�𾴵�VIP�û������������Ʒԭ��Ϊ"+stramount+"Ԫ���Żݺ�Ϊ"+stramount1+"Ԫ��"+" �������Ϊ��"+s1+" �˻�״̬Ϊ��"+s2; 
	this->Response(message2);
	}
}

