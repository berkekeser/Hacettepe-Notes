public class Inpatient implements Examination{

    private int inpatientCost = 10;
    private int patientId;
    @Override
    public double getCost() {
        return inpatientCost;
    }

    @Override
    public String printOperations(String type) {
        if(type.equals("admission")) {
            return "Inpatient\t";
        }else {
            return "Inpatient ";
        }
    }

    public int getPatientId() {
        return patientId;
    }

    public void setPatientId(int patientId) {
        this.patientId = patientId;
    }

}
