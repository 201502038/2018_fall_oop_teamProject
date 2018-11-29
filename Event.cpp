#include "Event.h"
using namespace std;
Event::Event()
{
	size = 0;
}

void Event::eventAddPassenger(Passenger* pass)
{
	Passenger* newPass = new Passenger();
	newPass->setName(pass->getName());
	newPass->setPhoneNumber(pass->getPhoneNumber());
	newPass->setCash(pass->getCash());
	newPass->setusernumber(pass->getusernumber());

	passengerOnTaxi[size] = *newPass;
	size++;
}

void Event::eventOn(Spot* spot)
{
	for (int i = 0; i < size; i++) {
		int userNum = passengerOnTaxi->getusernumber();
		delete spot->getPassengersByNum(userNum);
	}
}

void Event::eventPrint()
{
	cout << "�������� �����߽��ϴ�." << endl;
	for (int i = 0; i < size; i++) {		
		cout << passengerOnTaxi[i].getName() << "��, �����Ͻ� �ݾ���" << passengerOnTaxi[i].getToPay() << "�Դϴ�." << endl;
	}
}

void Event::eventEnd()
{
	for (int i = 0; i < size; i++) {
		delete &passengerOnTaxi[i];
	}
}
