//------------------------------------------------------------------------
// Filename:     ProducerConsumer.cpp
// PROGRAM DESCRIPTION
//     This program uses semaphores to solve the producer-consumer problem
//------------------------------------------------------------------------

#include <iostream>

#include "ProducerConsumer.h"

// static data variable
static int Buffer[BUFFER_SIZE]; // the buffer
static int In  = 0;                             // next empty slot in the buffer
static int Out = 0;                             // next available data slot

static Semaphore NotFull("NotFull", BUFFER_SIZE);
static Semaphore NotEmpty("NotEmpty", 0);
static Semaphore BufferLock("BufferLock", 1);   // lock protecting the buffer

// -----------------------------------------------------------------------
// FUNCTION  Filler():
//    This function fills a strstream with spaces.
// -----------------------------------------------------------------------

strstream *Filler(int n)
{
     int  i;
     strstream *Space;

     Space = new strstream;
     for (i = 0; i < n; i++)
        (*Space) << ' ';
     (*Space) << '\0';
     return Space;
}

//------------------------------------------------------------------------
// ProducerThread::ProducerThread()
//      constructor for ProducerThread class
//------------------------------------------------------------------------

ProducerThread::ProducerThread(int No, int numberofdata)
               : Number(No), NumberOfData(numberofdata)
{
     ThreadName.seekp(0, ios::beg);
     ThreadName << "Producer" << No << '\0';
};

//------------------------------------------------------------------------
// ProducerThread::ProducerThread()
//      constructor for ProducerThread class
//------------------------------------------------------------------------

ConsumerThread::ConsumerThread(int No)
               : Number(No)
{
     ThreadName.seekp(0, ios::beg);
     ThreadName << "Consumer" << No << '\0';
}

//------------------------------------------------------------------------
// ProducerThread::ThreadFunc()
//      producer thread implementation
//------------------------------------------------------------------------

void ProducerThread::ThreadFunc()
{
     Thread::ThreadFunc();
     int data;
     strstream *Space;

     Space=Filler(4);
     for (int i = 1; i <= NumberOfData; i++) {
          Delay();
          NotFull.Wait();     // wait until the buffer has space
          BufferLock.Wait();       // lock the buffer
          data = rand() % 100 + 1000 * Number;  // generate data
          Buffer[In] = data;       // add data to the buffer
          cout << Space->str() << ThreadName.str() << " deposited "
               << data << " to the buffer" << endl;
          In = (In + 1) % BUFFER_SIZE;    // advance input pointer
          BufferLock.Signal();     // release the buffer
          NotEmpty.Signal();  // buffer is not full now
     }

     Delay();                      // about to add END
     NotFull.Wait();               // wait until the buffer has space
     BufferLock.Wait();            // lock the buffer
     Buffer[In] = END;             // put the END message in
     cout << Space->str() << ThreadName.str()
          << " deposited END and Exit" << endl;
     In = (In + 1) % BUFFER_SIZE;  // advance in pointer
     BufferLock.Signal();          // release the buffer
     NotEmpty.Signal();            // buffer is not full
     Exit();
}

//------------------------------------------------------------------------
// ConsumerThread::ThreadFunc()
//      consumer thread implementation
//------------------------------------------------------------------------

void ConsumerThread::ThreadFunc()
{
     Thread::ThreadFunc();
     int data = 0 ;
     strstream *Space;

     Space=Filler(2);
     while (true) {
          Delay();
          NotEmpty.Wait();              // wait until the buffer has data
          BufferLock.Wait();            // lock the buffer
          data = Buffer[Out];           // get a data item from the buffer
          if (data != END) {            // If it is not "END"
               cout << Space->str() << ThreadName.str()<< " received "
                    << data << " from the buffer" << endl;
               Out = (Out + 1) % BUFFER_SIZE;  // advance buffer pointer
               BufferLock.Signal();            // unlock the buffer
               NotFull.Signal();        // buffer is not full
          }
          else {
               cout << Space->str() << ThreadName.str()
                    << " received END and exits" << endl;
               Out = (Out + 1) % BUFFER_SIZE;
               BufferLock.Signal();
               NotFull.Signal();
               break;
        }
    }
    Exit();
}

// end of ProducerConsumer.cpp





