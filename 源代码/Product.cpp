#include "Product.h"
 
Product::Product(){
}
Product::~Product(){
}
void Product::SetPartA(string pa)
{PartA=pa;}
 
void Product::SetPartB(string pb)
{PartB=pb;}
 
void Product::SetPartC(string pc)
{PartC=pc;}
 
string Product::GetPartA() const
{return PartA;} 
string Product::GetPartB() const
{return PartB;} 
string Product::GetPartC() const
{return PartC;}

