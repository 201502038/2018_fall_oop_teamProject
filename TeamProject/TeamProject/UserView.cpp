#include "stdafx.h"
#include "UserView.h"
#include "UserController.h"
#include <iostream>

using namespace std;

UserView::UserView()
{

}
void UserView::printUser(UserController u,int i)
{
	//������ ������ ����Ѵ�.
			cout <<" ����� �̸� : " << u.getList(i).getName() << endl;
			cout << " ����� ��ȭ��ȣ : " << u.getList(i).getPhoneNumber() << endl;
			cout << " Cash : " << u.getList(i).getCash() << endl;
}


