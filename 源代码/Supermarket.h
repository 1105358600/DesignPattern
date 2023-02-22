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
//Construct函数定义一个对象的整个构建过程,不同的部分之间的装配方式都是一致的,
//首先构建PartA其次是PartB,只是根据不同的构建者会有不同的表示

