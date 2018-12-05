#include "Server.h"
#include <iostream>

using namespace std;

int main()
{
	while (true)
	{
		int pa = 0;
		while (pa < PC->size())
		{
			PV->printPassenger(PC, pa);
			pa++;
		}
		//puts("���� ���� ������� �ִ� ����� ��� ����մϴ�.");
		Event* eve = new Event();

		string passengerSpot = "�����";
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(0));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(1));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(2));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(3));
		//�Է��� ������� ���� ������� �°����� event�� 4����� �߰���
		
		Handler* HD = new Handler(eve, "Graph.txt");

		//����ڿ��� �����ִ� 
		string s = HD->_calculation->calculate_Compare(HD->_graph->originalLength(eve->getPassenger(3)), 4, eve, HD->_graph);
		cout << s << endl;
		puts("������ ����Ʈ �Դϴ�. ž���Ͻðڽ��ϱ�?");
		if (true) {
			eve->eventOn(SC->getSpot(passengerSpot));
			eve->eventPrint(0);
			eve->eventEnd();
		}
	}
	return 0;
}

Server::Server()
{
	UserController* UC = new UserController();
	UserView* UV = new UserView();
	PassengerController* PC = new PassengerController(UC->size());
	PassengerView* PV = new PassengerView();
	SpotController* SC = new SpotController();
	SpotView* SV = new SpotView();
}

void Server::init()
{
	for (int i = 0, j = 0; i < UC->size(); i++) {
		if (PC->passengerControllerUserInfo(UC->getList(i), i, j))
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
	int use = 4;

	PC->InputPassenger(UC->getList(use), start, end);
	
	//����� ������ �Է¹ް�,
	return true;
}

void Server::eventOn(Event* eve,string passengerSpot)
{
	eve->eventOn(SC->getSpot(passengerSpot));
}

string Server::eventEnd(Event* eve)
{
	eve->eventPrint(0);
	eve->eventEnd();
}
