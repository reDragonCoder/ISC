package ex3_TreeSet2;

public class ex3_Player implements Comparable{
    private String name;
    private float height;

    public ex3_Player(String name, float height) {
        this.name = name;
        this.height = height;
    }

    public String getName() {
        return name;
    }

    public float getHeight() {
        return height;
    }

    @Override
    public String toString() {
        return "[name=" + name + ", height=" + height + "]";
    }

    // two players are equal if they have the same name
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof ex3_Player player)) return false;
        return this.name.equalsIgnoreCase(player.name);
    }

    // generates the hashCode based on the lowercase name to maintain consistency with equals
    @Override
    public int hashCode(){
        return name == null ? 0 : name.toLowerCase().hashCode();
    }

    // sort alphabetically by name
    @Override
    public int compareTo(Object o) {
        return this.name.compareToIgnoreCase(((ex3_Player)o).getName());
    }
}
