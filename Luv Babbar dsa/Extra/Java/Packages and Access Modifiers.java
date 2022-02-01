// package Bank;
// Packages and Access Modifiers

// Encapslation(dhak dena) making objects 
// data hiding
// abstraction 
class Account
{
    public String name;
    protected String email;
    private String password;
    // getters and setters for accessing private 
    public String getPassword()
    {
        return this.password;
    }
    
    public void setPassword(String pass)
    {
        this.password=pass; 
    }
}

public class Main
{
    public static void main(String args[])
    {
        Account account1=new Account();
        account1.name="Apna College";
        account1.email="apnacollege@gmail.com";
        account1.setPassword("abcd");
        System.out.println(account1.getPassword());
    }
}

//#### public ,private ,protected and default ####
