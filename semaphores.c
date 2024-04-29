

#include<stdio.h>
int mutex=1, empty=3, full=0;
void consumer();
void producer();
 void main()
 {
  int ch;
  while(ch<3)
  {
   printf("Enter the choice:\t1.Produce\t2.Consume\t3.Exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
    {
     if(mutex==1&&empty!=0)
     {
      producer();
      printf("Data is produced\n");
     }
     else
     {
      printf("Buffer is Full\n");
     }
     break;
    }  
    case 2:
    {
     if(mutex==1&&full!=0)
       {
         consumer();
          printf("Data is consumed\n");
       }
     else
     {
      printf("Buffer is empty\n");
     }
     break;
    }
    case 3:
    {
    printf("EXIT\n");
    break;
    }
   }
  }  
  }
    int wait(int s)
    {
     return --s;
    }
    int signal(int s)
    {
     return ++s;
    }
    void producer()
    {
     mutex=wait(mutex);
     full=signal(full);
     empty=wait(empty);
     mutex=signal(mutex);
    }
    void consumer()
    {
     mutex=wait(mutex);
     full=wait(full);
     empty=signal(empty);
     mutex=signal(mutex);
    }

     
     
     
     
     
     
     
     
     
     
     
     
     
     
    
	

