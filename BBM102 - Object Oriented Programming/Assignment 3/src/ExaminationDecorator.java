public abstract class ExaminationDecorator implements Examination{

    protected Examination tempExamination;
    protected int patientId;

    //Constructors
    public ExaminationDecorator(Examination newExamination) {
        tempExamination = newExamination;
    }

    public int getPatientId() {
        return patientId;
    }

    public void setPatientId(int patientId) {
        this.patientId = patientId;
    }

}
