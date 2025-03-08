import java.io.*;
public class Program13 {
    static int total = 0;

    public static void content (String file) throws FileNotFoundException, IOException {
        int num = 0;
        String chain;

        FileReader f = new FileReader(file);
        BufferedReader b = new BufferedReader(f);
        while((chain = b.readLine())!=null) {
            num ++;
            System.out.println(chain);
        }
        System.out.println("File has: " + num);
        total += num;
        b.close();
    }
    public static void main(String[] args) throws IOException {
        for (String arch : args) {
            try {
                content(arch);
            } catch (FileNotFoundException e) {
                System.out.println("File not found");
            } catch (IOException e) {
                System.out.println("An input/output error occurred");
            }
        }
    }
}