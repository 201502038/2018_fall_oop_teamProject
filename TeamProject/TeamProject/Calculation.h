#ifndef CALCULATION_H
#define CALCULATION_H


#include "Graph.h"
#include "Event.h"

using namespace std;

class Calculation {
	public:
		int calculate_Cost(int length);	//�� ��� ��� �Լ�
		int calculate_Personal_Cost(int total, double percent);	// ���κ� ������ ���� ������ش�.
		double calculate_percent(int total, int mine);	//������ ���� �������
		int calculate_totalLength(int n, Event* _event, Graph* _graph);	//��ü ���� ���
		string calculate_Compare(int myLength, int howMany, Event* _event, Graph* _graph);	//�Բ�Ż��,ȥ��Ż�� ���ݺ��ؼ� string���·� ��ȯ
		int calculate_Length(Graph* g, int start, int dest);
};

#endif CALCULATION_H