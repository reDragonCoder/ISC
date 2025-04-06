// Author: reDragonCoder

public class JavaInteger {
    public static void main(String[] args) {
        Integer a = 150;
        Integer b = 150;
        System.out.println(a == b); //false because is a big number that Integer object cannot read
        Integer a1 = 2;
        Integer b1 = 2;
        System.out.println(a1 == b1); //true
    }
}