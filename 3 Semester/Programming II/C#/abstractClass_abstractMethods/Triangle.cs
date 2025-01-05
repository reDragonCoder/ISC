class Triangle:Figure{
    private double triangleBase;
    private double height;

    //Constructor to initialize the base and height of the triangle
    public Triangle(double triangleBase, double height, string type):base(type){
        this.triangleBase=triangleBase;
        this.height=height;
    }

    //Abstract method implementation
    public override double CalculateArea(){
        return (triangleBase*height)/2;
    }
    
}