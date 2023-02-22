#include "Builder.h"
#include "Product.h"
#include <iostream>
using namespace std;
//抽象Builder基类，定义不同部分的创建接口
Builder::Builder()
{
}
Builder::~Builder()
{
}
 
ConcreteBuilder1::ConcreteBuilder1()
{
	product = new Product();
}
ConcreteBuilder1::~ConcreteBuilder1()
{
}
ConcreteBuilder2::ConcreteBuilder2()
{
	product = new Product();
}
ConcreteBuilder2::~ConcreteBuilder2()
{
}
ConcreteBuilder3::ConcreteBuilder3()
{
	product = new Product();
}
ConcreteBuilder3::~ConcreteBuilder3()
{
}
void ConcreteBuilder1::BuildPartA(const string& buildPara)
{
cout<<"套餐一1:"<<"一个电饭煲"<<endl;
product->SetPartA("一个电饭煲");
}
void ConcreteBuilder1::BuildPartB(const string& buildPara)
{
cout<<"套餐一2:"<<"一袋东北大米"<<endl;
product->SetPartB("一袋东北大米");
}
void ConcreteBuilder1::BuildPartC(const string& buildPara)
{
cout<<"套餐一3:"<<"一套餐具"<<endl;
product->SetPartC("一套餐具");
}
Product* ConcreteBuilder1::GetProduct()
{
	cout<<"套餐一价格200元"<<endl; 	
   	cout<<endl; 
return product;
}
void ConcreteBuilder2::BuildPartA(const string& buildPara)
{
cout<<"套餐二1:"<<"一台风扇"<<endl;
product->SetPartA("一台风扇");
}
void ConcreteBuilder2::BuildPartB(const string& buildPara)
{
cout<<"套餐二2:"<<"一块凉席"<<endl;
product->SetPartB("一块凉席");
}
void ConcreteBuilder2::BuildPartC(const string& buildPara)
{
cout<<"套餐二3:"<<"一个大西瓜"<<endl;
product->SetPartC("一个大西瓜");
}
Product* ConcreteBuilder2::GetProduct()
{cout<<"套餐二价格250元"<<endl;
cout<<endl; 
return product;
}

void ConcreteBuilder3::BuildPartA(const string& buildPara)
{
cout<<"套餐三1:"<<"一个枕头"<<endl;
product->SetPartA("一个枕头");
}
void ConcreteBuilder3::BuildPartB(const string& buildPara)
{
cout<<"套餐三2:"<<"一套被子"<<endl;
product->SetPartB("一套被子");
}
void ConcreteBuilder3::BuildPartC(const string& buildPara)
{
cout<<"套餐三3:"<<"一个床"<<endl;
product->SetPartC("一个床");
}
Product* ConcreteBuilder3::GetProduct()
{
cout<<"套餐三价格300元"<<endl;
cout<<endl;
return product;
}
//ConcreteBuilder1与ConcreteBuilder2是Builder的两个派生类，用于实现两种不同的建造细节
// 使用Builder构建产品,构建产品的过程都一致,但是不同的builder有不同的实现 
 

