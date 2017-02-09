//============================================================================
// Name        : Monitor.cpp
// Author      : Piotr Poskart
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "threadsMonitor.h"
#include "producerMonitor.h"
#include "consumerMonitor.h"
using namespace std;

threadsMonitor mon;
producerMonitor prodMon(&mon);
consumerMonitor consMon(&mon);

void producerTask(int type)
{
	for(int i = 0 ; i < 20; i++)
	{
		prodMon.producerEnter(type);
		sleep(1);
	}
}

void consumerTask(int type)
{
	for(int i = 0 ; i < 20; i++)
	{
		consMon.consumerEnter(type);
		sleep(1);
	}
}

//key_t Semafor::sem_counter = 0;

int main(int argc, char *argv[])
{

	std::thread p1(producerTask, 1);
	std::thread p2(producerTask, 2);
	std::thread p3(producerTask, 3);

	std::thread c1(consumerTask, 1);
	std::thread c2(consumerTask, 2);
	std::thread c3(consumerTask, 3);
	std::thread c4(consumerTask, 4);
	std::thread c5(consumerTask, 5);

	for(int i = 0 ; i < 100 ; i++)
	{
		mon.monitoringEnter();
		sleep(1);
	}

	p1.join();
	p2.join();
	p3.join();

	c1.join();
	c2.join();
	c3.join();
	c4.join();
	c5.join();

	return 0;
}

