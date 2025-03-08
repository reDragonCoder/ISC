import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Program14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line;
        ArrayList<String> output = new ArrayList<>();

        // Ask the user for the word to search
        System.out.print("Enter the word to search for: ");
        String word = sc.nextLine();

        // Ask the user for the files to search
        System.out.println("Enter file names (one per line, type 'done' to stop):");

        while (true) {
            String input = sc.nextLine();

            // Stop if user types 'done'
            if (input.equalsIgnoreCase("done")) {
                break;
            }

            try (BufferedReader file = new BufferedReader(new FileReader(input))) {
                while ((line = file.readLine()) != null) {
                    if (line.contains(word)) {
                        output.add(input + "\n" + line); // Store file name and line
                    }
                }
            } catch (IOException e) {
                System.out.println("File " + input + " could not be opened.");
            }
        }

        // Output all matches
        if (output.isEmpty()) {
            System.out.println("No matches found.");
        } else {
            for (String str : output) {
                System.out.println(str);
            }
        }

        sc.close();
    }
}