public class Main {

	public static void main(String[] args) {
		
	
		ReadFromFile input = new ReadFromFile();
			
		//This two lines read text file to list.
		String [] shoppingInput = input.readFile(args[0]);
		String [] priceInput = input.readFile(args[1]);
		
		//iterate line in lines.
		for(String line : shoppingInput) {
			input.readCustomerInput(line);
		}
		
		for(String line : priceInput) {
			input.readPriceInput(line);
		}
		
		//Calculate billing and display output
		Billing calculate = new Billing();
		calculate.billing();
		
	}

}
