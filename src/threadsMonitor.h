/*
 * threadsMonitor.h
 *
 *  Created on: 16 gru 2016
 *      Author: piotr
 */

#ifndef THREADSMONITOR_H_
#define THREADSMONITOR_H_

#include "monitor2.h"
#include "settings.h"
#include <iostream>
#include "iterable_queue.h"
using namespace std;


class threadsMonitor : private Monitor {
 public:
 	void producerEnter(int type)
 	{
 		thread::id tid1 = std::this_thread::get_id();
		enter();
		for(int i = 0 ; i < type ; i++)
		{
			if(_queue.size() == QUEUE_SIZE)
				wait(full);

			_queue.push(tid1);
			cout<<"__________P("<<type<<") wrzucilem "<<i + 1<<" raz"<<endl;

			if(_queue.size() == 1)
				signal(empty);
		}
		cout<<"P("<<type<<") "<<tid1<<"\tkoncze"<<endl;
		leave();
	}

 	void consumerEnter(int type)
	{
		thread::id tid2 = std::this_thread::get_id();
		enter();
		for(int i = 0 ; i < type; i++)
		{
			if(_queue.size() == 0)
				wait(empty);

			_queue.pop();
			cout<<"__________C("<<type<<") zdjalem "<<i + 1<<" raz"<<endl;
			if(_queue.size() == QUEUE_SIZE - 1)
				signal(full);
		}
		cout<<"C("<<type<<") "<<tid2<<"\tkoncze"<<endl;
		leave();
	}

 	void monitoringEnter()
 	{
 		enter();
 		if(_queue.size() > 0)
		{
			iterable_queue<std::thread::id>::iterator i;
			printf("\nQueue content:\n");
			if(_queue.size() == QUEUE_SIZE)
				printf("(Queue full)\n");
			for(i = _queue.begin(); i != _queue.end(); i++)
			{
				cout<<*i<<"\t";
			}
			cout<<" elements in the queue, "<<_queue.size()<<"\t ";
			cout<<"Get size: "<<_queue.size()<<endl;
		}
		else
		{
			printf("\nEmpty buffer...\n");
		}
 		leave();
 	}

 	threadsMonitor()
 	{
	}
 private:
	iterable_queue<std::thread::id> _queue;
	Condition full;
	Condition empty;
};


#endif /* THREADSMONITOR_H_ */
