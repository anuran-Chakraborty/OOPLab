package problem6;

import java.util.*;
class Hospital
{
    ArrayList<Patient> pt;
    ArrayList<Doctor> doc;

    //Constructor
    public Hospital()
    {
        pt=new ArrayList<>();
        doc=new ArrayList<>();
    }

    //Function to check if a doctor is in list
    public int checkDoctor(int id)
    {
        int pos=-1;
        for(Doctor i:doc)
        {
            if(i.getId()==id)
                return ++pos;
            pos++;
        }
        return -1;
    }
    
    //Function to check if a patient is in list
    public int checkPatient(int id)
    {
        int pos=-1;
        for(Patient i:pt)
        {
            if(i.getId()==id)
                return ++pos;
            pos++;
        }
        return -1;
    }

    //Function to add new doctor
    public void addDoctor()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter name of doctor");
        String name=sc.nextLine();

        Doctor dr=new Doctor(name);
        dr.display();
        doc.add(dr);

    }

    //Function to add new patient
    public void addPatient()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter name of patient");
        String name=sc.nextLine();
        int pos,id;

        do
        {
            System.out.println("Enter doctor id");
            id=sc.nextInt();
            pos=checkDoctor(id);
            if(pos==-1)
                System.out.println("Invalid doctor id");
        }
        while(pos==-1);
        
        Patient p=new Patient(name,id);
        pt.add(p);
        
    }
    
    //Function to take readings
    public void takeReadings()
    {
        int pos,id;
        Scanner sc=new Scanner(System.in);
        do
        {
            System.out.println("Enter patient id");
            id=sc.nextInt();
            pos=checkPatient(id);
            if(pos==-1)
                System.out.println("Invalid patient id");
        }
        while(pos==-1);
        
        
    }
}