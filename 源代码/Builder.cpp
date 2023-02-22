#include "Builder.h"
#include "Product.h"
#include <iostream>
using namespace std;
//����Builder���࣬���岻ͬ���ֵĴ����ӿ�
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
cout<<"�ײ�һ1:"<<"һ���緹��"<<endl;
product->SetPartA("һ���緹��");
}
void ConcreteBuilder1::BuildPartB(const string& buildPara)
{
cout<<"�ײ�һ2:"<<"һ����������"<<endl;
product->SetPartB("һ����������");
}
void ConcreteBuilder1::BuildPartC(const string& buildPara)
{
cout<<"�ײ�һ3:"<<"һ�ײ;�"<<endl;
product->SetPartC("һ�ײ;�");
}
Product* ConcreteBuilder1::GetProduct()
{
	cout<<"�ײ�һ�۸�200Ԫ"<<endl; 	
   	cout<<endl; 
return product;
}
void ConcreteBuilder2::BuildPartA(const string& buildPara)
{
cout<<"�ײͶ�1:"<<"һ̨����"<<endl;
product->SetPartA("һ̨����");
}
void ConcreteBuilder2::BuildPartB(const string& buildPara)
{
cout<<"�ײͶ�2:"<<"һ����ϯ"<<endl;
product->SetPartB("һ����ϯ");
}
void ConcreteBuilder2::BuildPartC(const string& buildPara)
{
cout<<"�ײͶ�3:"<<"һ��������"<<endl;
product->SetPartC("һ��������");
}
Product* ConcreteBuilder2::GetProduct()
{cout<<"�ײͶ��۸�250Ԫ"<<endl;
cout<<endl; 
return product;
}

void ConcreteBuilder3::BuildPartA(const string& buildPara)
{
cout<<"�ײ���1:"<<"һ����ͷ"<<endl;
product->SetPartA("һ����ͷ");
}
void ConcreteBuilder3::BuildPartB(const string& buildPara)
{
cout<<"�ײ���2:"<<"һ�ױ���"<<endl;
product->SetPartB("һ�ױ���");
}
void ConcreteBuilder3::BuildPartC(const string& buildPara)
{
cout<<"�ײ���3:"<<"һ����"<<endl;
product->SetPartC("һ����");
}
Product* ConcreteBuilder3::GetProduct()
{
cout<<"�ײ����۸�300Ԫ"<<endl;
cout<<endl;
return product;
}
//ConcreteBuilder1��ConcreteBuilder2��Builder�����������࣬����ʵ�����ֲ�ͬ�Ľ���ϸ��
// ʹ��Builder������Ʒ,������Ʒ�Ĺ��̶�һ��,���ǲ�ͬ��builder�в�ͬ��ʵ�� 
 

