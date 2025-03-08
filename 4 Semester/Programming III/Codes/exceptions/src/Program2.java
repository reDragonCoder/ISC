// Custom exception template

public class Program2  extends Exception {
    private final String msg;

    public Program2(String msg) {
        this.msg = msg;
    }

    public void printMessage() {
        System.out.println("Exception message: " + msg);
    }
}

class Main{
    public static void main(String[] args) {
        try{
            throw new Program2("Custom error");
        }
        catch(Program2 e){
            e.printMessage();
        }
    }
}
