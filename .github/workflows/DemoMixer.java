import java.util.*;
class Mixer
{
    Scanner sc = new Scanner(System.in);
    int n;
    int arr[] = new int[100];
    public void accept()
    {
        System.out.println("Enter number of elements : ");
        n = sc.nextInt();
        System.out.println("Enter Array Elements in Ascending Order and without any Repetition: ");
        for(int i = 0 ; i < n ; i++)
            arr[i] = sc.nextInt();
    }
    public Mixer mix(Mixer x, Mixer y)
    {
        Mixer ob = new Mixer();
        ob.n = x.n + y.n;
        int temp = 0;
        for(int i = 0 ; i < ob.n ; i++)
        {
            if(i < x.n)
                ob.arr[i] = x.arr[i];
            else
            {
                ob.arr[i] = y.arr[temp];
                temp++;
            }
        }
        display(ob);
        return ob;
    }
    public void display(Mixer ob)
    {
        for(int i = 0 ; i < ob.n ; i++)
            System.out.print(ob.arr[i]+" ");
        System.out.println();
    }
}
public class DemoMixer
{
    public static void main(String args[])
    {
        Mixer a = new Mixer();
        Mixer b = new Mixer();
        Mixer c = new Mixer();
        a.accept();
        b.accept();
        c.mix(a,b);
    }
}
