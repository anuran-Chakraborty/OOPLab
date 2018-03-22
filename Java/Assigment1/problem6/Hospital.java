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
            System.out.println("Enter doctor id to assign to");
            id=sc.nextInt();
            pos=checkDoctor(id);
            if(pos==-1)
                System.out.println("Invalid doctor id");
        }
        while(pos==-1);
        String docname=doc.get(pos).getName();
        Patient p=new Patient(name,id,docname);
        pt.add(p);

    }

    //Function to take readings
    public void takeReadings()
    {
        int pos,id,ubp,lbp;
        double temp;
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
        if(!pt.get(pos).isChecked())
        {
            System.out.println("Patient is no longer in hospital");
            return;
        }

        do
        {
            System.out.println("Enter upper and lower blood pressure");
            ubp=sc.nextInt();
            lbp=sc.nextInt();

            if(ubp<=lbp)
                System.out.println("Invalid pressure");

        }
        while(ubp<=lbp);

        do
        {
            System.out.println("Enter body temperatur in fahrenheit");
            temp=sc.nextInt();

            if(temp<90 || temp>110)
                System.out.println("Invalid temperature");

        }
        while(temp<90 || temp>110);

        Readings r=new Readings(ubp,lbp,temp);
        Patient p=pt.get(pos);
        p.setRecord(r);
        pt.set(pos,p);
    }

    //Function to checkout a patient
    public void patientCheckout()
    {
        Scanner sc=new Scanner(System.in);
        int pos,id;

        do
        {
            System.out.println("Enter patient id..enter -1 to exit");
            id=sc.nextInt();
            pos=checkPatient(id);
            if(pos==-1)
                System.out.println("Invalid patient id");
        }
        while(pos==-1 && id!=-1);
        if(id==-1)
            return;
        
        if(!pt.get(pos).isChecked())
            System.out.println("Patient already checked out");
        else
        {
            Patient p=pt.get(pos);
            p.checkOut();
            pt.set(pos,p);
            System.out.println("Patient successfully checked out");
        }
            
    }
    
    //Function to display all readings of a patient
    public void displayReadings()
    {
        Scanner sc=new Scanner(System.in);
        int pos,id;

        do
        {
            System.out.println("Enter patient id");
            id=sc.nextInt();
            pos=checkPatient(id);
            if(pos==-1)
                System.out.println("Invalid patient id");
        }
        while(pos==-1);
        
        Patient p=pt.get(pos);
        p.showReadings();
    }

}