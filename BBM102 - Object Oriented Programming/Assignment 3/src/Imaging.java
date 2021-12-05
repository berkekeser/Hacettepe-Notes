public class Imaging extends ExaminationDecorator {

    private int imagingCost = 10;
    public Imaging(Examination newExamination) {
        super(newExamination);
    }
    public double getCost() {
        return tempExamination.getCost() + imagingCost;
    }

    @Override
    public String printOperations(String type) {
        return tempExamination.printOperations(type) + "imaging ";
    }

}
