#ifndef _ACCOUNTSTATE_H_
#define _ACCOUNTSTATE_H_
#include<string>
using namespace std;
class Account;
class AccountState
{
	public:
		virtual ~AccountState();
		AccountState();
		virtual void deposit(double amount)=0;
		virtual void withdraw(double amount)=0;
		virtual void stateCheck()=0;
		virtual string getName();
		double balance;
		Account* acc;	
		
};
class GreenState:public AccountState
{
	public:
		GreenState(AccountState* acc);
		GreenState(double balance,Account* acc);
		~GreenState();
	    void deposit(double amount);
		void withdraw(double amount);
		void stateCheck();
		string getName();	
};
class RedState:public AccountState
{
	public:
		RedState(AccountState* acc);
		~RedState();
	    void deposit(double amount);
		void withdraw(double amount);
		void stateCheck();
		string getName();	
};
class VIP:public AccountState
{
	public:
		VIP(AccountState* acc);
		~VIP();
	    void deposit(double amount);
		void withdraw(double amount);
		void stateCheck();
		string getName();	
};
#endif //_ACCOUNTSTATE_H_

