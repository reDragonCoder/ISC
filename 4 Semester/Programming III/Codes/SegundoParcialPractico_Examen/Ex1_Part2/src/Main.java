import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        for (String arch : args) {
            FileThread thread = new FileThread(arch);
            thread.start();
            thread.join();
        }
        System.out.println("Total: " + FileThread.total);

    }
}