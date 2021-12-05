import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class ReadFromFile {
	
	//Read whole text file into array.
	public String[] readFile(String path){
		try {
			int i = 0;
			int length = Files.readAllLines(Paths.get(path)).size();
			String[] results = new String[length];
				for(String line : Files.readAllLines(Paths.get(path))) {
					results[i++] = line;
				}			
			return results;
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}
	
	// Tokenize customer input and store in array list.
	
	public void readCustomerInput(String line) {	
		String[] tokens = line.split("\t");
		String[] splitName = tokens[0].split(" ");
		
		CustomerDetails tempCustomer = new CustomerDetails(splitName[0], splitName[1], tokens[1],tokens[2]);
		
		ArrayList<String> tempPurchasedProductList = new ArrayList<>();
		ArrayList<Integer> tempPurchasedQuantityList = new ArrayList<>();
		
		int i = 3;
		while (i < tokens.length) {
			tempPurchasedProductList.add(tokens[i]);	
			tempPurchasedQuantityList.add(Integer.parseInt(tokens[i+1]));	
			i+=2;
			
		}
		
		CustomerDetails.addProductToList(tempPurchasedProductList);
		CustomerDetails.addQuantityToList(tempPurchasedQuantityList);
		CustomerDetails.addCustomerToList(tempCustomer);
	}
	
	// Tokenize price input and store in array list.
	
	public void readPriceInput(String line) {
		
		String[] tokens = line.split("\t");
		PriceDetails tempPriceDetails = new PriceDetails(tokens[0], tokens[1], tokens[2], tokens[3], Double.parseDouble(tokens[4]));
		PriceDetails.addPriceToList(tempPriceDetails);

	}
	
}
