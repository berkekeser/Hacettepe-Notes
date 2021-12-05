public class DoctorVisit extends ExaminationDecorator {

    private int doctorVisitCost = 15;
    public DoctorVisit(Examination newExamination) {
        super(newExamination);
    }

    public double getCost() {
        return tempExamination.getCost() + doctorVisitCost;
    }

    @Override
    public String printOperations(String type) {
        return tempExamination.printOperations(type) + "doctorvisit ";
    }

}
