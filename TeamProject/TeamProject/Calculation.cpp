#include "Calculation.h"


int Calculation::calculate_Cost(int length) {	//�� ��� ��� �Լ�( 1km�� 900������ ���)
	return 900 * length;
}

double Calculation::alloc_Cost(int total, int length) {	//������ ���� ������ ������ش�.
	return (double)length / total;
}

int Calculation::calculate_Personal_Cost(int total, double percent) {	//���κ� ������ ���� ������ش�.
	double returnValue = total * percent;	//�Ѿ� x ������ �����
	returnValue = floor(returnValue+0.5);	//�ݿø��ؼ� �����Ѵ�.
	return (int)returnValue;	//������ �ݿø��������� ������ �Ǿ����� ����ȯ�ؼ� ��ȯ�Ѵ�.
}

