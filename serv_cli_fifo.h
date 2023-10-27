#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include<signal.h>

#define NMAX 10
#define fifo1 "./fifo/fifo1"
#define fifo2 "./fifo/fifo2"

typedef struct question question;
struct question
{
    int n;
    int pid;
};


typedef struct reponse reponse;
struct reponse
{
     int arr[NMAX];
    int pid;
};
