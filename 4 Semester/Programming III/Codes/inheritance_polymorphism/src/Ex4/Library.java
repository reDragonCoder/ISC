package Ex4;

public class Library extends Volume{
    private Volume arr[];
    private int count, size=3;
    public Library() {
        arr = new Volume [size];
    }
    @Override
    public void show() {
        for (int i = 0; i < count; i++) {
            arr[i].show();
        }
    }

    public boolean add(Volume v) {
        if (count == arr.length) {
            return false;
        } else {
            arr[count] = v;
            count++;
        }
        return true;
    }
}
