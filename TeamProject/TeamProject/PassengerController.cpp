#include <fstream>
#include <iostream>
#include "PassengerController.h"
#include "UserController.h"

using namespace std;

//���� �°����� ���ε�
PassengerController::PassengerController(int size)
{
	fstream infile;
	string _startAddr;
	string _destAddr;
	string name;
	_size = 0;
	int i = 0;
	infile.open("passenger.txt");
	while (!infile.eof())
	{
		Passenger passenger;
		getline(infile, name, '\n');
		if (!strcmp(name.c_str(),"NULL"))
		{
			passengerData.insert(passengerData.begin() + i, passenger);
			i++;
			continue;
		}
		getline(infile, _startAddr, '\n');
		passenger.setStartAddr(_startAddr);
		getline(infile, _destAddr, '\n');
		passenger.setDestAddr(_destAddr);
		passengerData.insert(passengerData.begin() + i, passenger);
		i++;
	}

	passengerData.reserve(size);
}

//user�� ������ �޾� �°��� �����ϴ� ����
bool PassengerController::passengerControllerUserInfo(User* user,int i,int v)
{
		Passenger passenger(*user);
		
		if (passengerData.at(i).getStartAddr() == "")
		{
			return false;
		}
		passenger.setStartAddr(passengerData.at(i).getStartAddr());

		passenger.setDestAddr(passengerData.at(i).getDestAddr());

		passengerList.insert(passengerList.begin()+v, passenger);

		_size++;
		return true;
}

//�°�����Ʈ�� �ٸ� Ŭ������ �����ϱ� ���� �Լ�
Passenger* PassengerController::getPassengerList(int i)
{
	return &passengerList.at(i);
}

//UI���� �°��� ������ �Է¹ޱ� ���� �Լ�
void PassengerController::InputPassenger(User* user, string start, string dest)
{
	Passenger passenger(*user);
	int boolean = 0;
	passenger.setStartAddr(start);
	passenger.setDestAddr(dest);
	//������ȣ�� �°� �Էµ� ������ �����Ѵ�.
	passengerData.insert(passengerData.begin() + user->getusernumber(), passenger);
		for (int i = 0; i < passengerList.size();i++)
		{
			if (passengerList.at(i).getusernumber() == user->getusernumber())
			{
				passengerList.erase(passengerList.begin() + i);
				passengerList.insert(passengerList.begin() + i, passenger);
				boolean = 1;
			}
		}
		if (boolean == 0){
			_size++;
			passengerList.push_back(passenger);
		}
}

string PassengerController::printPassenger(PassengerController* u, int i)
{
	string result = "";
	result += u->getPassengerList(i)->getName() + ",";
	result += u->getPassengerList(i)->getPhoneNumber() + ",";
	result += u->getPassengerList(i)->getCash() + ",";
	result += u->getPassengerList(i)->getStartAddr() + ",";
	result += u->getPassengerList(i)->getDestAddr();

	return result;
}