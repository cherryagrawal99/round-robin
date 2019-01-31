#include<iostream>
using namespace std;
int function(int ,int[],int);
main()
{
	int n,quantum;
	cout<<"Enter the no of processes\n";
	cin>>n;
	int bt[n];
	cout<<"Enter burst time of all process\n";
	for(int i=0;i<n;i++)
	cin>>bt[i];
	cout<<"Enter quantum time\n";
	cin>>quantum;
	function(n,bt,quantum);
	
}
int function (int n,int bt[],int quantum)
{
	int wt[n],rem_bt[n];
    for(int i=0;i<n;i++)
    rem_bt[i]=bt[i];
    int t=0;
    while(true)
    {
      bool done=true;
      for(int i=0;i<n;i++)
      {
       if(rem_bt[i]>0)
       {
        done=false;
        {
		if(rem_bt[i]>quantum)
			{
			t=t+quantum;
			rem_bt[i]=rem_bt[i]-quantum;
			}
		else
			{
			t=t+rem_bt[i];
			rem_bt[i]=0;
			wt[i]=t-bt[i];
			}
		}
       }
      }
      if(done==true)
      break;
    }
    int tat[n];
    for(int i=0;i<n;i++)
    tat[i]=wt[i]+bt[i];
    for(int j=0;j<n;j++)
    cout<<wt[j]<<" "<<endl;
    for(int k=0;k<n;k++)
    cout<<tat[k]<<" "<<endl;
}

