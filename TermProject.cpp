// TermProject.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
#include "stdafx.h"
#include "User.h"
#include "UserController.h"
#include "UserView.h"
#include "PassengerController.h"
#include "PassengerView.h"
#include "SpotController.h"
#include "Spot.h"
#include "SpotView.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//���Ͽ� �ִ� ������ ������ ����
	UserController server;
	server.ControllerUserInfo();
	//�°��� �����ϴ� �Լ�
	//server.find();
	UserView view;
	int i=0;

	while (i<5)
	{
		view.printUser(server, i); 
		i++;
	}
	//�°��� �����Է��� ����.

	
	PassengerController PassengerController;
	int _i=0;
	int v = 0;
	//������ ���ڸ�ŭ �°��� �����
	//������ ���ڸ�ŭ �迭�� �ݺ�

	//������ ����ŭ loop
	while (_i < server.userSize())
	{
		//�°��迭�� index�������ֱ�
		if (PassengerController.passengerControllerUserInfo(server.getList(_i), _i, v))
		{
			v++;
		}
		//������ �ݺ��ؼ� �����Ͽ� �˻�.
		_i++;
	}

	//�°��� ������ ������ �� �ִ� �޼ҵ�
	//PassengerController.getpassengerList(0);

	PassengerView passengerView;

	int pa = 0;
	while (pa < PassengerController.returnSize())
	{
		passengerView.printPassenger(PassengerController,pa);
		pa++;
	}
	//�°��� ������ ������ȣ������ �Էµȴٰ� �����մϴ�.
	SpotController spotController;
	SpotView spotView;
	
	spotController.addSpot("����");
	spotController.getSpot("����")->addPassenger(PassengerController.getPassengerList(0));
	spotView.printStartSpot(spotController.getSpot("����"));
	
	spotView.printPassengers(spotController.getSpot("����"), 0);
	system("pause");
	return 0;
}

