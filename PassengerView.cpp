#include "stdafx.h"
#include "PassengerView.h"
using namespace std;
#include <iostream>

PassengerView::PassengerView()
{
}


void PassengerView::printPassenger(PassengerController u, int i)
{
	//������ ������ ����Ѵ�.
	cout << " ����� �̸� : " << u.getpassengerList(i).getName() << endl;
	cout << " ����� ��ȭ��ȣ : " << u.getpassengerList(i).getPhoneNumber() << endl;
	cout << " Cash : " << u.getpassengerList(i).getCash() << endl;
	cout << " ����� : " << u.getpassengerList(i).getStartAddr() << endl;
	cout << " ������ : " << u.getpassengerList(i).getdestAddr() << endl;
}

