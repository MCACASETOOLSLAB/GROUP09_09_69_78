                 Producer Consumer Problem with Wait and Notify Example
=======================================================================================================
Producer Consumer Problem is a classical concurrency problem and in fact it is one of the concurrency 
design pattern. In this Java tutorial, I have put the code example of wait notify version of 
earlier producer consumer concurrency design pattern. You can see this is much longer code with explicit 
handling blocking conditions like when shared queue is full and when queue is empty. Since we have replaced
BlockingQueue with Vector we need to implement blocking using wait and notify and that's why we have introduced
produce(int i) and consume() method. If you see I have kept consumer thread little slow by allowing it to sleep 
for 50 Milli second to give an opportunity to producer to fill the queue, which helps to understand that Producer
thread is also waiting when Queue is full.
