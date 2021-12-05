public class Personnel {

    //Constants
    static final int CURRENT_YEAR = 2020;
    static final int TOTAL_WEEK_IN_MONTH = 4;

    //Fields
    private String name;
    private String surname;
    private String registerNumber;
    private String position;
    private int yearOfStart;
    private double severancePay;
    private double salary;

    // Constructor
    public Personnel(String name, String surname, String registerNumber, String position, int yearOfStart) {
        this.name = name;
        this.surname = surname;
        this.registerNumber = registerNumber;
        this.position = position;
        this.yearOfStart = yearOfStart;
        this.severancePay = (CURRENT_YEAR - yearOfStart) * 20 * 0.8;
    }

    // Getters & Setters

    public double getSalary() { return salary; }
    public void setSalary(double salary) { this.salary = salary; }
    public String getRegisterNumber() { return registerNumber; }
    public double getSeverancePay() { return severancePay; }

    // Methods

    public void calculateSalary(int week1, int week2, int week3, int week4) { }

    @Override
    public String toString() {
        return "Name : " + name + "\n" +
               "Surname : "+ surname + "\n" +
               "Registration Number : " + registerNumber + "\n" +
                "Position : " + position + "\n" +
                "Year of Start : " + yearOfStart + "\n" +
                "Total Salary: " + String.format("%.2f",salary) + " TL\n";
    }

}