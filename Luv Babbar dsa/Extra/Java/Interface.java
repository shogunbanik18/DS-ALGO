interface Animal
{
    int eyes=2;
    void walk();
}

interface Herbivore
{
   
}

class Horse implements Animal
{
    public void walk()
    {
        System.out.println("walk on 4 legs");
    }
}

public class Main
{
    public static void main(String args[])
    {
        Horse horse=new Horse();
        horse.walk();
    }
}

// static accesssible to all 

class Student
{
    String name;
    static String school;
    public static void changeSchool()
    {
        school ="newschool";
    }
}

public class Main
{
    public static void main(String args[])
    {
        Student.school="ABC";
        Student Student1=new Student();
        Student1.name="Tony";
        System.out.println(Student1.school);
    }
}
