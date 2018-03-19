package problem7;
import java.io.*;
import java.util.*;
import java.text.*;

class fileComparatorDate implements Comparator<File>
{
	public int compare(File f1, File f2){
		return (int)(f1.lastModified()-f2.lastModified());
	}
}

class fileComparatorSize implements Comparator<File>
{
	public int compare(File f1, File f2){
		return (int)(f1.length()-f2.length());
	}
}



class FileSort
{
	ArrayList<File> files=new ArrayList<>();

	public void fillList(String src)
	{
		File path=new File(src);
		File[] fl=path.listFiles();
		for(File f:fl)
			files.add(f);
	}

	public void nameSort()
	{
		Collections.sort(files);
	}

	public void dateSort()
	{
		Collections.sort(files, new fileComparatorDate());
	}

	public void sizeSort()
	{
		Collections.sort(files , new fileComparatorSize());
	}

	public void display()
	{
		SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");
		for(File f:files)
			System.out.println(f.getName()+"\t\t"+sdf.format(f.lastModified())+"\t\t"+(f.length()/1024)+"KB");
	}
}
