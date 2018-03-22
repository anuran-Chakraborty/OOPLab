package problem6;

import java.util.*;
class Hospital_main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int ch,cntd=0,cntp=0;
        Hospital h=new Hospital();
        do
        {
            System.out.println("1. Add a new doctor\n2. Add a new patient\n3. Take readings\n4. Checkout patient\n5. Display all readings of a patient\n6. Exit");
            System.out.println("Enter choice");
            ch=sc.nextInt();

            switch(ch)
            {
                case 1:
                h.addDoctor();
                cntd++;
                break;

                case 2:
                if(cntd==0)
                {
                    System.out.println("Add some doctor first before adding patient");
                    break;
                }
                h.addPatient();
                cntp++;
                break;

                case 3:
                if(cntp==0 || cntd==0)
                {
                    System.out.println("Add some pateint or doctor first before taking any recording");
                    break;
                }
                h.takeReadings();
                break;
                
                case 4:
                if(cntp==0)
                {
                    System.out.println("Add some pateint first");
                    break;
                }
                h.patientCheckout();
                break;
                
                case 5:
                if(cntp==0)
                {
                    System.out.println("Add some pateint first");
                    break;
                }
                h.displayReadings();
                break;
                
                case 6:
                System.out.println("Now quitting");
                System.exit(0);
                break;
                
                default:
                System.out.println("invalid choice");

            }

        }
        while(ch!=6);
    }   
}