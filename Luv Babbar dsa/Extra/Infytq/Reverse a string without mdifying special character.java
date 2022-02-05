import java.util.*;
public class Main
{
    public static void reverse(char[] str)
    {
        int i=0;
        int j=str.length-1;
        while(i<=j)
        {
            if(!Character.isAlphabetic(str[i]))
            {
                i++;
            }
            
            else if(!Character.isAlphabetic(str[j]))
            {
                j--;
            }   
            
            else 
            {
                char temp=str[i];
                str[i]=str[j];
                str[j]=temp;
                i++;
                j--;
            }
        }
    }
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        String str= sc.nextLine();
        char[] charArray =str.toCharArray();
        System.out.println("Input String : " +str);
        reverse(charArray);
        String rev =new String(charArray);
        System.out.println(rev);
    }
}
