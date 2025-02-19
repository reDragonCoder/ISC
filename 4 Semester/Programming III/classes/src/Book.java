// Exercise 5 - Cesar Andres Zuleta Malanco

import javax.swing.*;

public class Book {
    private String title;
    private String author;
    private int numCopies;
    private int numLentCopies;

    Book(){}

    Book(String title, String author, int numCopies, int numBorrowedCopies) {
        this.title = title;
        this.author = author;
        this.numCopies = numCopies;
        this.numLentCopies = numBorrowedCopies;
    }

    public String getTitle() {
        return title;
    }
    public String getAuthor() {
        return author;
    }
    public int getNumCopies() {
        return numCopies;
    }
    public int getNumBorrowedCopies() {
        return numLentCopies;
    }

    public void setTitle(String title) {
        this.title = title;
    }
    public void setAuthor(String author) {
        this.author = author;
    }
    public void setNumCopies(int numCopies) {
        this.numCopies = numCopies;
    }
    public void setNumLentCopies(int numBorrowedCopies) {
        this.numLentCopies = numBorrowedCopies;
    }

    public boolean bookLoan(){
        if(numCopies>0 && numLentCopies<numCopies){
            numLentCopies++;
            return true;
        }
        return false;
    }

    public boolean bookReturn(){
        if(numLentCopies>=1){
            numLentCopies--;
            return true;
        }
        return false;
    }

    public void showBookData() {
        int availableCopies = numCopies - numLentCopies;
        JOptionPane.showMessageDialog(null, "Title: " + title + "\n"
                + "Author: " + author + "\n"
                + "Total Copies: " + numCopies + "\n"
                + "Available Copies: " + availableCopies + "\n"
                + "Lent Copies: " + numLentCopies + "\n");
    }

}

class FifthMain{
    public static void main(String[] args) {
        int numBooks = Integer.parseInt(JOptionPane.showInputDialog(null,
                "Enter number of books you want to add"));
        Book [] books = new Book[numBooks];

        String title, author;
        int numCopies, numLentCopies;

        for (int i = 0; i < numBooks; i++) {
            title = JOptionPane.showInputDialog(null, "Enter the book title: ");
            author = JOptionPane.showInputDialog(null, "Enter the book author: ");
            numCopies = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Enter the number of copies: "));
            numLentCopies = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Enter the number of lent copies: "));

            books[i] =  new Book(title, author, numCopies, numLentCopies);
        }

        int choice = 0;
        while(choice<4){
            JOptionPane.showMessageDialog(null, """
                    What would you like to do?
                    1. Book loan
                    2. Book return
                    3. Show inventory
                    4. Exit
                    """);
            try{
                choice = Integer.parseInt(JOptionPane.showInputDialog(null, "Enter choice: "));
            }catch(NumberFormatException e){
                JOptionPane.showMessageDialog(null, "Please enter a valid choice");
            }

            String auxTitle;
            switch (choice){
                case 1:
                    auxTitle = JOptionPane.showInputDialog(null, "Enter the book title you want to borrow: ");
                    boolean bookFound = false;
                    for (Book book : books) {
                        if (book.getTitle().equalsIgnoreCase(auxTitle)) {
                            bookFound = true;
                            if (book.bookLoan()) {
                                JOptionPane.showMessageDialog(null, "You've successfully borrowed \"" + book.getTitle() + "\".");
                            } else {
                                JOptionPane.showMessageDialog(null, "Sorry, all copies of \"" + book.getTitle() + "\" are currently lent out.");
                            }
                            break;
                        }
                    }
                    if (!bookFound) {
                        JOptionPane.showMessageDialog(null, "The book \"" + auxTitle + "\" is not available in the inventory.");
                    }
                    break;

                case 2:
                    auxTitle = JOptionPane.showInputDialog(null, "Enter the book title you want to return: ");
                    bookFound = false;
                    for (Book book : books) {
                        if (book.getTitle().equalsIgnoreCase(auxTitle)) {
                            bookFound = true;
                            if (book.bookReturn()) {
                                JOptionPane.showMessageDialog(null, "Thank you for returning \"" + book.getTitle() + "\".");
                            } else {
                                JOptionPane.showMessageDialog(null, "Error: No copies of \"" + book.getTitle() + "\" are currently lent out.");
                            }
                            break;
                        }
                    }
                    if (!bookFound) {
                        JOptionPane.showMessageDialog(null, "The book \"" + auxTitle + "\" does not belong to our inventory.");
                    }
                    break;


                case 3:
                    for (Book book : books) {
                        book.showBookData();
                    }
                    break;



                case 4:
                    JOptionPane.showMessageDialog(null, "Exiting the library system. Have a great day!");
                    System.exit(0);
                    break;
            }
        }
    }
}
