public class Program3 extends Exception {
    private final String msg;

    public Program3(String msg){
        super(msg);
        this.msg = msg;
    }

    public void printMessage(){
        System.out.println("Exception message: " + msg);
    }
}

class ExceptionTest{
    public void throwException() throws Program3{
        throw new Program3("Exception message from throwing exception method");
    }

    public static void main(String[] args) {
        ExceptionTest e = new ExceptionTest();
        try{
            e.throwException();
        }
        catch (Program3 e1){
            e1.printMessage();
        }
    }
}
