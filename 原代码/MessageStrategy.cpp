#include "MessageStrategy.h"
#include <iostream>
#include<string>
#include<cstring>
#include<windows.h>
using namespace std;
MessageStrategy::MessageStrategy()
{
}
MessageStrategy::~MessageStrategy()
{
}
void MessageStrategy::AlgrithmInterface(string message)
{
	
}
MessageStrategy1::MessageStrategy1()
{
}
MessageStrategy1::~MessageStrategy1()
{
}
void MessageStrategy1::AlgrithmInterface(string message)
{
	 MessageBox( NULL , TEXT(message.c_str()) ,
	 TEXT("∂Ã–≈Ã·–—") , MB_ICONINFORMATION|MB_YESNO);
}
MessageStrategy2::MessageStrategy2()
{
}
MessageStrategy2::~MessageStrategy2()
{
}
void MessageStrategy2::AlgrithmInterface(string message)
{
	cout<<message<<endl;
}

