#ifndef GRAPH_H
#define GRAPH_H

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

	void ViewNeighbors()const;

	void ViewNeighbor(int vt)const;

	Neighbors FindNeighbors(int vt);

	int matrixValue(int i, int j) {
		return matrix[i][j];
	}

	int convertEdge(string loc) {

		if (loc == "�����") return 0;
		else if (loc == "����") return 1;
		else if (loc == "������õ��") return 2;
		else if (loc == "ī�̽�Ʈ") return 3;
		else if (loc == "����") return 4;
		else if (loc == "�����Ű����") return 5;
		else if (loc == "�����͹̳�") return 6;
		else if (loc == "���ൿ") return 7;
		else if (loc == "�л굿") return 8;
		else if (loc == "������") return 9;
	}

	Graph* makeGraph(string addr);

	//int Graph::findMinWay(int start, Passenger* ps, Passenger* ps1);

	int findMinWay(int start, int dest1, int dest2);

	int findMinWay(int start, int dest1, int dest2, int dest3);

	int findMinWay(int start, int dest1, int dest2, int dest3, int dest4);


	


	int findMin(int arr[], int size) {
		int min = arr[0];
		for (int i = 0; i < size; i++) {
			if (min > arr[i]) min = arr[i];
		}	//�ּҰŸ� ã��

		for (int i = 0; i < size; i++) {
			if (arr[i] == min) return i;	//�� �ε��� ��ȯ
		}
		return 0;
	}

};


#endif // !GRAPH_H
