import java.util.*; 
public class Main
{
    public static int reverse(int x)
    {
        StringBuilder string =new StringBuilder(Integer.toString(x));
        string.reverse();
        return Integer.parseInt(string.toString());
    }
    
    public static boolean ispalindrome(int x)
    {
        return x==reverse(x);
    }
    
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt();
        while(true)
        {
            int y=reverse(x);
            int z=x+y;
            if(ispalindrome(z))
            {
                System.out.println(z);
                break;
            }
            else{
                x=y;
            }
        }
    }
}
