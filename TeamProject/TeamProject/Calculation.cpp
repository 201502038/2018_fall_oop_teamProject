#include "Calculation.h"


int Calculation::calculate_Cost(int length) {	//�� ��� ��� �Լ�( 1km�� 900������ ���)
	return 900 * length;
}

string Calculation::calculate_Compare(int myLength, int howMany, Event* _event, Graph* _graph) {
	int alone = calculate_Cost(myLength);
	int with = calculate_Cost(_graph->findMinWay(_event->getPassenger(0), _event->getPassenger(1),
		_event->getPassenger(2), _event->getPassenger(3)));
	with = with / (_event->getSize());
	
	string dest1  ;
	string dest2  ;
	string dest3 ;
	
	switch (howMany) {
	case 2: dest1 = _event->getPassenger(0)->getDestAddr();
		return ("�Բ����� ������� ������ : " + dest1 + "\n" + "ȥ�ڰ����� ���� ��� : " + to_string(alone) + "\n" + "�Բ������� ���� ��� : " + to_string(with));
	case 3: dest1 = _event->getPassenger(0)->getDestAddr();
		dest2 = _event->getPassenger(1)->getDestAddr();
		return("�Բ����� ������� ������ : " + dest1 + " " + dest2 + "ȥ�ڰ����� ���� ��� : " + to_string(alone) + "\n" + "�Բ������� ���� ��� : " + to_string(with));
	case 4 : dest1 = _event->getPassenger(0)->getDestAddr();
		dest2 = _event->getPassenger(1)->getDestAddr();
		dest3 = _event->getPassenger(2)->getDestAddr();
		return("�Բ����� ������� ������ : " + dest1 + " " + dest2 + " " + dest3 + "\n" + "ȥ�ڰ����� ���� ��� : " + to_string(alone) + "\n" + "�Բ������� ���� ��� : " + to_string(with));
	default:
		return NULL;
	}
}


int Calculation::calculate_Personal_Cost(int total, double percent) {	//���κ� ������ ���� ������ش�.
	double returnValue = total * percent;	//�Ѿ� x ������ �����
	returnValue = floor(returnValue+0.5);	//�ݿø��ؼ� �����Ѵ�.
	return (int)returnValue;	//������ �ݿø��������� ������ �Ǿ����� ����ȯ�ؼ� ��ȯ�Ѵ�.
}

double Calculation::calculate_percent(int total, int mine) {			//���� ������ ���� ���
	return  mine/ ((double)total);
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
		return _graph->originalLength(_event->getPassenger(0)) + _graph->originalLength(_event->getPassenger(1)) +
			_graph->originalLength(_event->getPassenger(2)) + _graph->originalLength(_event->getPassenger(3));
	}
	return 0;
}