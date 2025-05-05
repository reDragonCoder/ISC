import java.io.*;

public class FileThread extends Thread {
    String file;
    public static int total = 0;

    public FileThread(String file) {
        this.file = file;
    }

    @Override
    public void run() {
        int num = 0;
        String chain;

        FileReader f = null;
        try {
            f = new FileReader(file);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        BufferedReader b = new BufferedReader(f);
        while(true) {
            try {
                if (!((chain = b.readLine())!=null)) break;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            num ++;
        }
        System.out.println(file + ": " + num + " líneas");
        total += num;
        try {
            b.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}