/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;
public class Main
{
	public static void main(String[] args) 
	{
	    Scanner sc=new Scanner(System.in);
	    int n=sc.nextInt();
	    int earn[]=new int[n];
	    int cost[]=new int[n];
	    for(int i=0;i<n;i++)
	    {
	        earn[i]=sc.nextInt();
	    }
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
		    System.out.println(0);
		}
		else{
		    System.out.println(mini);
		}
	}
}
