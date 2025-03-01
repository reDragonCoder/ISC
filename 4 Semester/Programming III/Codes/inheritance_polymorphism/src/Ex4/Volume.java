package Ex4;

public abstract class Volume {
    private String title, isbn;
    private int nroCopies;
    public Volume(){}
    public Volume(String title, String isbn, int nroCopies) {
        this.title = title;
        this.isbn = isbn;
        this.nroCopies = nroCopies;
    }
    public Volume(Volume other){
        this.title = other.title;
        this.isbn = other.isbn;
        this.nroCopies = other.nroCopies;
    }
    public String getTitle() {
        return title;
    }
    public String getIsbn() {
        return isbn;
    }
    public int getNroCopies() {
        return nroCopies;
    }
    public abstract void show();
    public void setData(String title, String isbn, int nroCopies) {
        this.title = title;
        this.isbn = isbn;
        this.nroCopies = nroCopies;
    }
}
