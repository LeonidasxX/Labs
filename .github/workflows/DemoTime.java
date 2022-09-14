import java.util.*;
class Time
{
    int hr;
    int min;
    int sec;
    public Time()
    {
        hr = 0;
        min = 0;
        sec = 0;
    }
    public Time(int hr,int min, int sec)
    {
        this.hr = hr;
        this.min = min;
        this.sec = sec;
    }
    // void add(Time obj1, Time obj2)
    // {
    //     Time ob = new Time();
    //     ob.hr = obj1.hr+obj2.hr;
    //     ob.min = obj1.min+obj2.min;
    //     ob.sec = obj1.sec+obj2.sec;
    //     if(ob.sec>=60)
    //     {
    //         ob.min = ob.min+1;
    //         ob.sec = ob.sec-60;
    //     }
    //     if(ob.min>=60)
    //     {
    //         ob.hr = ob.hr+1;
    //         ob.min = ob.min-60;
    //     }
    //     if(ob.hr>=24)
    //     {
    //         ob.hr = ob.hr-24;
    //     }
    //     display();
    // }
    // void subtract(Time obj1, Time obj2) 
    // {
    // Time ob = new Time();
    //     ob.hr = (int) Math.abs(obj1.hr-obj2.hr);
    //     ob.min = (int) Math.abs( obj1.min-obj2.min);
    //     ob.sec = (int) Math.abs(obj1.sec-obj2.sec);
    //     display();
    // }
    public void display()
    {
        System.out.println(hr+":"+min+":"+sec);
    }
}
public class DemoTime
{
    public static void main(String[] args)
    {
        Time obj1 = new Time(2,59,59);
        Time obj2 = new Time(3,5,6);
        // add(obj1,obj2);
        // subtract(obj1,obj2);
    }
}
