package Ex1;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        CaptureInfo captureInfo = new CaptureInfo();
        List<Person> list = new ArrayList<>();

        System.out.println("How many people do you want to capture? ");
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.println("\nCapturing person #" + (i + 1) + " information: ");
            Person person = captureInfo.capturePerson(sc);
            list.add(person);
        }

        double average = captureInfo.calculateAgeAverage(list);
        System.out.println("\nAverage age: " + average);

        Map<String, Integer> counterGender = captureInfo.countByGender(list);
        System.out.println("\nGender count: ");
        for (Map.Entry<String, Integer> entry : counterGender.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        sc.close();
    }
}
