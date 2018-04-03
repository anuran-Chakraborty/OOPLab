package problem1;
public class Pizza1 implements Toppings
{
	private String topp;
	public Pizza1(String topping)
	{
		if(topping.equals("pepperoni"))
			topp=Toppings.pepperoni;
		else
		if(topping.equals("sausage"))
			topp=Toppings.sausage;
		else
		if(topping.equals("anchovy"))
			topp=Toppings.anchovy;
	}

	@Override
	public void display()
	{
		System.out.println("Pizza1 with "+topp);
	}
}