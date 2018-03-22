package problem3;
import java.util.ArrayList;
class Stck
{
	//Data members
	ArrayList<Character> lst;
	int top;

	public Stck()
	{
		lst=new ArrayList<Character>();
		top=-1;
	}

	public void push(Character c)
	{
		lst.add(c);
		top++;
	}

	public boolean empty()
	{
		return top==-1;
	}

	public Character pop()
	{
		if(!empty())
		{
			Character c=lst.get(top);
			lst.remove(top--);
			return c;
		}
		return '\0';
	}


}
