#include<iostream>
#include<string>
#include "MessageStrategy.h"
#include<list>
using namespace std;
class MessageStrategy;
class DeliveryObserver
{
 public:
DeliveryObserver(string name)
 {		this->name = name;}
 ~DeliveryObserver()
 {}
 void Response(string message)
 {msStrategy->AlgrithmInterface(message); }
 void setStrategy(MessageStrategy* msStrategy)
 {this->msStrategy=msStrategy;}
 
 void Notify1(string message)
 { 	MessageStrategy* m1=new MessageStrategy1();
	this->setStrategy(m1);
	Response(this->name+"ÄúºÃ£¬"+message);
 }
  void Notify2(string message)
 { 	MessageStrategy* m1=new MessageStrategy2();
	this->setStrategy(m1);
	Response(this->name+"ÄúºÃ£¬"+message);
 }
 private:
 string name;
 MessageStrategy* msStrategy;
 
};


