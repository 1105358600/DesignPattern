#include "Supermarket.h"
#include "Builder.h"
#include"Account.h" 
#include"AccountState.h"
#include"DeliveryObserver.cpp"
#include <iostream>
#include<list>
#include<string>
#include <iostream>
using namespace std;
Supermarket* Supermarket::_instance = 0;
Supermarket::Supermarket()
{
cout<<"supermarket "<<endl; 
}

Supermarket::Supermarket(Builder* bld)
{
_bld = bld;
}

Supermarket* Supermarket::Instance()
{
if (_instance == 0)
{
_instance = new Supermarket();
}
return _instance;
}
 
 
Product* Supermarket::Construct(Builder* bld)
{
_bld=bld;
_bld->BuildPartA("");
_bld->BuildPartB("");
_bld->BuildPartC("");
return _bld->GetProduct();

}
void Supermarket::notify(string message){
	list<DeliveryObserver*>::iterator i=accs.begin();
	int j=0;
    while(i!=accs.end())
    {	if(j%2==0)
    	{(*i)->Notify1(message);
    	 ++i;
    	 j++;
		}
    	else{
    	(*i)->Notify2(message);
    	 ++i;
    	 j++;
		}
    }
}
void Supermarket::Attach(DeliveryObserver* acc){
    accs.push_back(acc);
}
void Supermarket::Detach(DeliveryObserver* acc){
    accs.remove(acc);
}
