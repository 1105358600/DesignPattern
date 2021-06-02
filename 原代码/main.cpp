#include "Account.h"
#include "AccountState.h"
#include "Observer.h"
#include "Builder.h"
#include "Product.h"
#include "Supermarket.h"
#include "Caretaker.cpp" 
#include<string> 
#include <iostream>
using namespace std;
int main(int argc,const char* argv[])
{  int operation;
   int package;
   int score;
   int i;
   Account* p = new Account("用户",400); 
   UserInfoDTO user;
   Caretaker caretaker;
   user.setState(p->getbalance());
   AccountState*state=new GreenState(0,p);
   Observer*Ob = new Observer();
   Ob->Attach(p);
   string s="窗口提示,来自超市在线购物的消息，尊敬的用户，您正在进行购物，当前有2个套餐正在热销中，请妥善保护您的财产信息";
   Ob->notify(s); //发送MessageBox类提示信息
   Supermarket* d1 = Supermarket::Instance();
	cout<<"本超市目前功能如下"<<endl;
   	cout<<"1:查看超市套餐"<<endl;
   	cout<<"2:购买超市套餐"<<endl;
   	cout<<"3:给账户充值"<<endl;
   	cout<<"4:查看历史余额记录"<<endl;
  	cout<<"5:撤回上次存款或消费"<<endl; 
   	cout<<"6:退出本超市在线购物系统"<<endl;
   	cout<<"**********************************"<<endl;
   cout<<"请输入您要进行的操作"<<endl;
   while(cin>>operation&&operation!=6)
  {
  	switch(operation)
   {case 1:
   	 	cout<<"本超市目前提供以下2种热销套餐在线购买"<<endl;
  	 	d1->Construct(new ConcreteBuilder1());
  	 	cout<<"套餐一价格200元"<<endl; 
   	 	cout<<endl; 
   	 	d1->Construct(new ConcreteBuilder2());
   	 	cout<<"套餐二价格250元"<<endl;
		cout<<endl;  
   	 	d1->Construct(new ConcreteBuilder3());
  	 	cout<<"套餐一价格300元"<<endl;
		cout<<endl;
		cout<<"请输入您要进行的操作"<<endl;    
   	 	break;
   	case 2:
   		cout<<"请输入您想要购买的套餐"<<endl;
   		cin>>package;
   		switch(package)
   		{
   		  	case 1:
				p->withdraw(200);
				
				break;
			case 2:
				p->withdraw(250);
				break;
			case 3:
				p->withdraw(300);
				break;
		}
		user.setState(p->getbalance());
		caretaker.add(user.saveStateToMemento());
		cout<<"请输入您要进行的操作"<<endl;
		break; 
	case 3:
	 	int money;
	 	cout<<"请输入您想要充值的金额：";
		cin>>money;
		p->deposit(money);
		user.setState(p->getbalance());
		caretaker.add(user.saveStateToMemento());
		cout<<"请输入您要进行的操作"<<endl;		
		break;
	case 4:
		cout<<"现在您的余额为" << user.getState()<<endl;
		cout<<"您的余额变动次数为"<<caretaker.getsize()<<"次"<<endl; 
		for(i=0;i<=caretaker.getsize()+1;i++)
		{
		user.getStateFromMemento(caretaker.get(i));
		cout<<"第"<<i+1<<"次余额变动记录后余额为" << user.getState() << endl;
		 } 
		 cout<<"请输入您要进行的操作"<<endl;
   		break;
   	case 5:
   		cout<<"您的操作已取消,现在您的余额为"<< user.getState()<<endl;
   		user.getStateFromMemento(caretaker.get(caretaker.getsize()));
		p->setbalance(user.getState());
		cout<<p->getbalance()<<endl;
		cout<<"请输入您要进行的操作"<<endl; 
		break;	
  } 
  }
   delete Ob;
   delete p;
   return 0;
}
