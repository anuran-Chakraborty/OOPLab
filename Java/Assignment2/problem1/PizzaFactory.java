package problem1;
public class PizzaFactory
{
	public Toppings getPizza(String topping, String pizzaType)
	{
		if(pizzaType.equals("Pizza1"))
			return new Pizza1(topping);
		else
		if(pizzaType.equals("Pizza2"))
			return new Pizza2(topping);
		else
		if(pizzaType.equals("Pizza3"))
			return new Pizza3(topping);
		return null;
	}
}