package Ex1;

public class Main1 {
    public static void main(String[] args) {
        Employee[] array = new Employee[5];
        array[0] = new Employee("Rafa");
        array[1] = new Executive("Mario");
        array[2] = new Operator("Alfonso");
        array[3] = new Official("Luis");
        array[4] = new Technician("Pablo");

        for (Employee i: array) {
            System.out.println(i);
        }
    }
}
