/*
 * consumerMonitor.h
 *
 *  Created on: 7 sty 2017
 *      Author: piotr
 */

#ifndef SRC_CONSUMERMONITOR_H_
#define SRC_CONSUMERMONITOR_H_

#include "monitor2.h"
#include "threadsMonitor.h"
#include "settings.h"
#include <iostream>
using namespace std;

class consumerMonitor : private Monitor {
 public:
 	void consumerEnter(int type)
	{
		enter();
		threadsMonitorPtr->consumerEnter(type);
		leave();
	}

 	consumerMonitor(threadsMonitor * accessMonitor)
	{
 		threadsMonitorPtr = accessMonitor;
	}
 private:
 	threadsMonitor * threadsMonitorPtr;
};


#endif /* SRC_CONSUMERMONITOR_H_ */
