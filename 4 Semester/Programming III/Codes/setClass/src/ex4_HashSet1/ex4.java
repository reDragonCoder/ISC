package ex4_HashSet1;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ex4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Set<String> words_set = new HashSet<>();
        int choice;

        do {
            System.out.println();
            System.out.println("---- Options Menu ----");
            System.out.println("1. Enter word");
            System.out.println("2. List words");
            System.out.println("3. Delete word");
            System.out.println("4. Delete all");
            System.out.println("5. Show size");
            System.out.println("6. Search");
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
                    System.out.println("OPTION 1 - ENTER WORD");
                    System.out.print("Enter your word: ");
                    sc.nextLine();
                    String word = sc.next();
                    words_set.add(word);
                    System.out.println("Word added successfully");
                    break;

                case 2:
                    System.out.println();
                    System.out.println("OPTION 2 - LIST WORDS");
                    if(words_set.isEmpty()){
                        System.out.println("No words found in the set");
                    }else {
                        for (String word2 : words_set) {
                            System.out.println(word2);
                        }
                    }
                    break;

                case 3:
                    System.out.println();
                    System.out.println("OPTION 3 - DELETE WORD");
                    System.out.print("Enter the word to delete: ");
                    sc.nextLine();
                    String delete_word = sc.next();
                    if(words_set.contains(delete_word)){
                        words_set.remove(delete_word);
                        System.out.println("Word deleted successfully");
                    }else{
                        System.out.println("Word not found");
                    }
                    break;

                case 4:
                    System.out.println();
                    System.out.println("OPTION 4 - DELETE ALL");
                    words_set.clear();
                    System.out.println("All words deleted successfully");
                    break;

                case 5:
                    System.out.println();
                    System.out.println("OPTION 5 - SHOW SIZE");
                    System.out.println("The size of the set is: " + words_set.size());
                    break;

                case 6:
                    System.out.println();
                    System.out.println("OPTION 6 - SEARCH");
                    System.out.print("Enter the word to search: ");
                    sc.nextLine();
                    String search_word = sc.next();
                    if(words_set.contains(search_word)){
                        System.out.println("Word " + search_word + " found");
                    }else{
                        System.out.println("Word not found");
                    }
                    break;
            }
        }
        while(choice != 7);
        sc.close();
    }
}
