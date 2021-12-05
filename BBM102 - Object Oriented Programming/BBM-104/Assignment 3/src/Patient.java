public class Patient {

    //fields
    private int id;
    private String name;
    private String surname;
    private String address;
    private String phoneNumber;

    // Constructors
    public Patient() {

    }

    public Patient(int id, String name, String surname, String phoneNumber, String address) {
        this.id = id;
        this.name = name;
        this.surname = surname;
        this.phoneNumber = phoneNumber;
        this.address = address;
    }

    // Functions
    @Override
    public String toString() {
            return id + "\t" + name + " " +surname + "\t" +phoneNumber + "\tAddress: " + address +"\n";
    }

    // Getter & Setter
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }

}
