package problem3;

import java.util.*;

public class Parenthesis
{
    private Stck brackets;
    private String expr;
    
    public Parenthesis()
    {
        expr="";
        brackets=new Stck();
        
    }

    //Function to accept expression
    public void accept()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your expression");
        expr=sc.nextLine();
    }

    //Function to check order of brackets
    public void check()
    {
        int i;
        char ch,c;
        Character cc;
        boolean flag=true;
        for(i=0;i<expr.length();i++)
        {
            c=expr.charAt(i);
            if(i==0 && (c==')'||c=='}'||c==']'))
            {
                flag=false;
                break;
            }
            if(c=='(' || c=='{' || c=='[')
            {
                cc=new Character(c);
                brackets.push(cc);
            }
            else
            if(c==')')
            {   
                if(brackets.empty())
                {
                    flag=false;
                    break;
                }
                ch=brackets.pop().charValue();
                if(ch!='(')
                {
                    flag=false;
                    break;
                }
            }

            else
            if(c=='}')
            {   
                if(brackets.empty())
                {
                    flag=false;
                    break;
                }
                ch=brackets.pop().charValue();
                if(ch!='{')
                {
                    flag=false;
                    break;
                }
            }

            else
            if(c==']')
            {   
                if(brackets.empty())
                {
                    flag=false;
                    break;
                }
                ch=brackets.pop().charValue();
                if(ch!='[')
                {
                    flag=false;
                    break;
                }
            }
        }

        if(flag==true)
            System.out.println("Order is correct");
        else
            System.out.println("Order is incorrect");
    }
}