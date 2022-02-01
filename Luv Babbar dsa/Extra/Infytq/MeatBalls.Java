import java.util.*;
class Main
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        int d=sc.nextInt();
        int []arr =new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        // for(int i=0;i<n;i++)
        // {
        //     arr[i]=(arr[i]-1)/d;
            
        // }
        int maxi=0,maxpos=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>maxi)
            {
                maxi=arr[i];
                maxpos=i;
            }
        }
        System.out.println(maxpos+1);
    }
}
