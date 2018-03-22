package problem7;
import java.io.*;
import java.util.*;

class FileSort_main
{
	public static void main(String[] args) 
	{
		if(args.length==1)
		{
			if(args[0].compareTo("-s")!=0 && args[0].compareTo("-d")!=0)
			{
				System.out.println("Invalid options");
				return;
			}
		}
		FileSort fs=new FileSort();

		boolean flag=true;
		Scanner sc=new Scanner(System.in);
		String src="";
		do
		{
			try
			{
				flag=true;
				System.out.println("Enter name of directory");
				src=sc.nextLine();
			}
			catch(Exception e)
			{
				e.printStackTrace();
				flag=false;
			}

			
		}
		while(!flag);

		if(args.length==1)
		{
			if(args[0].compareTo("-s")==0)
			{
				fs.fillList(src);
				fs.sizeSort();
				fs.display();
				return;
			}
			else
				if(args[0].compareTo("-d")==0)
				{
					fs.fillList(src);
					fs.dateSort();
					fs.display();
					return;
				}
				else
				{
					System.out.println("Invalid options");
				}
			}
			else
			{

				fs.fillList(src);
				fs.nameSort();
				fs.display();
			}

			
		}
	}