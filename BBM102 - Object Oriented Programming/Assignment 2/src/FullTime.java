public class FullTime extends Employee {

    //Constants
    static final int WORK_DAY = 5; // full time employee work only 5 days
    static final int TOTAL_WORK_HOURS = 40;

    //Fields
    private double incomePerDay = 0;
    private double overWorkHours = 0;
    private double overWorkIncomePerHours = 0;

    //Constructor
    FullTime(String name, String surname, String registerNumber, String position, int yearOfStart) {
        super(name, surname, registerNumber, position, yearOfStart);
    }

    // Getters & Setters
    public double getIncomePerDay() {
        return incomePerDay;
    }
    public void setIncomePerDay(double incomePerDay) {
        this.incomePerDay = incomePerDay;
    }
    public double getOverWorkHours() {
        return overWorkHours;
    }
    public void setOverWorkHours(double overWorkHours) {
        this.overWorkHours = overWorkHours;
    }
    public double getOverWorkIncomePerHours() {
        return overWorkIncomePerHours;
    }
    public void setOverWorkIncomePerHours(double overWorkIncomePerHours) { this.overWorkIncomePerHours = overWorkIncomePerHours; }

    // Functions
    public void overWorkCalculate(int week, int MAX_WORK_HOURS) {
        if(week - TOTAL_WORK_HOURS > 0) {
            overWorkHours += Math.min(week - TOTAL_WORK_HOURS, MAX_WORK_HOURS);
        }
    }
}
