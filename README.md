                      Producer Consumer Problem with Wait and Notify
=======================================================================================================
The producer–consumer problem (also known as the bounded-buffer problem) is a classic example of a multi-process 
synchronization problem. The problem describes two processes, the producer and the consumer, who share a common, 
fixed-size buffer used as a queue. The producer's job is to generate a piece of data, put it into the buffer and 
start again. At the same time, the consumer is consuming the data (i.e., removing it from the buffer) one piece at 
a time. The problem is to make sure that the producer won't try to add data into the buffer if it's full and that the
consumer won't try to remove data from an empty buffer.

   The solution for the producer is to either go to sleep or discard data if the buffer is full. The next time the 
consumer removes an item from the buffer, it notifies the producer, who starts to fill the buffer again. 
In the same way, the consumer can go to sleep if it finds the buffer to be empty. The next time the producer puts data 
into the buffer, it wakes up the sleeping consumer. The solution can be reached by means of inter-process communication,
typically using semaphores. An inadequate solution could result in a deadlock where both processes are waiting to
be awakened. The problem can also be generalized to have multiple producers and consumers.

   Producer Consumer Problem is a classical concurrency problem and in fact it is one of the concurrency 
design pattern. In this Java program, we have put the code of wait notify of producer
consumer concurrency design pattern. You can see this is much longer code with explicit handling 
blocking conditions like when shared queue is full and when queue is empty. Since we have replaced
BlockingQueue with Vector we need to implement blocking using wait and notify and that's why we have introduced
produce(int i) and consume() method. If you see we have kept consumer thread little slow by allowing it to sleep 
for 50 Milli second to give an opportunity to producer to fill the queue, which helps to understand that Producer
thread is also waiting when Queue is full.
