package Ex4;

import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class LinkedListEx {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();
        Scanner sc = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("MENU:");
            System.out.println("1. Add element to the end");
            System.out.println("2. Iterate through all elements");
            System.out.println("3. Iterate in reverse order");
            System.out.println("4. Insert elements at the first and last positions");
            System.out.println("5. Insert element at the beginning");
            System.out.println("6. Insert element at a specified position");
            System.out.println("7. Get the first and last occurrences of an element");
            System.out.println("8. Remove a specific element");
            System.out.println("9. Remove all elements");
            System.out.println("10. Sort the list");
            System.out.println("11. Check if an item exists");
            System.out.println("12. Display the entire list");
            System.out.println("0. Exit");
            System.out.print("Select an option: ");

            int option = sc.nextInt();
            sc.nextLine();

            switch (option) {
                case 1:
                    System.out.print("Enter the element to add to the end: ");
                    String finalElement = sc.nextLine();
                    list.add(finalElement);
                    System.out.print("Element added to the end\n");
                    break;

                case 2:
                    System.out.println("\nGoing through the list (normal order):");
                    for(String element : list) {
                        System.out.println(element);
                    }
                    System.out.println();
                    break;

                case 3:
                    System.out.println("\nGoing through the list (reverse order):");
                    Iterator<String> iteratorReverse = list.descendingIterator();
                    while(iteratorReverse.hasNext()) {
                        System.out.println(iteratorReverse.next());
                    }
                    System.out.println();
                    break;

                case 4:
                    System.out.print("Enter the element to insert in the first position: ");
                    String firstElement = sc.nextLine();
                    list.addFirst(firstElement);
                    System.out.print("Enter the element to insert in the last position: ");
                    String lastElement = sc.nextLine();
                    list.addLast(lastElement);
                    System.out.println("Elements inserted in the first and last positions");
                    System.out.println();
                    break;

                case 5:
                    System.out.print("Enter the element to insert at the beginning: ");
                    String initialElement = sc.nextLine();
                    list.addFirst(initialElement);
                    System.out.println("Element inserted at the beginning");
                    System.out.println();
                    break;

                case 6:
                    System.out.print("Enter the index at which you want to insert: ");
                    int index = sc.nextInt();
                    sc.nextLine();
                    if (index < 0 || index > list.size()) {
                        System.out.println("Invalid index");
                        System.out.println();
                    } else {
                        System.out.print("Enter the element to insert: ");
                        String elemPos = sc.nextLine();
                        list.add(index, elemPos);
                        System.out.println("Element inserted at position " + index);
                        System.out.println();
                    }
                    break;

                case 7:
                    System.out.print("Enter the element to search for: ");
                    String searchElement = sc.nextLine();
                    int firstOccurrence = list.indexOf(searchElement);
                    int lastOccurrence = list.lastIndexOf(searchElement);
                    if (firstOccurrence == -1) {
                        System.out.println("The element is not found in the list");
                        System.out.println();
                    } else {
                        System.out.println("First occurrence of '" + searchElement + "': index " + firstOccurrence);
                        System.out.println("Last occurrence of '" + searchElement + "': index " + lastOccurrence);
                        System.out.println();
                    }
                    break;

                case 8:
                    System.out.print("Enter the element to remove: ");
                    String elementToRemove = sc.nextLine();
                    boolean removed = list.remove(elementToRemove);
                    if (removed) {
                        System.out.println("Element removed");
                        System.out.println();
                    } else {
                        System.out.println("Element not found");
                        System.out.println();
                    }
                    break;

                case 9:
                    list.clear();
                    System.out.println("All elements have been removed.");
                    System.out.println();
                    break;

                case 10:
                    Collections.sort(list);
                    System.out.println("The list has been sorted (ascending)");
                    System.out.println();
                    break;

                case 11:
                    System.out.print("Enter the element to check: ");
                    String checkElement = sc.nextLine();
                    if (list.contains(checkElement)) {
                        System.out.println("The element EXISTS in the list");
                        System.out.println();
                    } else {
                        System.out.println("The element does NOT exist in the list");
                        System.out.println();
                    }
                    break;

                case 12:
                    System.out.println("Current list contents:");
                    System.out.println(list);
                    System.out.println();
                    break;

                case 0:
                    System.out.println("Goodbye!...");
                    exit = true;
                    break;

                default:
                    System.out.println("Invalid option. Please try again");
                    System.out.println();
            }
        }
        sc.close();
    }
}
