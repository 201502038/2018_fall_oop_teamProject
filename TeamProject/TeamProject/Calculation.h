#ifndef CALCULATION_H
#define CALCULATION_H

#include "Graph.h"
#include "Event.h"

class Calculation {

	public:

		int calculate_Cost(int length);	//�� ��� ��� �Լ�
		int calculate_Personal_Cost(int total, double percent);	// ���κ� ������ ���� ������ش�.
		double calculate_percent(int total, int mine);	//������ ���� �������
		int calculate_totalLength(int n, Event* _event, Graph* _graph);	//��ü ���� ���
};

#endif CALCULATION_H