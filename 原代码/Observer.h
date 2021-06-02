#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include<string>
#include<list>
using namespace std;
class Account;
class Observer 
{
	public:
	Observer();
	~Observer();
	void notify(string message);
	list<Account*>accs; 
    void Attach(Account *acc);
    void Detach(Account *acc);
};
#endif //_BANK_H_

