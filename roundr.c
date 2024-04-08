#include<stdio.h>
void main(){
     int n,quantum,completed=0;
     printf("Enter the no. of processes\n");
     scanf("%d",&n);
     printf("Enter the time quantum :\n");
     scanf("%d",&quantum);
     int rm_time[n];
     int p[n],bt[n],wt[n],tat[n],tot_wt,tot_tat;
    int temp1,temp2,temp3;
int total=0;

for(int i=0;i<n;i++){
    printf("Enter the burst time of process %d:\n",i);
    scanf("%d",&bt[i]);

    p[i]=i;
    rm_time[i]=bt[i];
  }

  while (completed < n) {
    for(int i=0;i<n;i++){
      if(rm_time[i]>0){
        if(rm_time[i]>quantum){
            rm_time[i] -= quantum;
            total += quantum;

          }
        else{

            total += rm_time[i];
            wt[i] = total - bt[i];
            rm_time[i] = 0;
            completed++;
            tat[i] = total;
        }
      }
    }
  }

 

  printf("Process\tBurst time\tWT\tTAT\n");

  for(int i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\t\n",p[i],bt[i],wt[i],tat[i]);
    tot_wt += wt[i];
    tot_tat += tat[i];
  }
   float avg_wt=(float)tot_wt/n;
  float avg_tat=(float)tot_tat/n;

  printf("Total wt %d  Avg wt %f\n",tot_wt,avg_wt);
  printf("Total tat %d Avg tat %f\n",tot_tat,avg_tat);

}
 
              
             
                
          
     
