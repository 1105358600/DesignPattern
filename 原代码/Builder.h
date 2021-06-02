//Builder.h
#ifndef _BUILDER_H_
#define _BUILDER_H_
#include <string>
using namespace std;
class Product;
class Builder
{
public:
virtual ~Builder();
virtual void BuildPartA(const string& buildPara) = 0;
virtual void BuildPartB(const string& buildPara) = 0;
virtual void BuildPartC(const string& buildPara) = 0;
virtual Product* GetProduct() = 0;
//virtual Product* GetProduct() = 0;
protected:
Builder();
private:
};
//  Builder的派生类,实现BuilderPartA和BuilderPartB和BuildPartC接口函数 
class ConcreteBuilder1:public Builder
{
public:
ConcreteBuilder1();
~ConcreteBuilder1();
void BuildPartA(const string& buildPara);
void BuildPartB(const string& buildPara);
void BuildPartC(const string& buildPara);
Product* GetProduct();
//Product* GetProduct();
protected:
private:
	Product *product;
	//Product *product;
};
//  Builder的派生类,实现BuilderPartA和BuilderPartB和BuildPartC接口函数 
class ConcreteBuilder2:public Builder
{
public:
ConcreteBuilder2();
~ConcreteBuilder2();
void BuildPartA(const string& buildPara);
void BuildPartB(const string& buildPara);
void BuildPartC(const string& buildPara);
Product* GetProduct();
//Product* GetProduct();
protected:
private:
	Product *product;
//	Product *product;
};
class ConcreteBuilder3:public Builder
{
public:
ConcreteBuilder3();
~ConcreteBuilder3();
void BuildPartA(const string& buildPara);
void BuildPartB(const string& buildPara);
void BuildPartC(const string& buildPara);
Product* GetProduct();
//Product* GetProduct();
protected:
private:
	Product *product;
//	Product *product;
};
#endif //~_BUILDER_H_

