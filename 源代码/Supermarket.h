#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include <iostream>
#include<list>

using namespace std;
class Product;
class Builder;
class DeliveryObserver;
class Supermarket 
{
public:
static Supermarket* Instance();
Supermarket(Builder* bld);
~Supermarket();
Product * Construct();
Product * Construct(Builder* bld);
	list<DeliveryObserver*>accs; 
    void Attach(DeliveryObserver *acc);
    void Detach(DeliveryObserver *acc);
    void notify(string message);
protected:
Supermarket();
private:
static Supermarket* _instance;
Builder* _bld;
};
#endif //~_DIRECTOR_H_
//Construct��������һ�������������������,��ͬ�Ĳ���֮���װ�䷽ʽ����һ�µ�,
//���ȹ���PartA�����PartB,ֻ�Ǹ��ݲ�ͬ�Ĺ����߻��в�ͬ�ı�ʾ

