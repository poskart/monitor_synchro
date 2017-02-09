/*
 * producerMonitor.h
 *
 *  Created on: 7 sty 2017
 *      Author: piotr
 */

#ifndef SRC_PRODUCERMONITOR_H_
#define SRC_PRODUCERMONITOR_H_


#include "monitor2.h"
#include "threadsMonitor.h"
#include "settings.h"
#include <iostream>
using namespace std;

class producerMonitor : private Monitor {
 public:
 	void producerEnter(int type)
 	{
		enter();
		threadsMonitorPtr->producerEnter(type);
		leave();
	}

 	producerMonitor(threadsMonitor * accessMonitor)
	{
 		threadsMonitorPtr = accessMonitor;
	}
 private:
	threadsMonitor * threadsMonitorPtr;
};


#endif /* SRC_PRODUCERMONITOR_H_ */
