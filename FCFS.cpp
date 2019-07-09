#include<stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

int main(){
cout<<"\n FCFS \n\n";
float t_totalTAT=0,t_totalWT=0;
int t;
for(t=0;t<3;t++){
int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
int n,sum=0;
float totalTAT=0,totalWT=0;
n=5;
cout<<"\n For Turn "<<t+1;


for(int i=0;i<n;i++)
{

at[i]=rand()%10;
bt[i]=rand()%10;

}

//calculate completion time of processes

for(int j=0;j<n;j++)
{
sum+=bt[j];
ct[j]+=sum;
}

//calculate turnaround time and waiting times

for(int k=0;k<n;k++)
{
tat[k]=ct[k]-at[k];
totalTAT+=tat[k];
}


for(int k=0;k<n;k++)
{
wt[k]=tat[k]-bt[k];
totalWT+=wt[k];
}

 printf("Solution: \n\n");
printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");

for(int i=0;i<n;i++)
{
printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}

cout<<"\n Average Turnaround Time ="<<totalTAT/5;
cout<<"\n Average WT = "<<totalWT/5;
t_totalTAT=t_totalTAT+(totalTAT/5);
t_totalWT=t_totalWT+(totalWT/5);
cout<<"\n-------------------------";
}
cout<<"\n Average Turnaround Time for all 3 turn ="<<t_totalTAT/3;
cout<<"\n Average WT for all 3 turn = "<<t_totalWT/3;
return 0;
}

/*

output

FCFS


For Turn 1
Average Turnaround Time =8.6
Average WT = 4
-------------------------
For Turn 2
Average Turnaround Time =9.4
Average WT = 5.2
-------------------------
For Turn 3
Average Turnaround Time =8.2
Average WT = 4.2
-------------------------
Average Turnaround Time for all 3 turn =8.73333
Average WT for all 3 turn = 4.46667

*/
