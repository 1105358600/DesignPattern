#include <iostream>
using namespace std;
class Memento{
public:
	Memento(double tstate) { state = tstate; };
	~Memento() {};
	double getState() { return state; };
private:
	double state;
};

