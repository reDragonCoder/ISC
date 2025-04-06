// Author: reDragonCoder

import java.util.Scanner;

public class NumberToString {
    public static void main(String[] args) {
        Scanner myObj=new Scanner(System.in);
        System.out.print("Enter the number: ");
        int number=myObj.nextInt();
        String num=Integer.toString(number);
        System.out.println("The number is "+num);
    }
}
