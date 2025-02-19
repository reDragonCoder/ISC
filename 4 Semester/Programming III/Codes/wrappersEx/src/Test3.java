// CESAR ANDRES ZULETA MALANCO 300077

public class Test3{

    public static void main(String[] args)
    {
        // Base = 2
        Integer val1 = Integer.valueOf("1010", 8);
        System.out.println(val1 + " ");

        // Base = 16
        Integer val2 = Integer.valueOf("1011", 16);
        System.out.println(val2 + " ");

        // Base = 2
        Integer val3 = Integer.valueOf("1010", 2);
        System.out.println(val3 + " ");

        // Base = 10
        Integer val4 = Integer.valueOf("1021", 10);
        System.out.println(val4);
    }
}