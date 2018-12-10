#include "Handler.h"


Handler:: Handler(Event* event, string graphAddr) {	//������
	Graph* forMake = new Graph(10);
	_graph = forMake->makeGraph(graphAddr);	//�׷��� �����
	_event = event;
	_calculation = new Calculation();
}

Handler:: ~Handler(void) {			//�Ҹ���
	_graph->~Graph();	//�׷��� ����
}


void Handler::allocCost(Event* _event) {
	int size = _event->getSize();
	int totalLength = 0;
	int minLength = 0;
	int totalCost = 0;

	if (size == 2) {
		minLength = _graph->findMinWay(_event->getPassenger(0), _event->getPassenger(1));	//�ִ� �Ÿ����
	}
	else if (size == 3) {
		minLength = _graph->findMinWay(_event->getPassenger(0), _event->getPassenger(1), _event->getPassenger(2));	//�ִ� �Ÿ����
	}
	else {
		minLength = _graph->findMinWay(_event->getPassenger(0), _event->getPassenger(1), _event->getPassenger(2),
			_event->getPassenger(3));	//�ִ� �Ÿ����
	}

	totalCost = _calculation->calculate_Cost(minLength);	//�� ��ݰ��
	totalLength = _calculation->calculate_totalLength(size, _event, _graph);	//�ѱ��� ���


	for (int i = 0; i < size; i++) {
		int myLength = _graph->originalLength(_event->getPassenger(i));	//���� ��������
		double percent = _calculation->calculate_percent(totalLength, myLength);	//������ �������
		int toPay = _calculation->calculate_Personal_Cost(totalCost, percent);
		
		_event->eventSetToPay(i, toPay);	//passenger�� topay�� �־��ش�.
	}
}


