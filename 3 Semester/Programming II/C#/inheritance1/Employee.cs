class Employee:Person{
    //attributes
    protected int id;

    protected double salary;

    //methods
    //constructor
    public Employee(int id, double salary){
        Console.WriteLine("Employee constructor with parameters");
        this.id=id;
        this.salary=salary;
    }

    //get methods
    public int getId(){
        return this.id;
    }

    public double getSalary(){
        return this.salary;
    }

    //set methods
    public void setId(int id){
        this.id=id;
    }

    public void setSalary(int salary){
        this.salary=salary;
    }

    //other methods
    public string employeePublicMethod(){
        string chain="I'm the public employeeMethod in Employee, ";
        chain+=" calling a protected method in my base Person class, ";
        chain+=personProtectedMethod();
        return chain;
    }

    protected string employeeProtectedMethod(){
        return "I'm the employeeMethod declared protected";
    }

    private string employeePrivateMethod(){
        return "I'm the employeeMethod declared private";
    }

}