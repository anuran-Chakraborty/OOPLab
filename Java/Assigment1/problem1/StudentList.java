package problem1;

import java.util.*;
import java.text.SimpleDateFormat;
public class StudentList
{
    ArrayList<StudentDept> arr;
    
    StudentList(){
        Student.setCount();
        arr=new ArrayList<>();
    }

    void readData()
    {
        StudentDept s=new StudentDept();
        s.readData();
        s.display();
        arr.add(s);
    }

    StudentDept search(String r)
    {
        for(StudentDept s:arr){
            if (s.getRoll().equals(r))
                return s;
        }
        return null;
    }

    void readMarks(){
        System.out.println("Enter roll");
        Scanner sc=new Scanner(System.in);
        String r=sc.nextLine();
        StudentDept s=search(r);
        if(s==null)
            System.out.println("Student not found");
        else
            s.recMarks();
    }

    void preSheet(){
        System.out.println("Enter roll");
        Scanner sc=new Scanner(System.in);
        String r=sc.nextLine();
        StudentDept s=search(r);
        if(s==null)
            System.out.println("Student not found");
        else
            s.display();
    }

    ArrayList<StudentDept> enlist(int dep){
        ArrayList<StudentDept> DeptStu=new ArrayList<>();
        for(StudentDept s:arr){
            if(s.getDept().equals(StudentDept.deptList[dep-1]));
                DeptStu.add(s);
        }
        return DeptStu;
    }

    void removeStu(){
        Iterator<StudentDept> iter=arr.iterator();
        while(iter.hasNext()){
            if(iter.next().getTotal()<200.0)
                iter.remove();
        }
    }

    void display(){
        System.out.println("Roll\tName\tCourse\tDate of adm\tTotal");
        SimpleDateFormat f=new SimpleDateFormat("dd/MM/yyyy");
        for(StudentDept s:arr)
            System.out.println(s.getRoll()+"\t"+s.getName()+"\t"+s.getCourse()+"\t"+f.format(s.getDate())+"\t"+s.getTotal());
    }

    void display(ArrayList<StudentDept> a){
        System.out.println("Roll\tName\tDept\tCourse\tDate of adm\tTotal");
        SimpleDateFormat f=new SimpleDateFormat("dd/MM/yyyy");
        for(StudentDept s:a)
            System.out.println(s.getRoll()+"\t"+s.getName()+"\t"+s.getDept()+"\t"+s.getCourse()+"\t"+f.format(s.getDate())+"\t"+s.getTotal());
    }
}