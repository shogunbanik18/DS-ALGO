// tc:O(n)
// sc:o(1)
import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner sc =new Scanner(System.in);
        int n=sc.nextInt();
        
        int[] earn=new int[n];
        for(int i=0;i<n;i++)
        {
            earn[i]=sc.nextInt();
        }
        
        int[] cost=new int[n];
        for(int i=0;i<n;i++)
        {
            cost[i]=sc.nextInt();
        }
        
        int mini=0;
        for(int i=0;i<n;i++)
        {
            mini+=cost[i]-earn[i];
        }
        if(mini<0)
        {
            mini=0;
        }
        System.out.println(mini);
    }
}
