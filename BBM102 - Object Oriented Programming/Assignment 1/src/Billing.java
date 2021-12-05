import java.text.*;
import java.util.Date;

public class Billing {
			
	Display display = new Display();
	
	
	// Compare customer input and price input. If it's match print out results.
	public void billing()  {
		
			
		for(int i=0; i < CustomerDetails.getCustomerList().size(); i++) {
				
			String name = CustomerDetails.getCustomerList().get(i).getName();
			String surname = CustomerDetails.getCustomerList().get(i).getSurname();
			display.displayCustomer(name, surname);
			
			double colTotal = 0;
			
			for(int k = 0; k < CustomerDetails.productList.get(i).size(); k++ ) {
				
				for(int j = 0; j < PriceDetails.getPriceList().size(); j++) {
					
					String s1 = CustomerDetails.productList.get(i).get(k);
					String s2 = PriceDetails.getPriceList().get(j).getProductName();
					String s3 = CustomerDetails.getCustomerList().get(i).getTypeOfMembership();
					String s4 = PriceDetails.getPriceList().get(j).getTypeOfMembership();
						
					if(s1.equals(s2) && s3.equals(s4)) {
						
						String pattern = "dd.MM.yyyy";
						String date = CustomerDetails.getCustomerList().get(i).getShoppingDate();
						SimpleDateFormat simpleDateFormat = new SimpleDateFormat(pattern);
						String startDate = PriceDetails.getPriceList().get(j).getStartDate();
						String endDate = PriceDetails.getPriceList().get(j).getEndDate();
						
						try {
							Date todayDate = simpleDateFormat.parse(date);
							Date startDate1 = simpleDateFormat.parse(startDate);
							Date endDate1 = simpleDateFormat.parse(endDate);
							
							if(todayDate.after(startDate1) && todayDate.before(endDate1)) {
								
								String productName = CustomerDetails.productList.get(i).get(k);
								int quantity = CustomerDetails.quantityList.get(i).get(k);
								double price = PriceDetails.getPriceList().get(j).getPrice();
								double rowTotal = quantity * price;
								colTotal += rowTotal;
								
								Display.displayTotal(productName, quantity, price, rowTotal);
								if(k == CustomerDetails.productList.get(i).size() - 1)
									System.out.println("Total " + String.format("%.1f", colTotal));
							}
											
						} catch (ParseException e) {
							e.printStackTrace();
						}
					}
				}
			
			}
			
		}
	}
	
}
