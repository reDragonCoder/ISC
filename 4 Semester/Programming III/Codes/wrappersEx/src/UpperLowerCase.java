// Author: reDragonCoder

public class UpperLowerCase {
    public static void main(String[] args) {
        String s = "Hello World";
        StringBuilder sb = new StringBuilder(s.length());
        for( int i = 0; i<s.length(); i++ ) {
            if(Character.isUpperCase(s.charAt(i))){
                sb.append(Character.toLowerCase(s.charAt(i)));
            }else{
                sb.append(Character.toUpperCase(s.charAt(i)));
            }
        }
        System.out.println(sb);
    }
}
