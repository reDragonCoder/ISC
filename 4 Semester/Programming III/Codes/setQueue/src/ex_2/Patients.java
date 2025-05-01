package ex_2;

public class Patients {
    private int arrivalTime;
    private int age;
    private String lastName;

    public Patients(int arrivalTime, int age, String lastName) {
        this.arrivalTime = arrivalTime;
        this.age = age;
        this.lastName = lastName;
    }

    public int getArrivalTime() {
        return arrivalTime;
    }

    public int getAge() {
        return age;
    }

    public String getLastName() {
        return lastName;
    }

    @Override
    public String toString() {
        return arrivalTime + " " + age + " " + lastName;
    }
}
