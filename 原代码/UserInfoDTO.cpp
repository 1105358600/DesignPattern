#include"Memento.cpp"
using namespace std;
class Memento;
class UserInfoDTO{
 public:
	UserInfoDTO() {};
	~UserInfoDTO() {};
 
	void setState(double tstate) { state = tstate; };
	double getState() { return state; };
	Memento* saveStateToMemento() { return new Memento(state); };
	void getStateFromMemento(Memento *Memento) { state = Memento->getState(); };
private:
	double state;
};
