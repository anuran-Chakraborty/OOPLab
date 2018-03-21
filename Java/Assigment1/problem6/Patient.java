package problem6;

import java.util.*;

class Patient
{
    //Data members
    private static int lastId=0;
    private String name;
    private int id;
    private ArrayList<Readings> record;
    private int docid;
    private String docname;
    private int status;

    //Constructor
    public Patient(String name,int did)
    {
        this.name=name;
        id=10000+lastId++;
        docid=did;
        record=new ArrayList<>();
    }

    //Function to assign a doctor
    // public void assignDoctor(int did,String n)
    // {
    // docid=did;
    // docname=new String(n);
    // }

    //Function to set bp and temp
    public void setReacord(Readings r)
    {
        record.add(r);
    }

    //Function to get id
    public int getId()
    {
        return id;
    }

    //Function to get docid
    public int getDocId()
    {
        return docid;
    }
    
    //Function  to display
    public void display()
    {
        System.out.println("Id: "+id+"\nName: "+name);
        if(docid==0)
            System.out.println("Assigned to: None");
        else
            System.out.println("Assigned to: "+docid);
    }
    
    //Function to show all readings
    
}