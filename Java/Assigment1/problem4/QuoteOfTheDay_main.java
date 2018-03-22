package problem4;

import java.util.*;
import java.util.prefs.Preferences;

class QuoteOfTheDay_main
{
    public static void main(String[] args) 
    {

        QuoteOfTheDay obj=new QuoteOfTheDay();
        Scanner sc=new Scanner(System.in);
        String quote=sc.next();
        if(quote.equals("QuoteOfTheDay")==false)
        {
            System.out.println("Please Enter proper quote");

        }
        else
        {
            obj.fillmorning();
            obj.fillnoon();
            obj.fillnight();
            obj.fillevening();
            obj.fillspecialdays();

            String date=obj.getcurrDate();
            String time=obj.getcurrTime();
            
                        
            int day=Integer.parseInt(date.substring(0,date.indexOf("/")));
            int month=Integer.parseInt(date.substring(date.indexOf("/")+1,date.lastIndexOf("/")));
            int year=Integer.parseInt(date.substring(date.lastIndexOf("/")+1));
            int hour=Integer.parseInt(time.substring(0,time.indexOf(":")));
            int min=Integer.parseInt(time.substring(time.indexOf(":")+1,time.lastIndexOf(":")));
            int sec=Integer.parseInt(time.substring(time.lastIndexOf(":")+1));
            
            Preferences userprefs= Preferences.userRoot();

           
            if(day==14 && month==11)
            {
                ArrayList<String> sp=QuoteOfTheDay.specialdays.get(14);
                int cspchild=userprefs.getInt("cspchild",0);
                if(cspchild==sp.size()-1)
                    cspchild=0;
                System.out.println(sp.get(cspchild));
                userprefs.putInt("cspchild",cspchild+1);
            }
            else if(day==5 && month==9)
            {
                ArrayList<String> sp=QuoteOfTheDay.specialdays.get(5);
                int cspteacher=userprefs.getInt("cspteacher",0);
                if(cspteacher==sp.size()-1)
                    cspteacher=0;
                System.out.println(sp.get(cspteacher));
                userprefs.putInt("cspteacher",cspteacher+1);
            }
            else if(day==15 && month==8)
            {
                ArrayList<String> sp=QuoteOfTheDay.specialdays.get(15);
                int cspind=userprefs.getInt("cspind",0);
                if(cspind==sp.size()-1)
                    cspind=0;
                System.out.println(sp.get(cspind));
                userprefs.putInt("cspind",cspind+1);
            }
            else
            {
                if((hour>=6 && hour<=11)|| (hour==12 && min==0))
                {
                    int morn=userprefs.getInt("morning", 0);
                    if(morn==QuoteOfTheDay.morning.size()-1)
                        morn=0;
                    System.out.println(QuoteOfTheDay.morning.get(morn));
                    userprefs.putInt("morning",morn+1);

                }
                else if((hour>=12 && hour<=16)|| (hour==17 && min==0))
                {
                    int afternoon=userprefs.getInt("afternoon", 0);
                    if(afternoon==QuoteOfTheDay.noon.size()-1)
                        afternoon=0;
                    System.out.println(QuoteOfTheDay.noon.get(afternoon));
                    userprefs.putInt("afternoon",afternoon+1);

                }
                else if((hour>=17 && hour<=19)|| (hour==20 && min==0))
                {
                    int evening=userprefs.getInt("evening", 0);
                    if(evening==QuoteOfTheDay.eve.size()-1)
                        evening=0;
                    System.out.println(QuoteOfTheDay.eve.get(evening));
                    userprefs.putInt("evening",evening+1);
                }
                else if((hour>=20 && hour<=23)||(hour>=0 && hour<=5)|| (hour==6 && min==0))
                {
                    int nights=userprefs.getInt("night", 0);
                    if(nights==QuoteOfTheDay.night.size()-1)
                        nights=0;
                    System.out.println(QuoteOfTheDay.night.get(nights));
                    userprefs.putInt("night",nights+1);
                }

            }

        }

          
    }
}