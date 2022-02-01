/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
abstract class Animal
{
    abstract void walk();
    public void eat()
    {
        System.out.println("Animal Eats");
    }
    
    // constructor 
    Animal()
    {
        System.out.println("You are Creating a New Animal");
    }
} 

class Horse extends Animal
{
    Horse()
    {
        System.out.println("Created a horse");
    }
    public void walk()
    {
        System.out.println("Walks on 4 legs");
    }
}

class Chicken extends Animal
{
    public void walk()
    {
        System.out.println("Walks on 2 legs");
    }
}

public class Main
{
	public static void main(String[] args) 
	{
	   // constructor chaining 
	    Horse horse=new Horse();
	   // horse.walk();
	   // horse.eat();
	    
	    
	   // ## runtime error ##
	   // Animal animal=new Animal();
	   // animal.walk();
	}
}
