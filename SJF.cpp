#include<stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
int main()
{
cout<<"\n/////////////////////////////////";
cout<<"\n/    Shortest Job First         /";
cout<<"\n/////////////////////////////////";
float t_totalTAT=0,t_totalWT=0;
int n=7; // number of processes
int t=0; // number of rounds

for(t=0;t<3;t++){
int i,j,min,line[10],line1[10],p[10]={1,2,3,4,5,6,7,8,9,10};
int B_T[1000],A_V_T[1000],W_T[1000],temp,T_A_T[10];
int bt=0,ta=0,sum=0,k=1;
float AVR_W_T=0,AVR_T_A_T=0,T_A_T_SUM=0,W_T_SUM=0;

cout<<"\n Turn Number "<<t+1;
for(i=0;i<n;i++)
{
A_V_T[i]=rand()%10;
B_T[i]=rand()%10;
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(A_V_T[i]<A_V_T[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=A_V_T[j];
A_V_T[j]=A_V_T[i];
A_V_T[i]=temp;
temp=B_T[j];
B_T[j]=B_T[i];
B_T[i]=temp;
}
}
}

for(j=0;j<n;j++)
{
bt=bt+B_T[j];
min=B_T[k];
for(i=k;i<n;i++)
{
if (bt>=A_V_T[i] && B_T[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=A_V_T[k];
A_V_T[k]=A_V_T[i];
A_V_T[i]=temp;
temp=B_T[k];
B_T[k]=B_T[i];
B_T[i]=temp;
}
}
k++;
}
W_T[0]=0;
for(i=1;i<n;i++)
{
sum=sum+B_T[i-1];
W_T[i]=sum-A_V_T[i];
line[i]=W_T[i];
W_T_SUM=W_T_SUM+W_T[i];
}

AVR_W_T=(W_T_SUM/n);
for(i=0;i<n;i++)
{
ta=ta+B_T[i];
T_A_T[i]=ta-A_V_T[i];
line1[i]=T_A_T[i];
T_A_T_SUM=T_A_T_SUM+T_A_T[i];
}

AVR_T_A_T=(T_A_T_SUM/n);

printf(":\n\n");
printf("P#\t AT\t BT\t TAT\t WT\t\n\n");

for(int i=0;i<n;i++)
{
printf("P%d\t %d\t %d\t %d\t %d\n",i+1,A_V_T[i],B_T[i],T_A_T[i],W_T[i]);
}

cout<<"\nAVERAGE W TIME :"<<AVR_W_T;
cout<<"\nAVERAGE TA TIME :"<<AVR_T_A_T;
t_totalTAT=t_totalTAT+AVR_T_A_T;
t_totalWT=t_totalWT+AVR_W_T;
cout<<"\n--------------------";
}
cout<<"\n Average TA Time for all turns ="<<t_totalTAT/3;
cout<<"\n Average WT for all turns = "<<t_totalWT/3;
printf("\n\n");
return 0;
}
