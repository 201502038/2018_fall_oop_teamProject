#ifndef GRAPH_H
#define GRAPH_H
#include "Passenger.h"

#include <string>
#include <fstream>

#include <iostream>

#include <vector>

using namespace std;

typedef vector<int> Neighbors;

class Graph

{

	const int vn;//������ ����
	int **matrix;//���� ��� 
	 

public: 

	Graph(int vn);		//Graph ������

	~Graph(void);		//Graph �Ҹ���

	void AddEdge(string start, string goal, int dist);//���� �߰�

	int matrixValue(int i, int j);		//�׷����� ��ȯ

	int convertEdge(string loc);		//string ������ �޾Ƽ� �ε����� ��ȯ

	Graph* makeGraph(string addr);		//�׷��� ������ִ� �Լ�


	int findMinWay(Passenger* p1, Passenger* p2);	
	int findMinWay(Passenger* p1, Passenger* p2, Passenger* p3);
	int findMinWay(Passenger* p1, Passenger* p2, Passenger* p3, Passenger* p4);
	
	int findMin(int arr[], int size);		//�ּҰ��� ã���ִ� �Լ�

	int originalLength(Passenger* ps);		//���� ������ ���� �����ִ� �Լ�
};


#endif // !GRAPH_H
