package ex1;

import java.util.LinkedList;

public class Main_ex1 {
    public static void main(String[] args) {
        // Using linked list to preserve the insertion order
        LinkedList<BankUser> arrivalQueue = new LinkedList<>();

        // Add elements
        arrivalQueue.add(new BankUser("Kevin Mier", 24));
        arrivalQueue.add(new BankUser("Erik Lira", 24));
        arrivalQueue.add(new BankUser("Luka Romero", 20));
        arrivalQueue.add(new BankUser("Lorenzo Faravelli", 32));
        arrivalQueue.add(new BankUser("Mateusz Bogusz", 23));

        // Show arrival queue
        System.out.println("--- Arrival bank queue order ---");
        for (BankUser user : arrivalQueue) {
            System.out.println(user);
        }
        System.out.println();

        // Display elements based on age
        System.out.println("--- Attention bank queue order ---");
        while (!arrivalQueue.isEmpty()) {
            BankUser nextUser = null;
            int indexToRemove = -1;
            int minAge = Integer.MAX_VALUE;
            // go through all the array to find the minimum age
            for(int i = 0; i < arrivalQueue.size(); i++) {
                BankUser currentUser = arrivalQueue.get(i);
                if (currentUser.getAge() < minAge) {
                    minAge = currentUser.getAge();
                    nextUser = currentUser;
                    indexToRemove = i;
                }
            }
            // The user assisted is displayed and removed, respecting the FIFO order in case of an age tie
            System.out.println(nextUser);
            arrivalQueue.remove(indexToRemove);
        }
    }
}
