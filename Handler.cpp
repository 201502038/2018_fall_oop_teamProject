#include "Handler.h"


Handler:: Handler(Event* _event, string graphAddr) {	//������
	_graph = new Graph(10);
	_graph->makeGraph(graphAddr);	//�׷��� �����
}

Handler:: ~Handler(void) {			//�Ҹ���
	_graph->~Graph();	//�׷��� ����
}



void Handler::allocCost(Event* _event) {
	int size = _event->getSize();
	int totalLength = 0;
	int minLength = 0;
	int totalCost = 0;


	minLength = _graph->findMinWay(_event->getPassenger(0), _event->getPassenger(1));	//�ִ� �Ÿ����
	totalCost = _calculation->calculate_Cost(minLength);	//�� ��ݰ��
	totalLength = _calculation->calculate_totalLength(size, _event, _graph);	//�ѱ��� ���


	for (int i = 0; i < size; i++) {
		int myLength = _graph->originalLength(_event->getPassenger(i));	//���� ��������
		double percent = _calculation->calculate_percent(totalLength, myLength);	//������ �������
		int toPay = _calculation->calculate_Personal_Cost(totalCost, percent);
		_event->eventSetToPay(i, toPay);
	}
}


