package Ex4;

public class Ex4 {
    public static void main(String[] args) {
        Buffer buffer = new Buffer(4);
        Thread producer = new Thread(new Producer(buffer, 30));
        Thread consumer = new Thread(new Consumer(buffer, 30));

        producer.start();
        consumer.start();

        // wait for both threads to finish execution
        try{
            producer.join();
            consumer.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
