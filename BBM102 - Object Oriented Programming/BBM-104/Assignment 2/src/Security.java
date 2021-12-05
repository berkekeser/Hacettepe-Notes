public class Security extends Personnel {

    //Constants
    static final int MAX_WORK_HOURS = 9; // per day
    static final int MIN_WORK_HOURS = 5; // per day;
    static final int WORK_DAY = 6; //per week

    //Fields
    private double hourOfWork = 0;
    private double incomePerHour = 10;
    private double transMoney = 5; // per day
    private double foodMoney = 10; // per day
    private double extraIncome = 0;

    //Constructor
    Security(String name, String surname, String registerNumber, String position, int yearOfStart) {
        super(name, surname, registerNumber, position, yearOfStart);
    }

    //Methods
    @Override
    public void calculateSalary(int week1, int week2, int week3, int week4) {
        checkHourOfWork(week1);
        checkHourOfWork(week2);
        checkHourOfWork(week3);
        checkHourOfWork(week4);
        setSalary(getSeverancePay() + (hourOfWork * incomePerHour) + extraIncome);
    }

    private void checkHourOfWork(int week) {
        if (week < WORK_DAY * MIN_WORK_HOURS) {
            extraIncome += 0;
        }else if(week > WORK_DAY * MAX_WORK_HOURS) {
            hourOfWork += MAX_WORK_HOURS * WORK_DAY;
            extraIncome += ((transMoney + foodMoney) * WORK_DAY);
        }
        else {
            hourOfWork += week;
            extraIncome += ((transMoney + foodMoney) * WORK_DAY);
        }
    }
}
