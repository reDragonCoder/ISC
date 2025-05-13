package Ex4;

import java.util.Random;

// Class that consumes the produced data
public class Consumer implements Runnable {
    private Buffer buffer;
    private int maxData;
    private Random random = new Random();

    public Consumer(Buffer buffer, int maxData) {
        this.buffer = buffer;
        this.maxData = maxData;
    }

    @Override
    public void run() {
        for (int i = 0; i <= maxData; i++) {
            try{
                // retrieve the next data item from the buffer (blocks if the buffer is empty)
                int data = buffer.get();
                // simulate consumption time with a random sleep between 0 and 2 seconds
                int sleepTime = random.nextInt(2001);
                Thread.sleep(sleepTime);
                System.out.println("Consumer consumed: " + data);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
