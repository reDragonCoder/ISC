// Author: reDragonCoder

class Test1 {
    public static void main(String[] args)
    {
        String s = "77";

        // Primitive int is returned
        int str = Integer.parseInt(s);
        System.out.print(str);

        // Integer object is returned
        int str1 = Integer.valueOf(s);
        System.out.print(str1);
    }
}