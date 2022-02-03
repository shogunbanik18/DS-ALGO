import java.util.*;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] wt=new int[n];
        for(int i=0;i<n;i++)
        {
            wt[i]=sc.nextInt();
        }
        int threshold=sc.nextInt();
        
        int total=0;
        for(int i=0;i<n;i++)
        {
            if(wt[i]<=threshold)
            {
                total+=1;
            }
            else 
            {
                total+=2;
            }
        }
        System.out.println(total);
    }
}
