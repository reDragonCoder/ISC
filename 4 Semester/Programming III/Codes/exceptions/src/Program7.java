public class Program7 {
    public static void main(String[] args) {
        try {
            int[] array = {1, 2, 3, 4, 5};
            System.out.println(array[6]);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }
    }
}
