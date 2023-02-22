#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<iostream>
#include<string>
#include "AccountState.h"
#include<list>
using namespace std;
class DeliveryObserver;
class AccountState;
 
class MessageStrategy;
 
class Account
{
 public:
Account(string owner,double init);
 ~Account();
 void deposit(double amount);
 void setbalance(double amount)
 {this->state->balance=amount;
 }
 void withdraw(double amount);
 void setState(AccountState* state);
 double getbalance();
 void Response(string message);
 void setStrategy(MessageStrategy* msStrategy);
 void Notify(string message);
 private:
 string owner;
 AccountState* state;
 MessageStrategy* msStrategy;
 
};
 
#endif //_ACCOUNT_H_



