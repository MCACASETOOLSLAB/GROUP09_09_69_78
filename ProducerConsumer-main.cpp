//------------------------------------------------------------------------
// Filename:    ProducerConsumer-main.cpp
// PROGRAM DESCRIPTION
//     This program uses semaphores to solve the producer/consumer problem
//------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "ProducerConsumer.h"

//------------------------------------------------------------------------
// main() function
//------------------------------------------------------------------------

int main(int argc, char *argv[])
{
  	ProducerThread *Producerthread[MAX_NUM];
     ConsumerThread *Consumerthread[MAX_NUM];
     int NumberOfThreads;
     int NumberOfData;
     int i;

     if (argc != 3) {
     	cout << "Usage " << argv[0]
               << " #-of-producers/consumers #-of-data-items" << endl;
        exit(0);
     }
     else {
       
     	NumberOfThreads = abs(atoi(argv[1]));
        NumberOfData    = abs(atoi(argv[2]));
     }

     if (NumberOfThreads > MAX_NUM) {        // verify user's input
     	cout << "The number of producers/consumers should be less than "
               << MAX_NUM << endl;
        exit(0);
     }

     srand((unsigned int) time(NULL));       // initialize random seed

     for (i = 0; i < NumberOfThreads; i++) {  // create producers
         Producerthread[i] = new ProducerThread(i, NumberOfData);
         Producerthread[i]->Begin();
     }

     for (i = 0; i < NumberOfThreads; i++) { // create consumers
         Consumerthread[i] = new ConsumerThread(i);
         Consumerthread[i]->Begin();
     }

     for (i=0; i < NumberOfThreads; i++) {   // join with all children
         Producerthread[i]->Join();
         Consumerthread[i]->Join();
     }
     
     Exit();
     
     return 0;
}


