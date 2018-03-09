package problem4;

import java.util.Random;
class QuoteOfTheDay
{
    private String arr[]={"a","b","c","d"};
    
    public void getQuote()
    {
        Random rand=new Random();
        int num=rand.nextInt(arr.length);
        
        System.out.println(arr[num]);
    }
}
