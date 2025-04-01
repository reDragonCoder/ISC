package Ex2;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Student> students = new ArrayList<>();

        System.out.println("Enter the number of students to capture ");
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.println("\nCapturing student #" + (i + 1) + " information: ");
            System.out.println("Name ");
            String name = sc.nextLine();
            System.out.println("Grade ");
            int grade = sc.nextInt();
            sc.nextLine();
            students.add(new Student(name, grade));
        }

        boolean flag = true;

        while (flag) {
            System.out.println("Options menu:");
            System.out.println("1. Sort students alphabetically");
            System.out.println("2. Sort students by grade");
            System.out.println("3. Search for a student by name");
            System.out.println("4. Delete a student by name");
            System.out.println("5. Display the list of students");
            System.out.println("6. Exit");
            System.out.print("Select an option: ");
            int option = sc.nextInt();
            sc.nextLine();

            switch (option) {
                case 1:
                    students.sort(Comparator.comparing(Student::getName));
                    System.out.println("\nAlphabetically sorted list:");
                    for (Student student : students) {
                        System.out.println(student);
                    }
                    System.out.println();
                    break;

                case 2: //cambiar a mayor a menor
                    students.sort(Comparator.comparing(Student::getGrade).reversed());
                    System.out.println("\nList sorted by grade:");
                    for (Student student : students) {
                        System.out.println(student);
                    }
                    System.out.println();
                    break;

                case 3:
                    System.out.println("\nEnter the student name to search: ");
                    String searchName = sc.nextLine();
                    boolean find = false;
                    for (Student student : students) {
                        if (student.getName().equalsIgnoreCase(searchName)) {
                            System.out.println("\nStudent found: " + student);
                            System.out.println();
                            find = true;
                        }
                    }
                    if (!find) {
                        System.out.println("\nStudent not found");
                    }
                    break;

                case 4:
                    System.out.println("\nEnter the student name to delete: ");
                    String deleteName = sc.nextLine();
                    Student studentToRemove = null;
                    for (Student student : students) {
                        if(student.getName().equalsIgnoreCase(deleteName)){
                            studentToRemove = student;
                            break;
                        }
                    }
                    if (studentToRemove != null) {
                        students.remove(studentToRemove);
                        System.out.println("\nStudent deleted successfully!");
                        System.out.println();
                    }else{
                        System.out.println("\nStudent not found");
                    }
                    break;

                case 5:
                    System.out.println("\nStudent list:");
                    for (Student student : students) {
                        System.out.println(student);
                    }
                    System.out.println();
                    break;

                case 6:
                    System.out.println("\nGoodbye!...");
                    flag = false;
                    break;

                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }

        sc.close();
    }
}
