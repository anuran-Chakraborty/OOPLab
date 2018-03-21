package problem6;

class Readings
{
    private int bp;
    private int temp;
    
    public Readings(int bp,int temp)
    {
        this.bp=bp;
        this.temp=temp;
    }
    
    @Override
    public String toString()
    {
        String s="BP: "+Integer.toString(bp)+"\nTEMPERATURE: "+Integer.toString(temp);
        return s;
    }
}