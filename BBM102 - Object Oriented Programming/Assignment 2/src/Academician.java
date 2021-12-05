public class Academician extends Personnel{

    //Constants
    static final int MAX_WORK_HOURS = 40;

    //Fields
    private double baseSalary = 2600;
    private double ssBenefits = 0;

    //Constructor
    Academician(String name, String surname, String registerNumber, String position, int yearOfStart) {
        super(name, surname, registerNumber, position, yearOfStart);
    }

    //Getters & Setters
    public double getBaseSalary() { return baseSalary; }
    public double getSsBenefits() { return ssBenefits; }
    public void setSsBenefits(double ssBenefits) { this.ssBenefits = ssBenefits; }

}
