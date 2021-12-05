public class Outpatient implements Examination{

    private int outpatientCost = 15;
    private int patientId;

    @Override
    public double getCost() {
        return outpatientCost;
    }


    @Override
    public String printOperations(String type) {
        if(type.equals("admission")) {
            return "Outpatient\t";
        }else {
            return "Outpatient ";
        }
    }

    public int getPatientId() {
        return patientId;
    };
    public void setPatientId(int patientId) {
        this.patientId = patientId;
    }

}
