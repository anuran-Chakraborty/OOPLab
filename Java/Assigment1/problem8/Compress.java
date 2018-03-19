package problem8;

import java.util.*;
import java.util.zip.*;
import java.io.*;
class Compress
{
	private static ArrayList<String> filesList=new ArrayList<String>();
	
	public static void gzipFile(String source, String destination)
	{
		try
		{
			FileOutputStream fos=new FileOutputStream(destination);
			GZIPOutputStream gos=new GZIPOutputStream(fos);
			FileInputStream fis=new FileInputStream(source);

			int length;
			byte buffer[]=new byte[1024];
			while((length=fis.read(buffer))>0)
			{
				gos.write(buffer,0,length);
			}
			fis.close();
			gos.finish();
			gos.close();
			System.out.println("File compression successfull!");
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}

	}

	public static void getFilesInList(File src)
	{
		File directory=new File(src.getAbsolutePath());
		File[] flist=directory.listFiles();
		for(File fl:flist)
		{
			if(fl.isFile())
			{
				filesList.add(fl.getAbsolutePath().substring(fl.getAbsolutePath().lastIndexOf('/')+1));
			}
			else
				if(fl.isDirectory())
				{
					getFilesInList(fl);
				}
			}
		}
		public static void zipDirectory(File src, String destination)
		{
			try
			{
				getFilesInList(src);
				FileOutputStream fos=new FileOutputStream(destination);
				ZipOutputStream zos=new ZipOutputStream(fos);

				for(String path:filesList)
				{
					System.out.println("Zipping "+path);
					ZipEntry ze=new ZipEntry(path.substring(src.getAbsolutePath().length()+1,path.length()));//relative path
					zos.putNextEntry(ze);
					FileInputStream fis=new FileInputStream(path);
					byte buffer[]=new byte[1024];
					int len;
					while((len=fis.read(buffer))>0)
						zos.write(buffer,0,len);
					zos.closeEntry();
					fis.close();
			}
			zos.close();
			fos.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}