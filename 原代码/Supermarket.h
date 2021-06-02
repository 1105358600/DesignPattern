#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include <iostream>
using namespace std;
class Product;
class Builder;
class Supermarket
{
public:
static Supermarket* Instance();
Supermarket(Builder* bld);
~Supermarket();
Product * Construct();
Product * Construct(Builder* bld);
protected:
Supermarket();
private:
static Supermarket* _instance;
Builder* _bld;
};
#endif //~_DIRECTOR_H_
//Construct��������һ�������������������,��ͬ�Ĳ���֮���װ�䷽ʽ����һ�µ�,
//���ȹ���PartA�����PartB,ֻ�Ǹ��ݲ�ͬ�Ĺ����߻��в�ͬ�ı�ʾ

