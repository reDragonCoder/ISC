package Ex4;

import java.util.Random;

// Class that produces numbers from 1 to maxData (30)
public class Producer implements Runnable {
    private Buffer buffer;
    private int maxData;
    private Random random = new Random();

    public Producer(Buffer buffer, int maxData){
        this.buffer = buffer;
        this.maxData = maxData;
    }

    @Override
    public void run() {
        for(int i = 0; i <= maxData; i++){
            try {
                //simulate production time with a random sleep between 0 and 2 seconds
                int sleepTime = random.nextInt(2001);
                Thread.sleep(sleepTime);
                System.out.println("Producer produced: " + i);
                // insert the produced data into the buffer
                buffer.put(i);
            } catch (InterruptedException e){
                e.printStackTrace();
            }
        }
    }
}
