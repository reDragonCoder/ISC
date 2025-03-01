package Ex4;

public class Book extends Volume{
    public String author, publisher;
    public Book(String title, String isbn, int nroCopies, String author, String publisher) {
        super(title, isbn, nroCopies);
        this.author = author;
        this.publisher = publisher;
    }
    @Override
    public void show(){
        System.out.println("Title: " + getTitle());
        System.out.println("ISBN: " + getIsbn());
        System.out.println("Copies: " + getNroCopies());
        System.out.println("Author: " + author);
        System.out.println("Publisher: " + publisher +"\n");
    }
}
