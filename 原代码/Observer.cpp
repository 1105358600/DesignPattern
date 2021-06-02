#include"Account.h" 
#include"AccountState.h"
#include"Observer.h"
#include <iostream>
#include<list>
using namespace std;
class Account;
Observer::Observer()
{
}
Observer::~Observer()
{
}
void Observer::notify(string message){
	list<Account*>::iterator i=accs.begin();
    while(i!=accs.end())
    {
    	(*i)->Notify(message);
    	++i;
    }
}
void Observer::Attach(Account* acc){
    accs.push_back(acc);
}
void Observer::Detach(Account* acc){
    accs.remove(acc);
}

