import java.util.ArrayList;

public class CustomerDetails {
	
	private String name;
	private String surname;
	private String typeOfMembership;
	private String shoppingDate;


	public static ArrayList<ArrayList<String>>productList = new ArrayList<ArrayList<String>>();
	public static ArrayList<ArrayList<Integer>>quantityList = new ArrayList<ArrayList<Integer>>();

	private static ArrayList<CustomerDetails> customerList = new ArrayList<CustomerDetails>();
	
	
	//Constructors
	
	public CustomerDetails(String name, String surname, String typeOfMemberString, String shoppingDate) {
		this.name = name;
		this.surname = surname;
		this.typeOfMembership = typeOfMemberString;
		this.shoppingDate = shoppingDate;
	}
	
	public CustomerDetails() {
		
	}
	
	// Functions
	
	public static void addCustomerToList(CustomerDetails c) {
		customerList.add(c);
		
	}
	
	public static void addProductToList(ArrayList<String> tempList) {
		productList.add(tempList);
	}
	
	public static void addQuantityToList(ArrayList<Integer> tempQuantityProductList) {
		quantityList.add(tempQuantityProductList);
	}
	
	//Getters & Setters
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getSurname() {
		return surname;
	}
	public void setSurname(String surname) {
		this.surname = surname;
	}
	public String getTypeOfMembership() {
		return typeOfMembership;
	}
	public void setTypeOfMembership(String typeOfMembership) {
		this.typeOfMembership = typeOfMembership;
	}
	public String getShoppingDate() {
		return shoppingDate;
	}
	public void setShoppingDate(String shoppingDate) {
		this.shoppingDate = shoppingDate;
	}
	
	public static ArrayList<CustomerDetails> getCustomerList() {
		return customerList;
	}
		

	
}
