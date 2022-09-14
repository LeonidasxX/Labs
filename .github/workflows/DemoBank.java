import java.util.*;

class BankAccount
{
    String name;
    long accno;
    String typeofacc;
    double bal;
    static double rate = 10;
    public BankAccount()
    {
        name = null;
        accno = 0;
        typeofacc = null;
        bal = 0.0;
        rate = 10;
    }
    public BankAccount(String n , long an , String toa , double b)
    {
        name = n;
        accno = an;
        typeofacc = toa;
        bal = b;
    }
    public void depo(double amount)
    {
        bal+=amount;
        System.out.println("Adding Amount..........");
        display();
    }
    public void withdraw(double amm)
    {
        if((bal-amm)<1000)
        {
            System.out.println("Minimum Balance Cant Withdraw!");
            System.exit(0);
        }
        else
        {
            bal-=amm;
            System.out.println("Removing Amount..........");
        display();
        }
    }
    public void display()
    {
        System.out.println("Name = "+name);
        System.out.println("Account Number = "+accno);
        System.out.println("Type of Account = "+typeofacc);
        System.out.println("Balance = "+bal);
        System.out.println("Rate of Interest = "+BankAccount.rate);
    }
    public static void disprate()
    {
        System.out.println("Static Rate of Interest = "+rate);
    }
}
class DemoBank
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name of Account Holder : ");
        String n = sc.next();
        System.out.println("Enter Account Number : ");
        long acc = sc.nextLong();
        System.out.println("Enter Type of Account : ");
        String t = sc.next();
        System.out.println("Enter Balance in Account : ");
        double b = sc.nextDouble();  
        
        BankAccount ba = new BankAccount();
        BankAccount ba1 = new BankAccount(n,acc,t,b);

        System.out.println("Enter Amount to be Deposited : ");
        double am = sc.nextDouble();
        ba1.depo(am);
        System.out.println("Enter Amount to be Withdrawn : ");
        double amm = sc.nextDouble();
        ba1.withdraw(amm);
        BankAccount.disprate();
    }
}
