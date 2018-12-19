#include <stdio.h>
int a[10],b[10],x[10],i,smallest,count=0,time,n,wait,turn,end,w[10],t[10],c=0;
double avg=0,tt=0;
void srtf(int a[],int b[],int x[],int n);
int main() 
{
	printf("Enter the number of Processes:\n");
	scanf("%d",&n); 
    /*Storing arrival time of process*/
	printf("Enter arrival time\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    /*Storing burst time of process*/
	printf("Enter burst time\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]); 
	printf("\n");
    /*Copying burst time into another array*/
	for(i=0;i<n;i++)
		x[i]=b[i];
	srtf(a,b,x,n);
	return 0;
}
void srtf(int a[],int b[],int x[],int n)
{
	b[9]=1000;
	printf("\n Gantt chart\n");
	for(time=0;count!=n;time++)
	{
		smallest=9;
        /*To check whether arrived process has smallest burst time then executing process*/ 
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && b[i]<=b[smallest] && b[i]>0 )
            {
                 smallest=i;
            }
        }
        b[smallest]--;
        c++;
        printf("p%d=(%d-%d)\n",smallest,time,c);
        /*Calculating waiting and Turnaround time*/
        if(b[smallest]==0)
        {
             count++;
             end=time+1;
             wait=end-a[smallest]-x[smallest];
             w[smallest]=wait;
             avg=(double)avg+wait;
             turn=end-a[smallest];
             t[smallest]=turn;
             tt=(double)tt+turn;
         }
	}
    /*processes waiting and turnaround time*/
    printf("\nProcesses\tWaiting time\tTurnaround time");
    for(i=0;i<n;i++)
    {
         printf("\np%d\t\t%d\t\t%d",i,w[i],t[i]);
    }
    printf("\n\nAverage waiting time = %0.2lf\n",avg/n);
    printf("Average Turnaround time = %0.2lf",tt/n);
}

/*Output
tejal@ubuntu:~/Desktop/os$ gcc os2.c
tejal@ubuntu:~/Desktop/os$ ./a.out
Enter the number of Processes:
3
Enter arrival time
0
1
2
Enter burst time
9
4
9


Gantt chart
p0=(0-1)
p1=(1-2)
p1=(2-3)
p1=(3-4)
p1=(4-5)
p0=(5-6)
p0=(6-7)
p0=(7-8)
p0=(8-9)
p0=(9-10)
p0=(10-11)
p0=(11-12)
p0=(12-13)
p2=(13-14)
p2=(14-15)
p2=(15-16)
p2=(16-17)
p2=(17-18)
p2=(18-19)
p2=(19-20)
p2=(20-21)
p2=(21-22)

Processes	Waiting time	Turnaround time
p0		     4		              13
p1		     0		               4
p2		    11		              20

Average waiting time = 5.00
Average Turnaround time = 12.33
*/

