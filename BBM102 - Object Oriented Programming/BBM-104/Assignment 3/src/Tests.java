public class Tests extends ExaminationDecorator {

    private int testCost = 7;

    public Tests(Examination newExamination) {
        super(newExamination);
    }

    public double getCost() {
        return tempExamination.getCost() + testCost;
    }

    @Override
    public String printOperations(String type) {
        return tempExamination.printOperations(type) + "tests ";
    }

}
