//------------------------------------------------------------------------
// Filename: ProducerConsumer.h
// PROGRAM DESCRIPTION
//      definition file for Producer and consumer thread class
//------------------------------------------------------------------------

#ifndef _PROD_CONS_H
#define _PROD_CONS_H
#include "ThreadClass.h"

#define BUFFER_SIZE    5    // bounded buffer size
#define MAX_NUM        20   // maximum number of  producer/consumer 
#define END            -1   // "end of data" sign deposited by the producer

//------------------------------------------------------------------------
// ProducerThread class definition
//------------------------------------------------------------------------

class ProducerThread: public Thread 
{
     public:
          ProducerThread(int No, int numberofdata);
     private:
          void ThreadFunc();
          int Number;
          int NumberOfData;   // number of data to produce
};

//------------------------------------------------------------------------
// ConsumerThread class definition
//------------------------------------------------------------------------
class ConsumerThread: public Thread 
{
     public:
          ConsumerThread(int No);
     private:
          void ThreadFunc();
          int Number;
};

#endif

