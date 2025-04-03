package ex5_HashSet2;

public class ex5_Employee implements Comparable {
    private String name;
    private double salary;

    public ex5_Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }
    public double getSalary() {
        return salary;
    }

    @Override
    public String toString() {
        return "[Name: " + name + ", Salary: $" + salary + "]";
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj) return true;
        if (!(obj instanceof ex5_Employee ex5_Employee)) return false;
        return this.name.equalsIgnoreCase(ex5_Employee.getName());
    }

    @Override
    public int hashCode() {
        return name == null ? 0 : name.toLowerCase().hashCode();
    }

    @Override
    public int compareTo(Object o) {
        return this.name.compareToIgnoreCase(((ex5_Employee)o).getName());
    }
}
