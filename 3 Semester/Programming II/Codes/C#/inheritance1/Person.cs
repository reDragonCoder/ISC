class Person{
    //attributes    
    private double saving;
    protected string name="";
    protected int age=0;

    //methods
    //constructors
    public Person(){
        Console.WriteLine("---empty Person constructor---");
    }

    public Person(string name, int age, double saving){
        Console.WriteLine("---Person constructor with parameters---");
        this.name=name;
        this.age=age;
        this.saving=saving;
    }

    //get methods
    public int getAge(){
        return this.age;
    }

    public string getName(){
        return this.name;
    }

    //set methods
    public void setAge(int age){
        this.age=age;
    }

    public void setName(string name){
        this.name=name;
    }

    //property
    public double Saving{ 
        get{return saving;}
        set{saving=value;}
    }

    //other methods
    public string personPublicMethod(){
        return "I'm the personMethod declared public";
    }

    protected string personProtectedMethod(){
        return "I'm the personMethod declared protected";
    }

    protected string personPrivateedMethod(){
        return "I'm the personMethod declared private";
    }
}