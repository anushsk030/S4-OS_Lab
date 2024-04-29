#include<stdio.h>
void main()
   {
    int Processes[5];
    
    struct memory{    
       int size;
       int flag;
     }m[5];
     int j;
    printf("Enter the memory used by  processes\n");
    for (int i=0;i<5;i++)
        scanf("%d",&Processes[i]);
        
    printf("Enter the sizes of memory blocks :\n");
    for (int i=0;i<5;i++)
       {
        scanf("%d",&m[i].size);
        m[i].flag=0;
       }
    for (int i=0;i<5;i++)
       {
       
        for (j=0;j<5;j++)
           {
            if(Processes[i]<=m[j].size)
               {
                
                if (m[j].flag==1)
                   continue;
                else
                   {
                    printf("Process %d is allocated to %d Memory\n",i+1,m[j].size);
                    m[j].flag=1;
                    break;
                   }
               }
          
           }
           if (j==5)
               printf("Process %d cannot be allocated\n",i+1);
       }   
   }
 
 
 
 
 
 
 
 
