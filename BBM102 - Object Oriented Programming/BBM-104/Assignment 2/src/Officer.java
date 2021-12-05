public class Officer extends Personnel{

    // Constant
    static final int MAX_WORK_HOURS = 40;

    //Fields
    private double baseSalary = 2600;
    private double ssBenefits = baseSalary * 65 / 100;
    private double overWorkSalary = 0;
    private double overWorkHour = 0;
    private double overWorkIncomePerHours = 20;

    //Constructor
    Officer(String name, String surname, String registerNumber, String position, int yearOfStart) {
        super(name, surname, registerNumber, position, yearOfStart);
    }

    //Methods
    @Override
    public void calculateSalary(int week1, int week2, int week3, int week4) {
        overWorkHour += overWorkCalculate(week1);
        overWorkHour += overWorkCalculate(week2);
        overWorkHour += overWorkCalculate(week3);
        overWorkHour += overWorkCalculate(week4);
        overWorkSalary = overWorkHour * overWorkIncomePerHours;
        setSalary(baseSalary + ssBenefits + overWorkSalary + getSeverancePay());
    }

    private double overWorkCalculate(int week) {
        int overWorkHour = 0;
        if(week - MAX_WORK_HOURS > 0) {
            overWorkHour += Math.min(week - MAX_WORK_HOURS, 10);

        }
        return overWorkHour;
    }

}
