#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int trainee[3][3];
        int max=0;
        int avg[3]={0};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>trainee[i][j];
                if(trainee[i][j]<0 or trainee[i][j]>100)
                {
                    trainee[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                avg[i]=avg[i]+trainee[j][i];
            }
            avg[i]=avg[i]/3;
        }
        
        for(int i=0; i<3; i++) { 
            if(avg[i]>max)
    		{
        			max = avg[i];
    		}
	    }
        
        for(int i=0;i<3;i++)
        {
            if(avg[i]==max)
            {
                // max=avg[i];
                cout<<"trainer number : "<<i+1<<endl;
            }
            else if(avg[i]<70)
            {
                cout<<"Unfit!"<<endl;
            }
        }
        return 0;
    }
}
