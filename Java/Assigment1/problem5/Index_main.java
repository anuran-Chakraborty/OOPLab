package problem5;
import java.util.*;
import java.io.*;

class Index_main
{
	public static void main(String[] args) 
	{
		Index idx=new Index();
		try
		{
			idx.indexing();
			idx.display();
		}
		catch(Exception e)
		{

			e.printStackTrace();
		}
	}	
}