package problem1;
public class Pizza2 implements Toppings
{
	private String topp;
	public Pizza2(String topping)
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
		System.out.println("Pizza2 with "+topp);
	}
}