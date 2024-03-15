#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

void main(){
    int shmid;
    key_t key;
    key=ftok(".",'S');
    char *shm;
    char data[100];
    if(key==-1){
        perror("ftok");
        exit(1);
        }
    shmid=shmget(key,4096,IPC_CREAT|0666);
    if(shmid==-1){
        perror("shmget");
        exit(1);
        }
    else{
        printf("shmid=%d\n",shmid);
        shm=shmat(shmid,NULL,0);
        printf("The data is attached:  \n");
        printf("enter a data;\n");
        gets(data);
        strcpy(shm,data);
        printf("The Data is : %s \n",shm);
        shmdt(shm);
        printf("The data is dittached\n");
        shmctl(shmid,IPC_RMID,NULL);
        printf("Data Removed\n");
       }
  }
        
        
