#include "User.h"
#include "UserController.h"
#include "UserView.h"
#include "PassengerController.h"
#include "PassengerView.h"

#include <iostream>
int main()
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
		//view.printUser(server, i); 
		i++;
	}
	//�°��� �����Է��� ����.
	PassengerController PassengerController(server.size());

	int _i=0;
	int v = 0;
	//������ ���ڸ�ŭ �°��� �����
	//������ ���ڸ�ŭ �迭�� �ݺ�
	//������ ����ŭ loop
	while (_i < server.size())
	{
		//�°��迭�� index�������ֱ�
		if (PassengerController.passengerControllerUserInfo(server.getList(_i), _i, v))
		{
			v++;
		}
		//������ �ݺ��ؼ� �����Ͽ� �˻�.
		_i++;
	}

	while (true)
	{
		printf("������ �Է����ּ���");
		int use;
		string st;
		string de;

		cin >> use;
		cin >> st;
		cin >> de;

		PassengerController.InputPassenger(server.getList(use), st, de);
		PassengerView passengerView;

		int pa = 0;
		while (pa < PassengerController.size())
		{
			passengerView.printPassenger(PassengerController, pa);
			pa++;
		}
	}
	
	return 0;
}


