public class ResearchAssistant extends Academician {

    //Constructor
    ResearchAssistant(String name, String surname, String registerNumber, String position, int yearOfStart) {
        super(name, surname, registerNumber, position, yearOfStart);
        this.setSsBenefits((getBaseSalary() * 105) / 100);
    }

    //Methods
    @Override
    public void calculateSalary(int week1, int week2, int week3, int week4) {
        setSalary(getBaseSalary() + getSsBenefits() + getSeverancePay());
    }

}
