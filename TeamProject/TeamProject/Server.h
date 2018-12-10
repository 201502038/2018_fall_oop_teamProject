#pragma once
#include "UserController.h"
#include "PassengerController.h"
#include "SpotController.h"
#include "SpotView.h"
#include "Handler.h"
#include <iostream>

class Server
{
private:
	UserController* UC;
	PassengerController* PC;
	SpotController* SC;
	vector<Event> eve;
	string passengerSpot;
	string sendStartSpotList(Spot* spot); //���� ������� passenger�� "�̸�, �����, ������:�̸�, �����, ������" �̸��� A,B �� ����ó��
	string taxiListOfCost(Event* eve); //���� Ÿ�� ������� �������� ȥ�� ���� �� ��� �� �ݾװ� ���� Ÿ�Ե� ����� �ݾ� //"A:������, B:������, C:������, ȥ�� �ݾ�, ���� Ÿ�� �ݾ�"
	void addPassengerToEvent(Passenger * pass);
	void addPaseengerToEvent(Passenger* pass, Event* _eve);
	void eventOn(Event* eve, string passengerSpot); //����ϰ� �Ǹ� ��� ������ ����Ʈ���� �ش� ����ڵ��� ����
	string eventEnd(Event* eve); //�̸� ����, ~���Խ��ϴ�. "���� ������ �̸�, �� �ݾ�"

public:
	Server();
	void init(); //�����ͺ��̽� �ҷ����� ����
	int getData(string start, string end); //�⵵���� �Է¹ޱ�

	string proceedBeforeEvent1();
	int numOfList();

	string proceedBeforeEvent2();
	
	void makeEvent();
	void makeEvent2();
	
	//Event
	string proceedEvent();

	
};