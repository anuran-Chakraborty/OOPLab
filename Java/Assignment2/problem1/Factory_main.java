package problem1;
import java.util.*;
class Factory_main
{
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		PizzaFactory factory=new PizzaFactory();

		System.out.println("Enter pizza type as Pizza1, Pizza2, or Pizza3");
		String type=sc.next();
		System.out.println("Enter toppings type as pepperoni, sausage, or anchovy");
		String top=sc.next();

		Toppings t1=factory.getPizza(top,type);
		if(t1==null)
			System.out.println("Invalid input");
		else
			t1.display();

	}
} 