#ifndef HANDLER_H
#define HANDLER_H

#include "Graph.h"
#include "Calculation.h"
#include "Event.h"

class Handler {
	
	


public:
	Calculation * _calculation;
	Graph * _graph;
	Event* _event;

	Handler(Event* _event, string graphAddr); //������

	~Handler(void);			//�Ҹ���

	void allocCost(Event* _event);

};

#endif







