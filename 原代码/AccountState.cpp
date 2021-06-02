#include "Account.h"
#include "AccountState.h"
#include <iostream>
using namespace std;
 
AccountState::AccountState()
{
}
AccountState::~AccountState()
{	
}
void AccountState::withdraw(double amount)
{
}	
void AccountState::deposit(double amount)
{
} 
void AccountState::stateCheck()
{
}
string AccountState::getName()
{
	return " "; 
}
 

GreenState::GreenState(AccountState* state)
{	
    this->balance =state->balance;  
    this->acc = state->acc;  
}
GreenState::GreenState(double balance,Account* acc)
{
	this->balance = balance;  
    this->acc = acc;  
}
GreenState::~GreenState()
{	
}
void GreenState::stateCheck() {   
    if(balance<=0){  
        acc->setState(new RedState(this));  
    }  
 }  
void GreenState::deposit(double amount)
{
	this->balance+=amount;
    stateCheck();
}
 
void GreenState::withdraw(double amount)
{
	this->balance-=amount;
    stateCheck();
}
string GreenState::getName()
{
	return "GreenState";
}
RedState::RedState(AccountState* state)
{
	this->balance =state->balance;  
    this->acc = state->acc;  
}
RedState::~RedState()
{	
}
void RedState::stateCheck() {   
    if(balance>0){  
            acc->setState(new GreenState(this));  
        }
} 
void RedState::deposit(double amount)
{
	this->balance+=amount;
    stateCheck();
}
 
void RedState::withdraw(double amount)
{
cout<<"您的余额不足，无法购物"<<endl;
}
string RedState::getName()
{
	return "RedState";
}

