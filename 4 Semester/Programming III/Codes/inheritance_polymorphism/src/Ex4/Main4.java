package Ex4;

public class Main4 {
    public static void main(String[] args) {
        Volume aura = new Book("Aura", "266529456", 1, "Carlos Fuentes", "Alfarabia");
        Volume noteBook7 = new Magazine("Conspiracy Theories", "566589151", 2, 2025, 7);
        Volume metamorphosis = new Book("The Metamorphosis", "465125145", 2,"Franz Kafka", "United Mexicans");
        Library library = new Library();
        library.add(aura);
        library.add(noteBook7);
        library.add(metamorphosis);
        library.show();
        Volume vogue = new Magazine("Vogue", "132525641", 7, 2025, 4);
        if(!library.add(vogue)) {
            System.out.println("Error: The volume " + vogue.getTitle() + " could not be added to the library.");
        }


    }
}
