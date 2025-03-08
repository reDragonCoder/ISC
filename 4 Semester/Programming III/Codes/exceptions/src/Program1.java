public class Program1 {
    public static void main(String[] args) {
        try{
            throw new Exception("Error");
        } catch(Exception e){
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Finally block is being executed");
        }
    }
}
