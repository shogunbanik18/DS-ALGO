/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// public class Main
// {
// 	public static void main(String[] args) {
// 		System.out.println("Hello World");
// 	}
// }

class Pen
{
    String color;
    String type; //ballpint;gel
    
    public void write()
    {
        System.out.println("Writing Something!");
    }
    
    public void printColor()
    {
        System.out.println(this.color);
    }
}

// capital letters 
class Student
{
    String name;
    int age;
    
    public void printInfo()
    {
        System.out.println(this.name);
        System.out.println(this.age);
    }
    
    // Parameterized constructor 
    // Student(String name,int age)
    // {
    //     this.name=name;
    //     this.age=age;
    //     System.out.println("Parameterized constructors called!");
    // }
    
    Student()
    {
        
    }
    
    // copy constructors
    Student(Student s2)
    {
        this.name=s2.name;
        this.age=s2.age;
        System.out.println("Copy constructors called!");
    }
}

public class Main
{
    public static void main(String args[])
    {
        // Pen pen1=new Pen();
        // pen1.color="Blue";
        // pen1.type="Gel";
        // pen1.write();
        
        // Pen pen2=new Pen();
        // pen2.color="Green";
        // pen2.type="Ballpoint";
        // pen2.write();
        
        // pen1.printColor();
        // pen2.printColor();
        
        // constructors
        // Student s1=new Student("Shogun",21);
        Student s1=new Student();
        s1.name="Shogun";
        s1.age=21;
        
        Student s2=new Student(s1);
        s1.printInfo();
    }
}
