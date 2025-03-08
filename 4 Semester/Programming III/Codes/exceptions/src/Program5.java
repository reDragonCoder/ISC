public class Program5 {
    public static class CustomException extends Exception {
        public CustomException(String msg) {
            super(msg);
        }
    }

    public static void g() throws CustomException {
        throw new CustomException("CustomException from g() method");
    }

    public static void f(){
        try{
            g();
        }
        catch(CustomException e){
            System.out.println("Captured exception in f(): "+ e.getMessage());
            throw new RuntimeException("New thrown exception from f()");
        }
    }

    public static void main(String[] args) {
        try{
            f();
        } catch (Exception e) {
            System.out.println("Captured exception in main(): "+ e.getMessage());
        }
    }

}
