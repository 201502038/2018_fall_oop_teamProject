#ifndef SPOTCONTROLLER_H
#define SPOTCONTROLLER_H
#include "Spot.h"
#include "Passenger.h"
#include "string"

using namespace std;
class SpotController {
public:
	SpotController();
	Spot* getSpot(string startSpot);
	Spot* getSpot(int index);
	void addPassenger(Passenger* pass);
	void deleteSpot(Spot* _spot);
	void printAllSpot();
	int getSize();
	bool SpotContain(string s);
private:
	vector<Spot> spots;
	vector<Passenger> passengers;
	string spotList[10] = {"�����","����","������õ��","ī�̽�Ʈ","������","�����͹̳�","�����Ű����","����","���ൿ","�л굿"};
};
#endif