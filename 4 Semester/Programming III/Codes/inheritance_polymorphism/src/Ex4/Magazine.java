package Ex4;

public class Magazine extends Volume{
    public int publicationYear, number;
    public Magazine(String title, String isbn, int nroCopies, int publicationYear, int number) {
        super(title, isbn, nroCopies);
        this.publicationYear = publicationYear;
        this.number = number;
    }
    @Override
    public void show(){
        System.out.println("Title: " + getTitle());
        System.out.println("ISBN: " + getIsbn());
        System.out.println("Copies: " + getNroCopies());
        System.out.println("Publication Year: " + publicationYear);
        System.out.println("Number of copies: " + getNroCopies() +"\n");
    }
}
