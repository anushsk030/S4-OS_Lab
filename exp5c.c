#include<stdio.h>
void main(){
     int n;
     printf("Enter the no. of processes\n");
     scanf("%d",&n);
     int p[n],bt[n],wt[n],tat[n],tot_wt,tot_tat,pri[n];
    int temp1,temp2,temp3;
     for(int i=0;i<n;i++){
      printf("Enter the burst time of process %d:\n",i);
       scanf("%d",&bt[i]);
       printf("Enter the priority of process %d:\n",i);
       scanf("%d",&pri[i]);
       p[i]=i;
       }
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        
           if(pri[i]>pri[j]){
               temp3=pri[i];
               pri[i]=pri[j];
               pri[j]=temp3;
               
               
               temp1=bt[i];
               bt[i]=bt[j];
               bt[j]=temp1;
               
               temp2=p[i];
               p[i]=p[j];
               p[j]=temp2;
               }
              }
            }
             wt[0]=0;
     tat[0]=bt[0];
     for(int i=1;i<n;i++){
             wt[i]=wt[i-1]+bt[i-1];
             tot_wt=tot_wt+wt[i];
             tat[i]=tat[i-1]+bt[i];
             tot_tat=tot_tat+tat[i];
             }
              tot_tat=tot_tat+tat[0];
             float avg_wt=(float)tot_wt/n;
             float avg_tat=(float)tot_tat/n;
       for(int i=0;i<n;i++){
         printf("Process=%d\tBurst time=%d\tWT=%d\tTAT=%d\t",p[i],bt[i],wt[i],tat[i]);
         printf("\n");
         }
         printf("Total wt %d  Avg wt %f\n",tot_wt,avg_wt);
         printf("Total tat %d Avg tat %f\n",tot_tat,avg_tat);
}
       