#include<stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

int main(){
cout<<"\n/////////////////////////////////";
cout<<"\n/    First Come First Serve     /";
cout<<"\n/////////////////////////////////";
float t_totalTAT=0,t_totalWT=0;
int t; // number of rounds

for(t=0;t<3;t++){
int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
int n,sum=0;
float totalTAT=0,totalWT=0;
n=7; // number of processes
cout<<"\n For Turn "<<t+1;

at[0]=0;
for(int i=0;i<n;i++)
{
at[i+1]=rand()%5 + 1;
bt[i]=rand()%5 + 1;
}

/*
calculate completion time of processes.
will be used to calculate TAT.
*/
for(int j=0;j<n;j++)
{
sum+=bt[j];
ct[j]+=sum;
}

//calculate TAT
for(int k=0;k<n;k++)
{
tat[k]=ct[k]-at[k];
totalTAT+=tat[k];
}
//calculate WT
for(int k=0;k<n;k++)
{
wt[k]=abs(tat[k]-bt[k]);
totalWT+=wt[k];
}

printf(":\n\n");
printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");

for(int i=0;i<n;i++)
{
printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}

cout<<"\n Average TAT ="<<totalTAT/5;
cout<<"\n Average WT = "<<totalWT/5;
t_totalTAT=t_totalTAT+(totalTAT/5);
t_totalWT=t_totalWT+(totalWT/5);
cout<<"\n-------------------------";
}
cout<<"\n Average TAT for all 3 turns ="<<t_totalTAT/3;
cout<<"\n Average WT for all 3 turns = "<<t_totalWT/3;
printf("\n\n");
return 0;
}
