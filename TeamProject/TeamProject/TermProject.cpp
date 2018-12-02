#include "UserController.h"
#include "UserView.h"
#include "PassengerController.h"
#include "PassengerView.h"
#include "SpotController.h"
#include "SpotView.h"

#include <iostream>

int main()
{
	
	//���Ͽ� �ִ� ������ ������ ����
	UserController* UC = new UserController();
	UserView* UV = new UserView();
	PassengerController* PC = new PassengerController(UC->size());
	PassengerView* PV = new PassengerView();

	for (int i = 0, j = 0; i < UC->size(); i++) {
		if (PC->passengerControllerUserInfo(UC->getList(i), i, j))
			j++;
	}
	//�ٸ� �°����� ������ �����ͺ��̽��� �ִ� ����
	while (true)
	{
		//�ȳ��ϼ���. " "��?
		//������� �������� �Է����ּ���.
		
		printf("������ �Է����ּ���");
		int use = 4;
		string st;
		string de;

		cin >> st;
		cin >> de;

		PC->InputPassenger(UC->getList(use), st, de);
		puts("AA");
		int pa = 0;
		while (pa < PC->size())
		{
			PV->printPassenger(PC, pa);
			pa++;
		}
	}
	
	return 0;
}