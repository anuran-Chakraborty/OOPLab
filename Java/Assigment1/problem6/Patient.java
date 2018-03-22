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
    public Patient(String name,int did, String dname)
    {
        this.name=name;
        id=10000+lastId++;
        docid=did;
        docname=dname;
        record=new ArrayList<>();
        status=1;
    }

    //Function to assign a doctor
    // public void assignDoctor(int did,String n)
    // {
    // docid=did;
    // docname=new String(n);
    // }

    //Function to set bp and temp
    public void setRecord(Readings r)
    {
        record.add(r);
    }

    //Function to check ifa patient is still in hospital
    public boolean isChecked()
    {
        return status==1;
    }

    //Function to check out a patient
    public void checkOut()
    {
        status=0;
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
            System.out.println("Assigned to: "+docname);
    }

    //Function to show all readings
    public void showReadings()
    {
        System.out.println("Taken by: "+docname);
        System.out.println("--------------------------------------------------");
        for(Readings r:record)
        {
            System.out.println(r);
            System.out.println("--------------------------------------------------");
        }
    }
}