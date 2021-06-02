#include "Supermarket.h"
#include "Builder.h"
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
 
 

