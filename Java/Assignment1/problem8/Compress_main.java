package problem8; 

import java.util.*;
import java.util.zip.*;
import java.io.*;

class Compress_main
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        int ch;
        boolean flag;
        String fileName="";
        File file=null;
        do
        {
            System.out.println("1. Compress a single file using gzip\n2. Compress all files in directory\n3.Exit\nEnter choice");
            ch=sc.nextInt();

            switch(ch)
            {
                case 1:
                do
                {
                    try
                    {
                        flag=true;
                        System.out.println("Enter name of source file");
                        fileName=sc.next();
                        file=new File(fileName);

                        // if(!file.isFile())
                        // {
                        // 	System.out.println("Invalid input not a file");
                        // 	flag=false;
                        // }
                    }
                    catch(Exception e)
                    {
                        e.printStackTrace();
                        flag=false;
                    }
                }
                while(flag==false);
                Compress.gzipFile(fileName,fileName+".gz");
                break;

                case 2:
                do
                {
                    try
                    {
                        flag=true;
                        System.out.println("Enter name of source directory");
                        fileName=sc.next();
                        file=new File(fileName);
                        // if(!file.isDirectory())
                        // {
                        // 	System.out.println("Invalid input not a directory");
                        // 	flag=false;
                        // }
                    }
                    catch(Exception e)
                    {
                        e.printStackTrace();
                        flag=false;
                    }
                }
                while(flag==false);
                Compress.zipDirectory(file,"files2.zip");
                break;

                case 3:
                System.out.println("Now quitting");
                break;

                default:
                System.out.println("Invalid choice");

            }

        }
        while(ch!=3);
    }
}