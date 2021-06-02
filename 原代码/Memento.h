#include <iostream>
using namespace std;
class Memento{
	public:
		Memento(double balance);
		Memento& operator=(const Memento &memento) 
		{
		state = memento.state;
		return *this;
		}
		double state;
};
