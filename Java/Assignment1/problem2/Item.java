package problem2;

import java.util.*;
class Item
{
    //Data members
    private static int id=0;
    private int code;
    private String name;
    private double rate;
    private int qty;

    //Constructor
    public Item(String nm, double r,int q)
    {
        name=nm;
        rate=r;
        qty=q;
        code=10000+id;
        id++;
    }

    //Set rate
    public void setRate(double r)
    {
        rate=r;
    }

    //Set quantity
    public void setQty(int q)
    {
        qty=q;
    }
    
    //Get quantity
    public int getQty()
    {
        return qty;
    }
    
    //Get rate
    public double getRate()
    {
        return rate;
    }
    
    //Get code
    public int getCode()
    {
        return code;
    }
    
    //Function to display item
    public void display()
    {
        System.out.println("Code :"+code+"\nName: "+name+"\nRate: "+rate+"\nQuantity: "+qty);
    }
}
