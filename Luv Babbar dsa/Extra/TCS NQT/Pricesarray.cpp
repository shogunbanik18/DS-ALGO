#include<bits/stdc++.h>
using namespace std;

int main()
{
    int item_Number[]={101,102,103,104};
    string item_Name[]={"Milk","Cheese","Ghee","Bread"};
    int price[]={42,50,500,40};
    int stock[]={10,20,15,16};
    
    int item_num,quantity;
    cin>>item_num>>quantity;
    
    float ans;
    int temp=0,flag=0;
    for(int i=0;i<4;i++)
    {
        if(item_num==item_Number[i])
        {
            temp=i;
            flag=1;
        }
    
        if(flag==0)
        {
            cout<<"INVALID INPUT"<<endl;
        }
        
        if(quantity>stock[temp])
        {
            cout<<"NO STOCK"<<endl;
            cout<<stock[temp]<<" "<<"LEFT"<<endl;
            break;
        }
        
        else if(quantity<=stock[temp])
        {
            float ans= (price[temp]*quantity);
            cout<<ans<<" "<<"INR"<<endl;
            cout<<stock[temp]-quantity<<" "<<"LEFT"<<endl;
            break;
        }
    }
    return 0;
}
