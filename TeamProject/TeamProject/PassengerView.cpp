#include "PassengerView.h"
using namespace std;
#include <iostream>

PassengerView::PassengerView()
{
}

//�°��� ������ ���: "������̸�,����� ��ȭ��ȣ,Cash,�����,������"
string PassengerView::printPassenger(PassengerController* u, int i)
{
	string result = "";
	result += u->getPassengerList(i)->getName() + ",";
	result +=  u->getPassengerList(i)->getPhoneNumber() + ",";
	result += u->getPassengerList(i)->getCash() + ",";
	result += u->getPassengerList(i)->getStartAddr() + ",";
	result += u->getPassengerList(i)->getDestAddr();

	return result;
}

