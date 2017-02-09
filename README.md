# monitor_synchro
Implementation of threads synchronization in producer-consumer problem using monitor in C++.

The buffer in this task is cyclic-buffer of thread_id values with defined size (15 default), which is shared between consumer and producer threads.

There are 3 producer threads (although algorithm is general), which push their thread id's into the buffer in the following way:
- first producer writes one thread_id to the buffer
- second producer writes two thread_ids to the buffer
- third producer writes three thread_ids to the buffer
- (etc.)

There are 5 consumers (although algorithm is general), which pull thread_ids from buffer, as in the case of producers:
- first consumer consumes one thread_id
- second consumer consumes two thread_ids
- etc.

Pushing and pulling from buffer must be kept in order, in which particular threads came to the critical section e.g. if 
double producer was first in the critical section, other producer thread must not get into buffer and must wait for double producer to finish its work.
Consumer threads must behaves like producer threads - only one consumer can pull from buffer, until it is fed up, and then the next in the queue can start consume.

