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
   Account* p = new Account("�û�",400); 
   UserInfoDTO user;
   Caretaker caretaker;
   user.setState(p->getbalance());
   AccountState*state=new GreenState(0,p);
   Observer*Ob = new Observer();
   Ob->Attach(p);
   string s="������ʾ,���Գ������߹������Ϣ���𾴵��û��������ڽ��й����ǰ��2���ײ����������У������Ʊ������ĲƲ���Ϣ";
   Ob->notify(s); //����MessageBox����ʾ��Ϣ
   Supermarket* d1 = Supermarket::Instance();
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
   	 	cout<<"������Ŀǰ�ṩ����2�������ײ����߹���"<<endl;
  	 	d1->Construct(new ConcreteBuilder1());
  	 	cout<<"�ײ�һ�۸�200Ԫ"<<endl; 
   	 	cout<<endl; 
   	 	d1->Construct(new ConcreteBuilder2());
   	 	cout<<"�ײͶ��۸�250Ԫ"<<endl;
		cout<<endl;  
   	 	d1->Construct(new ConcreteBuilder3());
  	 	cout<<"�ײ�һ�۸�300Ԫ"<<endl;
		cout<<endl;
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
		}
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
		for(i=0;i<=caretaker.getsize()+1;i++)
		{
		user.getStateFromMemento(caretaker.get(i));
		cout<<"��"<<i+1<<"�����䶯��¼�����Ϊ" << user.getState() << endl;
		 } 
		 cout<<"��������Ҫ���еĲ���"<<endl;
   		break;
   	case 5:
   		cout<<"���Ĳ�����ȡ��,�����������Ϊ"<< user.getState()<<endl;
   		user.getStateFromMemento(caretaker.get(caretaker.getsize()));
		p->setbalance(user.getState());
		cout<<p->getbalance()<<endl;
		cout<<"��������Ҫ���еĲ���"<<endl; 
		break;	
  } 
  }
   delete Ob;
   delete p;
   return 0;
}
