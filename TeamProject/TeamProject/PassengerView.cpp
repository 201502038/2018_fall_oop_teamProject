#include "PassengerView.h"
using namespace std;
#include <iostream>

PassengerView::PassengerView()
{
}


void PassengerView::printPassenger(PassengerController u, int i)
{
	//������ ������ ����Ѵ�.
	cout << " ����� �̸� : " << u.getPassengerList(i)->getName() << endl;
	cout << " ����� ��ȭ��ȣ : " << u.getPassengerList(i)->getPhoneNumber() << endl;
	cout << " Cash : " << u.getPassengerList(i)->getCash() << endl;
	cout << " ����� : " << u.getPassengerList(i)->getStartAddr() << endl;
	cout << " ������ : " << u.getPassengerList(i)->getDestAddr() << endl;
}

