package ex5_HashSet2;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ex5_main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Set<ex5_Employee> employee_set = new HashSet<>();
        int choice;

        do {
            System.out.println();
            System.out.println("---- Options Menu ----");
            System.out.println("1. Enter employee");
            System.out.println("2. List employees");
            System.out.println("3. Delete employee");
            System.out.println("4. Delete all");
            System.out.println("5. Show number of employees");
            System.out.println("6. Search employee");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            if(choice == 7) {
                System.out.println();
                System.out.println("Goodbye user!");
            }

            switch (choice) {
                case 1:
                    System.out.println();
                    System.out.println("OPTION 1 - ENTER EMPLOYEE");
                    sc.nextLine();
                    System.out.print("Enter employee name: ");
                    String employeeName = sc.nextLine();
                    System.out.print("Enter employee salary: ");
                    double salary = sc.nextDouble();
                    sc.nextLine();
                    boolean exists = false;
                    for (ex5_Employee employee : employee_set) {
                        if (employee.getName().equalsIgnoreCase(employeeName)) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        ex5_Employee newEmployee = new ex5_Employee(employeeName, salary);
                        employee_set.add(newEmployee);
                    }else{
                        System.out.println("Employee already exists!");
                    }
                    break;

                case 2:
                    System.out.println();
                    System.out.println("OPTION 2 - LIST EMPLOYEES");
                    if(employee_set.isEmpty()){
                        System.out.println("The set is empty!");
                    }else{
                        for(ex5_Employee employee : employee_set){
                            System.out.println(employee.toString());
                        }
                    }
                    break;

                case 3:
                    System.out.println();
                    System.out.println("OPTION 3 - DELETE EMPLOYEE");
                    System.out.print("Enter the employee name to delete: ");
                    sc.nextLine();
                    String delete_name = sc.nextLine();
                    ex5_Employee employeeToDelete = new ex5_Employee(delete_name, 0.0);
                    boolean removed = employee_set.remove(employeeToDelete);
                    if(removed){
                        System.out.println("Employee " + delete_name + " was deleted successfully!");
                    }else{
                        System.out.println("Employee " + delete_name + " does not exists!");
                    }
                    break;

                case 4:
                    System.out.println();
                    System.out.println("OPTION 4 - DELETE ALL");
                    employee_set.clear();
                    System.out.println("Employee set cleared!");
                    break;

                case 5:
                    System.out.println();
                    System.out.println("OPTION 5 - SHOW NUMBER OF EMPLOYEES");
                    System.out.println("The number of employees is: " + employee_set.size());
                    break;

                case 6:
                    System.out.println();
                    System.out.println("OPTION 6 - SEARCH EMPLOYEE");
                    System.out.print("Enter the employee to search: ");
                    sc.nextLine();
                    String search_employee = sc.nextLine();
                    ex5_Employee employeeToSearch = new ex5_Employee(search_employee, 0.0);
                    if(employee_set.contains(employeeToSearch)){
                        System.out.println("Employee " + search_employee + " found!");
                    }else{
                        System.out.println("Employee not found!");
                    }
                    break;
            }
        }
        while(choice != 7);
        sc.close();
    }
}
