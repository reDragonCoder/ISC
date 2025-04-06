// Author: reDragonCoder

public class Test2{
    public static void main(String[] args)
    {
        String s1 = "HELLO";
        String s2 = "HELLO";
        String s3 = new String("HELLO");

        System.out.println(s1 == s2); //true because "HELLO" is the same word in s1 & s2, that is, "HELLO"
                                     // is in the pool adn s2 does not create a new word
        System.out.println(s1 == s3);
        System.out.println(s1.equals(s2));
        System.out.println(s1.equals(s3));
    }
}