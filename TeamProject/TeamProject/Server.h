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
	SpotView* SV;
	//Event* eve;
	vector<Event> eve;
	string passengerSpot;

public:
	Server();
	void init(); //�����ͺ��̽� �ҷ����� ����
	bool getData(string start, string end); //�⵵���� �Է¹ޱ�

	string proceedBeforeEvent1();

	string sendStartSpotList(Spot* spot); //���� ������� passenger�� "�̸�, �����, ������:�̸�, �����, ������" �̸��� A,B �� ����ó��

	string proceedBeforeEvent2();

	string taxiListOfCost(Event* eve); //���� Ÿ�� ������� �������� ȥ�� ���� �� ��� �� �ݾװ� ���� Ÿ�Ե� ����� �ݾ� //"A:������, B:������, C:������, ȥ�� �ݾ�, ���� Ÿ�� �ݾ�"
	
	//Event
	string proceedEvent();

	void addPassengerToEvent(Passenger * pass);
	void eventOn(Event* eve, string passengerSpot); //����ϰ� �Ǹ� ��� ������ ����Ʈ���� �ش� ����ڵ��� ����
	string eventEnd(Event* eve); //�̸� ����, ~���Խ��ϴ�. "���� ������ �̸�, �� �ݾ�"
};