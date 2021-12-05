public class Chief extends FullTime {

    //Constants
    static final int MAX_WORK_HOURS = 8;

    //Constructor
    Chief(String name, String surname, String registerNumber, String position, int yearOfStart) {
        super(name, surname, registerNumber, position, yearOfStart);
        this.setIncomePerDay(125);
        this.setOverWorkHours(0);
        this.setOverWorkIncomePerHours(15);
    }

    //Methods
    @Override
    public void calculateSalary(int week1, int week2, int week3, int week4) {
        overWorkCalculate(week1, MAX_WORK_HOURS);
        overWorkCalculate(week2,MAX_WORK_HOURS);
        overWorkCalculate(week3,MAX_WORK_HOURS);
        overWorkCalculate(week4,MAX_WORK_HOURS);
        setSalary(getSeverancePay() + ( getIncomePerDay() * WORK_DAY * TOTAL_WEEK_IN_MONTH) + (getOverWorkHours() * getOverWorkIncomePerHours()));
    }

}
