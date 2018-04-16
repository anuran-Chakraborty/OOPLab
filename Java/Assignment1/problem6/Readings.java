package problem6;
import java.util.*;
import java.text.*;
class Readings
{
    private int ubp;
    private int lbp;
    private double temp;
    private String dateTime; 
    
    public Readings(int ubp, int lbp, double temp)
    {
        this.ubp=ubp;
        this.lbp=lbp;
        this.temp=temp;
        Date today = new Date();
        DateFormat formatter = new SimpleDateFormat("dd MMM yyyy HH:mm:ss"); 
        dateTime=formatter.format(today);
    }
    
    @Override
    public String toString()
    {
        String s=dateTime+"\nBP: "+Integer.toString(ubp)+"/"+
                Integer.toString(lbp)+"\nTEMPERATURE: "+Double.toString(temp);
        return s;
    }
}