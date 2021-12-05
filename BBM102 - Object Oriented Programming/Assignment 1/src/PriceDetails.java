import java.util.ArrayList;

public class PriceDetails {
	
	private String productName;
	private String typeOfMembership;
	private String startDate;
	private String endDate;
	private Double price;
	
	private static ArrayList<PriceDetails> priceList = new ArrayList<PriceDetails>();
	
	//Constructors
	
	PriceDetails(
			String productName,
			String typeOfMembership,
			String startDate,
			String endDate,
			Double price) {
		
		this.productName = productName;
		this.typeOfMembership = typeOfMembership;
		this.startDate = startDate;
		this.endDate = endDate;
		this.price = price;
	}
	
	// Functions
	
		public static void addPriceToList(PriceDetails p) {
			priceList.add(p);
		}
		

		public static ArrayList<PriceDetails> getPriceList() {
			return priceList;
		}
	
		
	// Getters & Setters
	
	public String getProductName() {
		return productName;
	}
	public void setProductName(String productName) {
		this.productName = productName;
	}
	public String getTypeOfMembership() {
		return typeOfMembership;
	}
	public void setTypeOfMembership(String typeOfMembership) {
		this.typeOfMembership = typeOfMembership;
	}
	public String getStartDate() {
		return startDate;
	}
	public void setStartDate(String startDate) {
		this.startDate = startDate;
	}
	public String getEndDate() {
		return endDate;
	}
	public void setEndDate(String endDate) {
		this.endDate = endDate;
	}
	public Double getPrice() {
		return price;
	}
	public void setPrice(Double price) {
		this.price = price;
	}
	
	
	
}
