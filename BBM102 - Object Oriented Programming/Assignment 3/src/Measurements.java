public class Measurements extends ExaminationDecorator{

    private int measurementCost = 5;
    public Measurements(Examination newExamination) {
        super(newExamination);
    }

    public double getCost() {
        return tempExamination.getCost() + measurementCost;
    }

    @Override
    public String printOperations(String type) {
        return tempExamination.printOperations(type) + "measurements ";
    }
}
