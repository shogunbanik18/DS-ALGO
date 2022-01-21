/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.Arrays;
import java.util.Scanner;
public class Main
{
    public static void printJava()
    {
        System.out.println("Hello Peter!");
    }
    
    public static void printName(String name)
    {
        System.out.println(name);
    }
    
    public static void printsum(int a,int b)
    {
        int sum=a+b;
        System.out.println(sum);
    }
    
	public static void main(String[] args)
	{
	   // our first program 
// 		System.out.println("Hello Java");
// 	    System.out.println("Hello Peter!");
	    
	   // variable 
	   //String name="Aman";
	   //int age=30;
	   //String neighbour="Akku";
	   //String friend =neighbour;
	   //System.out.println(friend);
	   //System.out.println(age);
	   
	   //data types 
	   //primitive 
    	   //byte -1 [-128 to 127]
    	   //short 2 
    	   //int 4
    	   //long -8 
    	   //float 4 3.14 
    	   //double -8
    	   //char 2 a,b,c,d
    	   //boolean 1 (true/false)
	   //byte age=30;
	   //int phone =1234567890;
	   //long phone2=1234567890L;
	   //float pi =3.14F;
	   //char letter ='a';
	   //boolean isadult =true;
	   
	   //non -primitive or reference type variable
	   //they reference a memory location where data is stored
	   //length is fixed 
	   //String name="Shogun";
	   //String name =new String("Apu");
	   //String friend=new String("Akku");
	   //System.out.println(name.length());
	   //new keyword 
	   
	   //String are Immutable in Java 
	   
	   //operations on strings
	   //Concatenation on Strings
	   //String name1="Aman";
	   //String name2="Akku";
	   //String name3=name1+" and "+name2;
	   //System.out.println(name3);
	   
	   //charAt function 
	   //String name1="Aman";
	   //System.out.println(name1.charAt(3));
	   
	   //Replace function
	   //in java strings are immutable 
	   //String name1="Aman";
	   //String name2 =name1.replace('a','b');
	   //System.out.println(name2);
	   //System.out.println(name1);
	   
	   //Substring Function 
	   //String name="Aman and Akku";
	   ////0 included and 3 excluded 
	   //System.out.println(name.substring(5,9));
	   
	   //Arrays in Java 
	   //int[]arr=new int[3];
	   //arr[0]=97;
	   //arr[1]=98;
	   //arr[2]=95;
	   
	   ////length 
	   //System.out.println(arr.length);
	   
	   ////sorting function 
	   //System.out.println(arr[0]);
	   //Arrays.sort(arr);
	   //System.out.println(arr[0]);
	   
	   //int[]marks={97,98,95};
	   
	   ////2d Arrays
	   //int[][] finalmarks={{97,98,95},{89,91,90}};
	   //for(int i=0;i<finalmarks.length;i++)
	   //{
	   //    for(int j=0;j<finalmarks[0].length;j++)
	   //    {
	   //         System.out.print(finalmarks[i][j]);
	   //         System.out.print(" ");
	   //    }
	   //    System.out.println("");
	   //}
	   
	   //Casting 
	   //implicit casting 
	   //double price=100.00;
	   //double finalprice =price+18;
	   //System.out.println(finalprice);
	   
	   ////error due to casting
	   ////int 4 bytes and double has 8 bytes memory
	   ////use of explicit casting 
	   //int p=100;
	   //int fp=p+(int)18.18;
	   //System.out.println(fp);
	   
	   //int age=30;
	   //age=31;
	   //age=32;
	   
	   //final float PI =3.14F;
	   ////PI=1.4F;
	   //System.out.println(PI);
	   
	   
	   //operators
	   //int a=1;
	   //int b=2; 
	   //int sum=a+b;
	   //int diff=a-b;
	   //float mul=a*b;
	   //float div=a/b;
	   ////modulo 
	   //double mod=a%b;
	   //System.out.println(sum);
	   //System.out.println(diff);
	   //System.out.println(mul);
	   //System.out.println(mod);
	   //System.out.println(div);
	   
	   //a,b
	   //unary operator 
	   //int numb=1;
	   ////numb++;
	   //System.out.println(numb++);
	   //System.out.println(++numb);
	   
	   //Math function 
	   //System.out.println(Math.max(5,6));
	   //System.out.println(Math.min(5,6));
	   
	   ////random function
	   //System.out.println((int)Math.random()*100);
	   
	   
	   //Important
	   //input and output 
	   //Scanner sc =new Scanner(System.in);
	   //System.out.println("Input Your Name");
	   //int age=sc.nextInt();
	   //float age=sc.nextFloat();
	   
	   ////single wordinput 
	   ////String name=sc.next();
	   
	   //single line input 
	   //String name1=sc.nextLine();
	   //System.out.println(name1);
	   
	   //Comparision operators 
	   //a==b
	   //a!=b
	   //a=>b a<=b 
	   
	   //boolean isup=true;
	   //if(isup==true)
	   //{
	   //    System.out.println("Day");
	   //}
	   //else
	   //{
	   //    System.out.println("Night");
	   //}
	   
	   //logical operators 
	   //int a=60;
	   //int b=40;
	   
	   //if(a<50 && b<50)
	   //if(a<50 || b<50)
	   //{
	   //    System.out.println("Both Less Than 50");
	   //}
	   //else
	   //{
	   //    System.out.println("Not");
	   //}
	   
	   //Negation operator 
	   //boolean isadult=false;
	   //if(!isadult)
	   //{
	   //    System.out.println("Not ADULT");
	   //}
	   //else
	   //{
	   //    System.out.println("Is Adult");
	   //}
	   
	   //Scanner sc=new Scanner(System.in);
	   ////pen=10 notebook=40
	   //int cash=sc.nextInt();
	   //if(cash<10)
	   //{
	   //    System.out.println("Cannot Buy Anything");
	   //    System.out.println("Get More cash");
	   //}
	   //else if(cash>10 && cash<50)
	   //{
	   //    System.out.println("Can get one thing");
	   //}
	   //else
	   //{
	   //    System.out.println("Can get both ");
	   //}
	   
	   //Switch case 
	   //int day;
	   //Scanner sc=new Scanner(System.in);
	   //day=sc.nextInt();
	   //switch(day)
	   //{
	   //    case 1 : 
	   //         System.out.println("Monday");
	   //         break;
	   //    case 2 : 
	   //         System.out.println("Tuesday");
	   //         break;
	   //    case 3 : 
	   //         System.out.println("Wednesday");
	   //         break;
	   //    case 4 : 
	   //         System.out.println("Thursday");
	   //         break;
	   //    case 5 : 
	   //         System.out.println("Friday");
	   //         break;
	   //    case 6 : 
	   //         System.out.println("Saturday");
	   //         break;
	   //    case 7 : 
	   //         System.out.println("Sunday");
	   //         break;
	   //    default:
	   //         System.out.println("Wed-sun");
	   //}
	   
	   //Loops 
	   //for loops 
	   //for(int i=10;i>=1;i--)
	   //{
	   //    System.out.println(i);
	   //}
	   
	   //while loops 
	   //int i=10;
	   //while(i>=1)
	   //{
	   //    System.out.println(i);
	   //    i--;
	   //}
	   
	   //do while loops 
	   //int k=10;
	   //do{
	   //    System.out.println(k);
	   //    k--;
	   //}while(k>=1);
	   
	   //Scanner sc=new Scanner(System.in);
	   //int number=0;
	   //do{
	   //   System.out.println("Input a number");
	   //   number=sc.nextInt();
	   //   System.out.print("Here is Your No.");
	   //   System.out.println(number);
	   //}while(number>=0);
	   
	   //System.out.println("The End");
	   
	   //using break and continue 
	   //int i=0;
	   //while(true)
	   //{
	   //    if(i==3)
	   //    {
	   //        i+=1;
	   //        continue;
	   //    }
	   //    System.out.println(i);
	   //    i+=1;
	   //    if(i>5)
	   //    {
	   //        break;
	   //    }
	   //    //break
	   //}
	   
	   //Exception Handling
	   //try and catch 
	   //int[]marks ={97,98,95};
	   //try{
	   //     System.out.println(marks[5]);
	   //}
	   //catch(Exception exception)
	   //{
	   //    //do something
	       
	   //}
	   //System.out.println("The Name is Yash");
	   
	   //Methods/Functions 
	   //System.out.println("Hello Peter!");
	   //System.out.println("Hello Peter!");
	   //System.out.println("Hello Peter!");
	   //printJava();
	   //printJava();
	   //printJava();
	   //printName("Shogun");
	   //printName("Yash");
	   //printsum(1,6);
	   
	   //MINI Project 
	   int myNum=(int)(Math.random()*100);
	   Scanner sc=new Scanner(System.in);
	   int usernumber=0;
	   do{
	       System.out.println("Guess My Number: ");
	       usernumber=sc.nextInt();
	       if(usernumber==myNum)
	       {
	           System.out.println("WOOHOO...Correct Number ");
	           break;
	       }
	       else if(usernumber>myNum)
	       {
	             System.out.println("Your Number is too large");  
	       }
	       else
	       {
	            System.out.println("Your Number is too Small");  
	       }
	   }while(usernumber>=0);
	}
}
