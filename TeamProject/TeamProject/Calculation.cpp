#include "Calculation.h"


int Calculation::calculate_Cost(int length) {	//�� ��� ��� �Լ�( 1km�� 900������ ���)
	return 900 * length;
}

int Calculation::calculate_Length(Graph* g, int start, int dest) {
	return g->matrixValue(start, dest);
}


string Calculation::calculate_Compare(int myLength, int howMany, Event* _event, Graph* _graph) {
	int alone = calculate_Cost(myLength);
	int with = 0;

	int dest1_Cost = 0;
	int dest2_Cost = 0;
	int dest3_Cost = 0;
	string start = _event->getPassenger(0)->getStartAddr();


	string dest1 = "";
	
	string dest2 = "";
	
	string dest3 = "";


	int size = howMany;
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

	totalCost = calculate_Cost(minLength);	//�� ��ݰ��
	totalLength = calculate_totalLength(size, _event, _graph);	//�ѱ��� ���
	double percent = calculate_percent(totalLength, myLength);	//������ �������
	
	/*
	dest1_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest1));

	dest2_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest2));

	dest3_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest3));
	*/

	switch (howMany) {
	case 2: 
		dest1 = _event->getPassenger(0)->getDestAddr();
		dest1_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest1));
		with = alone + calculate_Cost(dest1_Cost);
		return ("�Բ����� ������� ������ : " + dest1 + "\n" + "ȥ�ڰ����� ���� ��� : " + to_string(alone) + "\n" + "�Բ������� ���� ��� : " + to_string((int)(totalCost * percent)));
	case 3:
		dest1 = _event->getPassenger(0)->getDestAddr();
		dest2 = _event->getPassenger(1)->getDestAddr();
		dest1_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest1));
		dest2_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest2));
		with = alone + calculate_Cost(dest1_Cost) + calculate_Cost(dest2_Cost);
		return("�Բ����� ������� ������ : " + dest1 + " " + dest2 + "\n" + "ȥ�ڰ����� ���� ��� : " + to_string(alone) + "\n" + "�Բ������� ���� ��� : " + to_string((int)(totalCost * percent)));
	case 4: 
		dest1 = _event->getPassenger(0)->getDestAddr();
		dest2 = _event->getPassenger(1)->getDestAddr();
		dest3 = _event->getPassenger(2)->getDestAddr();
		dest1_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest1));
		dest2_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest2));
		dest3_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest3));
		with = alone + calculate_Cost(dest1_Cost) + calculate_Cost(dest2_Cost) + calculate_Cost(dest3_Cost);
		return("�Բ����� ������� ������ : " + dest1 + " " + dest2 + " " + dest3 + "\n" + "ȥ�ڰ����� ���� ��� : " + to_string(alone) + "\n" + "�Բ������� ���� ��� : " + to_string((int)(totalCost * percent)));
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