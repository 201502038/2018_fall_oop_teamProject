#pragma once
#include "UserController.h"
#include "UserView.h"
#include "PassengerController.h"
#include "PassengerView.h"
#include "SpotController.h"
#include "SpotView.h"
#include "Handler.h"
#include <iostream>

class Server
{
private:
	UserController* UC;
	UserView* UV;
	PassengerController* PC;
	PassengerView* PV;
	SpotController* SC;
	SpotView* SV;

public:
	Server();
	~Server();
	void init(); //�����ͺ��̽� �ҷ����� ����
	bool getData(string start, string end); //�⵵���� �Է¹ޱ�
	void eventOn(Event * eve);
	string showStartSpotList(); //���� ������� passenger�� "�̸�, �����, ������:�̸�, �����, ������" �̸��� A,B �� ����ó��
	bool OK(); //��¿� ���ؼ��� IO���� ó��, IO�κ��� Y�� ������ return true
	Event makeEvent();
	string taxiListOfCost(); //���� Ÿ�� ������� �������� ȥ�� ���� �� ��� �� �ݾװ� ���� Ÿ�Ե� ����� �ݾ�						   //"A:������, B:������, C:������, ȥ�� �ݾ�, ���� Ÿ�� �ݾ�"
	void eventOn(Event* eve, string passengerSpot); //����ϰ� �Ǹ� ��� ������ ����Ʈ���� �ش� ����ڵ��� ����
	string eventEnd(Event* eve); //�̸� ����, ~���Խ��ϴ�. "���� ������ �̸�, �� �ݾ�"

};


