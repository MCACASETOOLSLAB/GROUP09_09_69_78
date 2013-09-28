#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 8
#define NUM_THREADS 4

struct cBuf{
    char    *buf; 
    int     size;   
    int     start;
    int     end;   
    pthread_mutex_t mutex;
    pthread_cond_t  buffer_full;
    pthread_cond_t  buffer_empty;
};

struct cBuf cb;


void buf_Init(struct cBuf *cb, int size) {
    int i;
    cb->size  = size + 1; 
    cb->start = 0;
    cb->end   = 0; 
    cb->buf = (char *)calloc(cb->size, sizeof(char)); 
    for (i=0;i<size;i++) cb->buf[i]='_';

}

void buf_Free(struct cBuf *cb) {
    free(cb->buf);
}

int buf_IsFull(struct cBuf *cb) {
    return (cb->end + 1) % cb->size == cb->start; 
}

int buf_IsEmpty(struct cBuf *cb) {
    return cb->end == cb->start; 
}

int buf_Insert(struct cBuf *cb, char *elem) {

    int i,j;

    pthread_mutex_lock(&(cb->mutex));
    for (i=0; i < strlen(elem); ++ i){
        if (buf_IsFull(cb)==1) printf("\nProducer (buf_Insert) is waiting because of full buffer");
        while(buf_IsFull(cb)){  
            pthread_cond_signal(&(cb->buffer_full));            
            pthread_cond_wait(&(cb->buffer_empty),&(cb->mutex));
        } 
        cb->buf[cb->end] = elem[i]; 
        cb->end = (cb->end + 1) % cb->size;     
        printf("%c [INPUT]",elem[i]);
    }

    pthread_cond_signal(&(cb->buffer_full));
    pthread_mutex_unlock(&(cb->mutex));     
    return 0;       
}

int buf_Read(struct cBuf *cb, char *out) {
    int i,j;

    pthread_mutex_lock(&(cb->mutex));
    if (buf_IsEmpty(cb))printf("\nConsumer (buf_Read) is waiting because of empty buffer\n");
    while(buf_IsEmpty(cb)){
        pthread_cond_wait(&(cb->buffer_full),&(cb->mutex));
    }
    for (i=0;i<BUFFER_SIZE-1;i++){
    printf("\n");
        if (cb->start == cb->end) break;        
        out[i] = cb->buf[cb->start];
        cb->buf[cb->start] = '_';
        cb->start = (cb->start + 1) % cb->size; 
        printf("%c [OUTPUT]",out[i]);
    }
    pthread_cond_signal(&(cb->buffer_empty));
    pthread_mutex_unlock(&(cb->mutex)); 
    return 0;
}

void * client(void *cb){

    pthread_detach(pthread_self());

    struct cBuf *myData;
    myData = (struct cBuf*) cb;
    char input[]="Hello World!";
    if (buf_Insert(myData, input)){
        //succes on return 0
        printf("\n");
    } 

    return 0;
}

int main(void) {
    char out[60];
    pthread_t thread;
    int i;
    /* Initialise conditioners*/
    pthread_cond_init(&(cb.buffer_full),NULL);
    pthread_cond_init(&(cb.buffer_empty),NULL);

    buf_Init(&cb, BUFFER_SIZE);

    for (i = 0; i<NUM_THREADS; i++){
            if(pthread_create (&thread,NULL, client, (void *) &cb) !=0){
        } else {

        }
    }

    while (1){
        if (buf_Read(&cb,out)){
        } 
    }

    //empty the buffer; free the allocated memory
    buf_Free(&cb);
    return 0;
}

c mutex race