public class PartTime extends Employee {

    //Constants
    static final int MIN_WORK_HOURS = 10;
    static final int MAX_WORK_HOURS = 20;

    //Fields
    private double hourOfWork = 0;
    private double incomePerHour = 18;

    //Constructor
    PartTime(String name, String surname, String registerNumber, String position, int yearOfStart) {
        super(name, surname, registerNumber, position, yearOfStart);
    }

    //Methods
    @Override
    public void calculateSalary(int week1, int week2, int week3, int week4) {
        checkHourOfWork(week1);
        checkHourOfWork(week2);
        checkHourOfWork(week3);
        checkHourOfWork(week4);
        setSalary(getSeverancePay() + (hourOfWork * incomePerHour));
    }

    private void checkHourOfWork(int week) {
        double salary = getSalary();
        if (week < MIN_WORK_HOURS) {
            salary += 0;
            setSalary(salary);
        }else hourOfWork += Math.min(week, MAX_WORK_HOURS);
    }
}
