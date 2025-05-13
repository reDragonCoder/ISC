package Ex1;

public class Ex1 {
    public static void main(String[] args) {
        Counter count = new Counter();

        Thread t1 = new Thread(() ->{
            for (int i = 0; i < 5000; i++) {
                count.inc();
            }
        });

        Thread t2 = new Thread(() ->{
            for (int i = 0; i < 5000; i++) {
                count.inc();
            }
        });

        Thread t3 = new Thread(() ->{
            for (int i = 0; i < 5000; i++) {
                count.inc();
            }
        });

        Thread t4 = new Thread(() ->{
            for (int i = 0; i < 5000; i++) {
                count.inc();
            }
        });
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        try{
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        }catch (InterruptedException e){
            e.printStackTrace();
        }
        System.out.println(count.get());
    }
}

class Counter{
    private int counter = 0;

    public synchronized void inc(){
        counter++;
    }
    public synchronized  int get(){
        return counter;
    }
}
