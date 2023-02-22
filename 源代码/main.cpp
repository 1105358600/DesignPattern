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
   system("color f0");   //�ڵװ���
   int i;
   Account* p = new Account("�û�",400); 
   UserInfoDTO user;
   DeliveryObserver* del1=new DeliveryObserver("����Ա1");
   DeliveryObserver* del2=new DeliveryObserver("����Ա2");
   Caretaker caretaker;
   user.setState(p->getbalance());
   AccountState*state=new GreenState(0,p);
   Supermarket* d1 = Supermarket::Instance();
   d1->Attach(del1);
   d1->Attach(del2);
   string s="������ʾ,���Գ������߹������Ϣ���¶������ˣ���ѡ���Ƿ�����";
	cout<<"������Ŀǰ��������"<<endl;
   	cout<<"1:�鿴�����ײ�"<<endl;
   	cout<<"2:�������ײ�"<<endl;
   	cout<<"3:���˻���ֵ"<<endl;
   	cout<<"4:�鿴��ʷ����¼"<<endl;
  	cout<<"5:�����ϴδ�������"<<endl; 
   	cout<<"6:�˳����������߹���ϵͳ"<<endl;
   	cout<<"**********************************"<<endl;
    cout<<"��������Ҫ���еĲ���"<<endl;
   while(cin>>operation&&operation!=6)
  {
  	switch(operation)
   {case 1:
   	 	cout<<"������Ŀǰ�ṩ����3�������ײ����߹���"<<endl;
  	 	d1->Construct(new ConcreteBuilder1());
   	 	d1->Construct(new ConcreteBuilder2());
   	 	d1->Construct(new ConcreteBuilder3());
		cout<<"��������Ҫ���еĲ���"<<endl;    
   	 	break;
   	case 2:
   		cout<<"����������Ҫ������ײ�"<<endl;
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
				cout<<"�������"<<endl;
				break;
		}
		d1->notify(s); 
		user.setState(p->getbalance());
		caretaker.add(user.saveStateToMemento());
		cout<<"��������Ҫ���еĲ���"<<endl;
		break; 
	case 3:
	 	int money;
	 	cout<<"����������Ҫ��ֵ�Ľ�";
		cin>>money;
		p->deposit(money);
		user.setState(p->getbalance());
		caretaker.add(user.saveStateToMemento());
		cout<<"��������Ҫ���еĲ���"<<endl;		
		break;
	case 4:
		cout<<"�����������Ϊ" << user.getState()<<endl;
		cout<<"�������䶯����Ϊ"<<caretaker.getsize()<<"��"<<endl; 
		for(i=0;i<caretaker.getsize();i++)
		{
		user.getStateFromMemento(caretaker.get(i));
		cout<<"��"<<i+1<<"�����䶯��¼�����Ϊ" << user.getState() << endl;
		 } 
		 cout<<"��������Ҫ���еĲ���"<<endl;
   		break;
   	case 5:
   		if(caretaker.getsize()>=2)
		   {user.getStateFromMemento(caretaker.get(caretaker.getsize()-2));
			p->setbalance(user.getState());
			cout<<p->getbalance()<<endl;
			user.setState(p->getbalance());
			caretaker.add(user.saveStateToMemento());
			cout<<"���Ĳ�����ȡ��,�����������Ϊ"<< user.getState()<<endl;
			} 
   		else if(caretaker.getsize()==1)
		     {p->setbalance(400);
			 cout<<p->getbalance()<<endl;
			 user.setState(p->getbalance());
			 caretaker.add(user.saveStateToMemento());
			 cout<<"���Ĳ�����ȡ��,�����������Ϊ"<< user.getState()<<endl;
			} 
		else 
		   	 cout<<"������ȡ���ϴβ��������Ƚ������ѻ��ֵ"<<endl;
		cout<<"��������Ҫ���еĲ���"<<endl; 
		break;
	default:
		cout<<"����������������������"<<endl;
   		break;
  } 
  }
   delete p;
   return 0;
}
