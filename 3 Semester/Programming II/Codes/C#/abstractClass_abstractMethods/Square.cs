class Square:Figure{
    private double side;

    //Constructor for initializing the square side
    public Square(double side, string type):base(type){
        this.side=side;
    }

    //Abstract method implementation
    public override double CalculateArea(){
        return side*side;
    }
}