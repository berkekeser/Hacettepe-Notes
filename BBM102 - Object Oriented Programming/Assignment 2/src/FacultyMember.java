public class FacultyMember extends Academician {

    //Constants
    static final int MAX_COURSE_HOURS = 8;

    //Fields
    private double courseIncomeFeePerHours = 20;
    private double courseHours = 0;

    //Constructor
    FacultyMember(String name, String surname, String registerNumber, String position, int yearOfStart) {
        super(name, surname, registerNumber, position, yearOfStart);
        this.setSsBenefits((getBaseSalary() * 135) / 100);
    }

    //Methods
    @Override
    public void calculateSalary(int week1, int week2, int week3, int week4) {
        calculateCourseFee(week1);
        calculateCourseFee(week2);
        calculateCourseFee(week3);
        calculateCourseFee(week4);
        setSalary(getBaseSalary() + getSsBenefits() + getSeverancePay() + (courseHours * courseIncomeFeePerHours));
    }

    private void calculateCourseFee(int week) {
        if(week - MAX_WORK_HOURS > 0) {
            courseHours += Math.min(week - MAX_WORK_HOURS, MAX_COURSE_HOURS);
        }
    }
}
