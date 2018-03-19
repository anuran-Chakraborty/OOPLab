package problem5;
import java.util.*;
import java.io.*;

class Index
{
	Map<String, TreeSet<Integer>> posn;

	public Index()
	{
		posn=new TreeMap<>();
	}

	public void indexing()throws IOException
	{
		//Accept name of file
		File f;
		boolean flag;
		do
		{
			flag=true;
			System.out.println("Enter name of file to read");
			Scanner sc=new Scanner(System.in);
			String book=sc.nextLine();

			f=new File(book);
			if(!f.isFile())
			{
				System.out.println("Invalid file");
				flag=false;
			}
		}
		while(!flag);

		String wordList[];
		int i=1;
		//Read from file
		Scanner scf=new Scanner(f);
		while(scf.hasNextLine())
		{
			String line=scf.nextLine();
			line=line.replace(".","");
			line=line.replace(",","");
			line=line.replace(";","");
			wordList=line.split(" ");

			//Insert into HashMap
			for(String w:wordList)
			{	

				if(!posn.containsKey(w.toLowerCase()))
				{
					//Insert the key
					Integer lineNo=new Integer(i);
					TreeSet<Integer> lno=new TreeSet<>();
					lno.add(lineNo);
					posn.put(w.toLowerCase(),lno);

				}
				else
				{
					Integer lineNo1=new Integer(i);
					TreeSet<Integer> lno1=posn.get(w.toLowerCase());
					lno1.add(lineNo1);
					posn.put(w.toLowerCase(),lno1);

				}

			}
			i++;
		}
	}

	//Function to display
	public void display()
	{
		for(Map.Entry m:posn.entrySet())
		{
			System.out.println(m.getKey()+": "+m.getValue());
		}
	}
}