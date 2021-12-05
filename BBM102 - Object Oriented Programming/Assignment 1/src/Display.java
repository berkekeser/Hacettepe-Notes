public class Display {

	
	// print out product name, quantity, price, total
	public static void displayTotal(String productName, int quantity, double price, double rowTotal) {
		
		System.out.println(productName + "\t" + price + "\t" + quantity + "\t" +String.format("%.1f", rowTotal));
		

	}
	
	
	// print out customer name and surname.
	public void displayCustomer(String name, String surname) {
		System.out.println("---" + 
				name + 
				" " +
				surname + 
				"---");
	}
	
}
