#include "Calculation.h"


int Calculation::calculate_Cost(int length) {	//�� ��� ��� �Լ�( 1km�� 900������ ���)
	return 900 * length;
}


int Calculation::calculate_Personal_Cost(int total, double percent) {	//���κ� ������ ���� ������ش�.
	double returnValue = total * percent;	//�Ѿ� x ������ �����
	returnValue = floor(returnValue+0.5);	//�ݿø��ؼ� �����Ѵ�.
	return (int)returnValue;	//������ �ݿø��������� ������ �Ǿ����� ����ȯ�ؼ� ��ȯ�Ѵ�.
}

double Calculation::calculate_percent(int total, int mine) {			//���� ������ ���� ���
	return ((double)total) / mine;
}

int Calculation::calculate_totalLength(int n, Event* _event, Graph* _graph) {
	if (n == 2) {
		return _graph->originalLength(_event->getPassenger(0)) + _graph->originalLength(_event->getPassenger(1));
	}
	else if (n == 3) {
		return _graph->originalLength(_event->getPassenger(0)) + _graph->originalLength(_event->getPassenger(1)) +
			_graph->originalLength(_event->getPassenger(2));
	}
	else if (n == 4) {
		_graph->originalLength(_event->getPassenger(0)) + _graph->originalLength(_event->getPassenger(1)) +
			_graph->originalLength(_event->getPassenger(2)) + _graph->originalLength(_event->getPassenger(3));
	}
}