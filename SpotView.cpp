#include "SpotView.h"
#include <iostream>
using namespace std;

void SpotView:: printStartSpot(Spot spot) {
	cout << "��� ��Ҵ� : " << spot.getStartSpot() << endl;
}

void SpotView::printPassengers(Spot spot, int i)
{
	cout << i << "��° �°��� �̸��� : " << spot.getPassengers(i).getName << endl;
}
