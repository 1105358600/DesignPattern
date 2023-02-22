#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include <string>
using namespace std;
class Product
{
public:
Product();
~Product();
void SetPartA(string pa);
void SetPartB(string pb);
void SetPartC(string pc);
string GetPartA() const ;
string GetPartB() const ;
string GetPartC() const ;
protected:
private:
	string PartA;
	string PartB;
	string PartC;
};
 
#endif

