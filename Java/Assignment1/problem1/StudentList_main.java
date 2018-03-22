package problem1;

import java.util.*;
class StudentList_main
{
    public static void main(String args[]){
        int ch,ch2;
        StudentList sl=new StudentList();
        do{
            System.out.println("Enter choice");
            System.out.println("1. Admission of student");
            System.out.println("2. Enter marks of a student");
            System.out.println("3. Display marksheet of a student");
            System.out.println("4. Show number of students in a dept");
            System.out.println("5. Show total number of students");
            System.out.println("6. Display sorted list of students");
            System.out.println("7. Remove student");
            System.out.println("8. Exit");
            Scanner sc=new Scanner(System.in);
            ch=sc.nextInt();
            switch(ch){
                case 1:
                sl.readData();
                break;
                
                case 2:                 
                sl.readMarks();
                break;
                
                case 3:
                sl.preSheet();
                break;
                
                case 4:
                System.out.println("Enter dept.\n1.BCSE\n2.ETCE\n3.EE\n4.IT");//VALIDATE
                System.out.println("Number of students enrolled = "+StudentDept.getCount(sc.nextInt()-1));
                break;
                
                case 5:
                System.out.println("Number of students enrolled = "+Student.getCount());
                break;
                
                case 6:
                System.out.println("Enter dept\n1.BCSE\n2.ETCE\n3.EE\n4.IT\n5.All");//VALIDATE
                ch2=sc.nextInt();
                ArrayList<StudentDept> a2=new ArrayList<>();
                if(ch2!=5){
                    a2=sl.enlist(ch2);
                    Collections.sort(a2);
                    sl.display(a2);
                }
                else{
                    Collections.sort(sl.arr);
                    sl.display();
                }
                break;
                
                case 7:
                sl.removeStu();
                break;
                
                case 8:
                System.out.println("Exiting");
                break;
                
                default:
                System.out.println("Wrong choice!\nEnter once again");
            }
        }while(ch!=8);
    }
}