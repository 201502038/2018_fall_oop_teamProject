#include "Passenger.h"
#include "Spot.h"
#include <iostream>
#include <string>

using namespace std;
Spot::Spot(string startSpot) {
	passengers.reserve(10);
	setStartSpot(startSpot);
}

bool Spot::addPassenger(Passenger* addedPassenger) {
	try {
		if (check(addedPassenger)) {
			throw "����� ������ ���� �ʽ��ϴ�.";
		}
		passengers.push_back(*addedPassenger);
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
		throw "add was Fail";
	}
	return true;
}

bool Spot::removePassenger(Passenger* removedPassenger)
{
	
	try {
		if (passengers.empty()) {
			throw "���� Passenger�� �����ϴ�.";
		}
		for (int i = 0; i < passengers.size(); i++) {
			if (removedPassenger->getusernumber() == passengers[i].getusernumber()) {
				//passengers.erase(removedPassenger);
			}
		}
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
	}
	return false;
}

Passenger* Spot::getPassengers(string passengerName)
{
	for (int i = 0; i < passengers.size(); i++) {
		if (passengers[i].getName() == passengerName)
			return &passengers[i];
	}
	return nullptr;
}

Passenger* Spot::getPassengers(int i)
{
	return &(passengers.at(i));
}

void Spot::setStartSpot(string _startSpot) {
	startSpot = _startSpot;
}

string Spot::getStartSpot()
{
	return startSpot;
}

int Spot::getNumOfPassengers()
{
	return passengers.size();
}

bool Spot::check(Passenger * added)
{
	if(!strcmp(added->getStartAddr().c_str(), getStartSpot().c_str()))
		return false;
	return true;
}
