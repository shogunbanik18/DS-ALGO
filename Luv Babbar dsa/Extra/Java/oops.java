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

Polymorphism 
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
    
    // public void printInfo()
    // {
    //     System.out.println(this.name);
    //     System.out.println(this.age);
    // }
    
    // // Parameterized constructor 
    // // Student(String name,int age)
    // // {
    // //     this.name=name;
    // //     this.age=age;
    // //     System.out.println("Parameterized constructors called!");
    // // }
    
    // Student()
    // {
        
    // }
    
    // // copy constructors
    // Student(Student s2)
    // {
    //     this.name=s2.name;
    //     this.age=s2.age;
    //     System.out.println("Copy constructors called!");
    // }
    
    
    // polymorphism example
    // compile time polymorphism 
    // function overloading examples
    public void printinfo(String name)
    {
        System.out.println(name);
    }
    
     public void printinfo(int age)
    {
        System.out.println(age);
    }
    
     public void printinfo(String name,int age)
    {
        System.out.println(name+" "+age);
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
        s1.printinfo(s1.name,s1.age);
        
        // Student s2=new Student(s1);
        // s1.printInfo();
        
        // polymorphism 
        // compile time and run time polymorphism
        // function overloading 
        
    }
}

