package Ex4;

public class Buffer{
    private int[] buffer;
    private int capacity;
    private int count=0;
    private int in=0;
    private int out=0;

    public Buffer(int capacity){
        this.capacity = capacity;
        buffer = new int[capacity];
    }

    // Insert data into the buffer
    public synchronized void put(int data) throws InterruptedException {
        // if the buffer is full, the producer must wait
        while(count==capacity){
            System.out.println("Buffer full. Producer waiting...");
            wait(); // wait until space is available
        }

        // insert the data at the "in" position and update the index
        buffer[in] = data;
        if(in==capacity-1){
            in=0;
        }else{
            in++;
        }
        count++;
        // notify all waiting threads that the state of the buffer has changed
        notifyAll();
    }

    // Retrieve data from the buffer
    public synchronized int get() throws InterruptedException {
        // if the buffer is empty, the consumer must wait
        while(count==0){
            System.out.println("Buffer empty. Consumer waiting...");
            wait(); // wait until there is data to consume
        }

        // retrieve the data at the "out" position and update the index
        int data=buffer[out];
        if(out==capacity-1){
            out=0;
        }else{
            out++;
        }
        count--;

        //notify all waiting threads that the state of the buffer has changed
        notifyAll();
        return data;
    }
}