import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String str[]=sc.nextLine().split(",");
        for(String obj:str)
        {
            String ar[]=obj.split(":");
            String s =ar[0];
            int number =Integer.parseInt(ar[1]);
            int digitsum=0;
            while(number!=0)
            {
                int digit=number%10;
                digitsum+=(digit*digit);
                number=number/10;
            }
            int lengthofstring=s.length();
            if(digitsum%2==0)
            {
                System.out.println(s.charAt(lengthofstring-1)+s.substring(0,lengthofstring-1));
            }
            else{
                System.out.println(s.substring(2,lengthofstring)+s.substring(0,2));
            }
        }
    }
}
