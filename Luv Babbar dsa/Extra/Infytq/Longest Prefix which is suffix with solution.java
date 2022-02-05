import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        int n=str.length();
        int i=0;
        int j=n-1;
        int count=0;
        while(i<j)
        {
            if(str.charAt(i)!=str.charAt(j))
            {
                j--;
            }
            else
            {
                count++;
                i++;
                j++;
                if(j>n-1)
                {
                    break;
                }
            }
        }
        System.out.println(count);
    }
}
