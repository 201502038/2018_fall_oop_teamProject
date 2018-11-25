#include "SpotController.h"
#include <cstring>

SpotController::SpotController() {
	spots.reserve(10);
	passengers.reserve(10);
}

bool SpotController::addSpot(char* startSpot) {
	try {
		if (strcmp(startSpot, NULL)) {
			throw "�ùٸ��� ���� ��� ����Դϴ�.";
		}
		Spot *addedSpot = new Spot(startSpot);
		spots.push_back(*addedSpot);
	}
	catch (string errorStr) {
		cout << errorStr << endl;
	}
}

Spot SpotController::getSpot(char* startSpot) {
	try {
		for (int i = 0; i < spots.size(); i++) {
			if (!(strcmp(spots[i].getStartSpot, startSpot))) {
				Spot temp = spots[i];
				//Spots.erase(i);
				return temp;
			}
		}
		throw "�ش��ϴ� ������� Spot�� �����ϴ�.";
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
	}
}