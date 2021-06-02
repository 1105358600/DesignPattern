#ifndef _MESSAGESTRATEGY_H_
#define _MESSAGESTRATEGY_H_
#include<string>
#include <cstring>
using namespace std;
class MessageStrategy
{
	public:
		MessageStrategy();
        virtual ~MessageStrategy();
        virtual void AlgrithmInterface(string message)=0;
    protected:
    private:
};
class MessageStrategy1:public MessageStrategy
{
	public:
        MessageStrategy1();
        virtual ~MessageStrategy1();
        void AlgrithmInterface(string message);
    protected:
    private:
};
class MessageStrategy2:public MessageStrategy
{
	public:
        MessageStrategy2();
        virtual ~MessageStrategy2();
        void AlgrithmInterface(string message);
    protected:
    private:
};
#endif //_MESSAGESTRATEGY_H_

