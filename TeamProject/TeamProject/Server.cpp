#include "Server.h"
#include <iostream>
using namespace std;
int userNum = 4;

Server::Server()
{
	UC = new UserController();
	PC = new PassengerController(UC->size());
	SC = new SpotController();
	eve.reserve(0);
}

void Server::init()
{
	for (int i = 0, j = 0; i < UC->size(); i++) {
		if (PC->passengerControllerUserInfo(UC->getList(i), i, j))
			//�ԷµǴ� �°��� ��
			j++;
	}
	for (int i = 0; i < PC->size(); i++) {
		SC->addPassenger(PC->getPassengerList(i));
	}
	SC->printAllSpot();
	//�ٸ� �°����� ������ �����ͺ��̽��� �ִ� ����
}
bool Server::getData(string start, string end)
{
	//�ȳ��ϼ���. " "��?
	//������� �������� �Է����ּ���.
	cout << userNum;
	PC->InputPassenger(UC->getList(userNum), start, end);
	//����� ������ �Է¹ް�,
	
	Passenger *passenger = new Passenger(UC->getList(userNum));

	passenger->setStartAddr(start);
	passenger->setDestAddr(end);

	SC->addPassenger(passenger);
	
	passengerSpot = start;

	return true;
}

string Server::proceedEvent()
{
	Spot* tempSpot = SC->getSpot(passengerSpot);
	//addPassengerToEvent(SC->getSpot(passengerSpot)->getPassengersByUserNum(userNum));
	for (unsigned int i = 0; i < tempSpot->getNumberOfPassenger() && i < 4; i++) {
		if (tempSpot->getPassengers(i)->getusernumber() != userNum)
			addPassengerToEvent(tempSpot->getPassengers(i));
		else //����
			i--;
	}
	int temp = 0;
	for (unsigned int i = 0; i < eve.size(); i++)
	{
		if (eve.at(i).getPassengerByUserNum(userNum)->getusernumber() == userNum) {
			temp = i;
		}
	}
	eventOn(&eve.at(temp), passengerSpot);
	return eventEnd(&eve.at(temp));
}

void Server::addPassengerToEvent(Passenger *pass)
{
	for (unsigned int i=0;i<eve.size();i++)
	{	
		//�� �̺�Ʈ�̸� �°��� ����
		if (eve.at(i).getSize() == 0)
		{
			eve.at(i).eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(0));
			return;
		}
		else //�°��� ������� Ȯ���Ͽ� ������ ����
		{
			if ((eve.at(i).getPassenger(0)->getStartAddr() == pass->getStartAddr()) && eve.at(i).getSize() != 4 )
			{
				eve.at(i).eventAddPassenger(pass);
				return;
			}			
		}
	}
	Event _eve;
	_eve.eventAddPassenger(pass);
	eve.push_back(_eve);
}
void Server::eventOn(Event* eve, string passengerSpot)
{
	eve->eventOn(SC->getSpot(passengerSpot));
}

string Server::eventEnd(Event* eve)
{
	string temp = eve->eventPrint(userNum);
	eve->eventEnd();
	return temp;
}

string Server::proceedBeforeEvent1()
{
	cout << passengerSpot;
	string result = sendStartSpotList(SC->getSpot(passengerSpot));
	return result;
}

string Server::sendStartSpotList(Spot *spot) //"�����:�°�A,������:�°�B,������,"
{
	string result = "";
	for (unsigned int i = 0; i < spot->getNumberOfPassenger(); i++) {
		result += spot->getPassengers(i)->getName() + ",";
		result += spot->getStartSpot() + ",";
		result += spot->getPassengers(i)->getDestAddr() + ":";
	}
	return result;
}

string Server::proceedBeforeEvent2()
{
	int temp = 0;
	for (unsigned int i = 0; i<eve.size(); i++)
	{
		if (eve.at(i).getPassengerByUserNum(userNum)->getusernumber() == userNum) {
			temp = i;
		}
	}
	string result = taxiListOfCost(&eve.at(temp));
	return result;
}

string Server::taxiListOfCost(Event* eve)
{
	Handler HD(eve, "C://Users//arabi//Desktop//Graph.txt");
	string s = HD._calculation->calculate_Compare(HD._graph->originalLength(eve->getPassengerByUserNum(userNum)), eve->getSize()+1 , eve, HD._graph);
	return s;
}

void Server::makeEvent()
{
	for (int i = 0; i < SC->getSize(); i++) {
		int j = ceil( double(SC->getSpot(i)->getNumberOfPassenger()) / 2);
		for (int k = 0; k < j; k++) {
			addPassengerToEvent(SC->getSpot(i)->getPassengers(k));
		}
	}
	addPassengerToEvent(SC->getSpot(passengerSpot)->getPassengersByUserNum(userNum));
}
