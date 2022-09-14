import java.util.*;

class Complex{
    double real;
    double imag;

    public Complex(){
        real=0;
        imag=0;
    }
    public Complex(double real, double imag){
        this.real = real;
        this.imag = imag;
    }
    public void display(Complex ob){
        System.out.println("Complex: " + ob.real + "+" + ob.imag +"i");
    }
    public Complex add(Complex n1, Complex n2)
    {
        Complex temp = new Complex();

        temp.real = n1.real + n2.real;
        temp.imag = n1.imag + n2.imag;
        display(temp);
        return(temp);
    }
    public Complex subtract(Complex n1, Complex n2)
    {
        Complex temp = new Complex();

        temp.real = Math.abs(n1.real - n2.real);
        temp.imag = Math.abs(n1.imag - n2.imag);
        display(temp);
        return(temp);
    }
}
class DemoComplex
{
    public static void main(String[] args) {
        Complex n1 = new Complex(2.3, 4.5),
                n2 = new Complex(3.4, 5.0),
                temp = new Complex();

        temp.add(n1, n2);
        temp.subtract(n1,n2);
    }
}