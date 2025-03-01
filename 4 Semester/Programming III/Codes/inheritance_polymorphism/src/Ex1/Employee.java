package Ex1;

public class Employee {
    private String name;

    public Employee() {}

    public Employee(String name) {
        this.name = name;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return this.name;
    }

    public String toString(){
        return "Employee "+ this.name +" ";
    }
}
