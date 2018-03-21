package problem6;

class Doctor
{
    private static int lastId=0;
    private String name;
    private int id;
    
    //Constructor
    public Doctor(String name)
    {
        this.name=name;
        id=20000+lastId++;
    }
    
    //Function to get id
    public int getId()
    {
        return id;
    }
    
    //Function to get name
    public String getName()
    {
        return name;
    }
    
    //Function to display doctor details
    public void display()
    {
        System.out.println("Id: "+id+"\nName: "+name);
    }
    
    
}