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

	int convertEdge(string loc) {
		
		if (loc == "�����") return 0;
		else if (loc == "����") return 1;
		else if (loc == "������õ��") return 2;
		else if (loc == "������") return 3;
		else if (loc == "ī�̽�Ʈ") return 4;
		
	}

};


#endif // !GRAPH_H
