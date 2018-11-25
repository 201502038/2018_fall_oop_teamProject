#include "SpotController.h"
#include <cstring>

SpotController::SpotController() {
	spots.reserve(10);
	passengers.reserve(10);
}

bool SpotController::addSpot(string startSpot) {
	try {
		if (!isContain(startSpot)) {
			throw "�ùٸ��� ���� ��� ����Դϴ�.";
		}
		Spot *addedSpot = new Spot(startSpot);
		spots.push_back(*addedSpot);
	}
	catch (string errorStr) {
		cout << errorStr << endl;
	}
}

Spot SpotController::getSpot(string startSpot) {
	try {
		for (int i = 0; i < spots.size(); i++) {
			if (isContain(startSpot)) {
				return spots[i];
			}
		}
		throw "�ش��ϴ� ������� Spot�� �����ϴ�.";
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
	}
}

bool SpotController::isContain(string startSpot)
{
	for (int i = 0; i < spots.size(); i++) {
		if (!strcmp(startSpot.c_str(), spots[i].getStartSpot().c_str())) {
			return true;
		}
	}
	return false;
}

