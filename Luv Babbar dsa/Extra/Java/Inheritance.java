// Inheritance
// increases reusability 
class Shape
{
    String color;
}

class Triangle extends Shape
{
    
}

public class OOPS
{
    public static void main(String args[])
    {
        Triangle t1=new Triangle();
        t1.color="red";
    }
}

// // Inheritable Types
// // single level inheritance 
class Shape
{
    public void area()
    {
        System.out.println("displays Area");
    }
}

class Triangle extends Shape
{
    public void area(int l,int h)
    {
        System.out.println(1/2*l*h);
    }
}

public class OOPS
{
    public static void main(String args[])
    {
        Triangle t1=new Triangle();
        t1.color="red";
    }
}


// #### Multilevel inheritance  #### 
class Shape
{
    public void area()
    {
        System.out.println("displays Area");
    }
}

class Triangle extends Shape
{
    public void area(int l,int h)
    {
        System.out.println(1/2*l*h);
    }
}

class EwuilateralTriangle extends Triangle
{
    public void area(int l,int h)
    {
        System.out.println(1/2*l*h);
    }
}

public class OOPS
{
    public static void main(String args[])
    {
        Triangle t1=new Triangle();
        t1.color="red";
    }
}

// // #### Hierarchiallevel inheritance  #### 
class Shape
{
    public void area()
    {
        System.out.println("displays Area");
    }
}

class Triangle extends Shape
{
    public void area(int l,int h)
    {
        System.out.println(1/2*l*h);
    }
}

class Circle extends Shape
{
    public void area(int r)
    {
        System.out.println(3.14*r*r);
    }
}

public class OOPS
{
    public static void main(String args[])
    {
        Triangle t1=new Triangle();
        t1.color="red";
    }
}

// #### Hybrid inheritance  #### 
