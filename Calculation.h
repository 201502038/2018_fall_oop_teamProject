#ifndef CALCULATION_H
#define CALCULATION_H

#include "Graph.h"

class Calculation {

	public:

		int calculate_Cost(int length);	//�� ��� ��� �Լ�
		double alloc_Cost(int total, int length);	//������ ���� ������ ������ش�.
		int calculate_Personal_Cost(int total, double percent);	// ���κ� ������ ���� ������ش�.
};

#endif CALCULATION_H