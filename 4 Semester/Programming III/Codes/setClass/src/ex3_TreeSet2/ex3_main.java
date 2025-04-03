package ex3_TreeSet2;
import java.util.*;

public class ex3_main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        NavigableSet<ex3_Player> players_set = new TreeSet<>();
        int choice;

        do {
            System.out.println();
            System.out.println("---- Options Menu ----");
            System.out.println("1. Enter player");
            System.out.println("2. List players");
            System.out.println("3. Remove player");
            System.out.println("4. Delete all");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            if(choice == 5) {
                System.out.println();
                System.out.println("Goodbye user!");
            }

            switch (choice) {
                case 1:
                    System.out.println();
                    System.out.print("OPTION 1 - ENTER PLAYER");
                    System.out.println();
                    sc.nextLine();
                    System.out.print("Enter player name: ");
                    String playerName = sc.nextLine();
                    System.out.print("Enter player height (in meters): ");
                    float playerHeight = sc.nextFloat();
                    sc.nextLine();
                    boolean exists = false;
                    for (ex3_Player player : players_set) {
                        if(player.getName().equalsIgnoreCase(playerName)) {
                            exists = true;
                            break;
                        }
                    }
                    if(!exists) {
                        ex3_Player player = new ex3_Player(playerName, playerHeight);
                        players_set.add(player);
                    }else{
                        System.out.println("Player already exists!");
                    }
                    break;

                case 2:
                    System.out.println();
                    System.out.println("OPTION 2 - LIST PLAYERS");
                    if(players_set.isEmpty()){
                        System.out.println("The set is empty");
                    }else {
                        for (ex3_Player ex3Player : players_set) {
                            System.out.println(ex3Player);
                        }
                    }
                    break;

                case 3:
                    System.out.println();
                    System.out.println("OPTION 3 - REMOVE PLAYER");
                    System.out.print("Enter the player name to remove: ");
                    sc.nextLine();
                    String delete_name = sc.nextLine();
                    ex3_Player playerToDelete = new ex3_Player(delete_name, 0);
                    boolean removed = players_set.remove(playerToDelete);
                    if(removed){
                        System.out.println("The player " + delete_name + " was removed successfully");
                    }else{
                        System.out.println("The player " + delete_name + " does not exist");
                    }
                    break;

                case 4:
                    System.out.println();
                    System.out.println("OPTION 4 - DELETE ALL");
                    players_set.clear();
                    System.out.println("Players set cleared");
                    break;
            }
        }
        while(choice != 5);
        sc.close();
    }
}

