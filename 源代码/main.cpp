#include "Account.h"
#include "AccountState.h"
#include "Builder.h"
#include "Product.h"
#include "DeliveryObserver.cpp"
#include "Supermarket.h"
#include "Caretaker.cpp" 
#include<string> 
#include <iostream>
using namespace std;
int main(int argc,const char* argv[])
{  int operation;
   int package;
   int score;
   system("color f0");   //黑底白字
   int i;
   Account* p = new Account("用户",400); 
   UserInfoDTO user;
   DeliveryObserver* del1=new DeliveryObserver("配送员1");
   DeliveryObserver* del2=new DeliveryObserver("配送员2");
   Caretaker caretaker;
   user.setState(p->getbalance());
   AccountState*state=new GreenState(0,p);
   Supermarket* d1 = Supermarket::Instance();
   d1->Attach(del1);
   d1->Attach(del2);
   string s="窗口提示,来自超市在线购物的消息，新订单到了，请选择是否配送";
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
   	 	cout<<"本超市目前提供以下3种热销套餐在线购买"<<endl;
  	 	d1->Construct(new ConcreteBuilder1());
   	 	d1->Construct(new ConcreteBuilder2());
   	 	d1->Construct(new ConcreteBuilder3());
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
			default:
				cout<<"输入错误"<<endl;
				break;
		}
		d1->notify(s); 
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
		for(i=0;i<caretaker.getsize();i++)
		{
		user.getStateFromMemento(caretaker.get(i));
		cout<<"第"<<i+1<<"次余额变动记录后余额为" << user.getState() << endl;
		 } 
		 cout<<"请输入您要进行的操作"<<endl;
   		break;
   	case 5:
   		if(caretaker.getsize()>=2)
		   {user.getStateFromMemento(caretaker.get(caretaker.getsize()-2));
			p->setbalance(user.getState());
			cout<<p->getbalance()<<endl;
			user.setState(p->getbalance());
			caretaker.add(user.saveStateToMemento());
			cout<<"您的操作已取消,现在您的余额为"<< user.getState()<<endl;
			} 
   		else if(caretaker.getsize()==1)
		     {p->setbalance(400);
			 cout<<p->getbalance()<<endl;
			 user.setState(p->getbalance());
			 caretaker.add(user.saveStateToMemento());
			 cout<<"您的操作已取消,现在您的余额为"<< user.getState()<<endl;
			} 
		else 
		   	 cout<<"您不能取消上次操作，请先进行消费或充值"<<endl;
		cout<<"请输入您要进行的操作"<<endl; 
		break;
	default:
		cout<<"您的输入有误，请重新输入"<<endl;
   		break;
  } 
  }
   delete p;
   return 0;
}
