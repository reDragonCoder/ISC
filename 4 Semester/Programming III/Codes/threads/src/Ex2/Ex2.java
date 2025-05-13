package Ex2;

import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

public class Ex2 {
    // Semaphore representing the number of chairs in the waiting room
    private static final Semaphore WAITING_ROOM = new Semaphore(3);

    // Semaphore to determine whether the barber is available
    private static final Semaphore BARBER = new Semaphore(1);

    static class Customer implements Runnable {
        private final int id;

        Customer(int id) {
            this.id = id;
        }

        @Override
        public void run() {
            try {
                if (WAITING_ROOM.tryAcquire()) {
                    System.out.println("Customer " + id + " is waiting.");
                    BARBER.acquire();
                    WAITING_ROOM.release(); // Leave the waiting room chair
                    getHaircut();
                    BARBER.release(); // Release the barber
                } else {
                    System.out.println("Customer " + id + " leaves (no chairs available).");
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }

        private void getHaircut() throws InterruptedException {
            System.out.println("Customer " + id + " is getting a haircut.");
            Thread.sleep(TimeUnit.SECONDS.toMillis(1));
        }
    }

    public static void main(String[] args) throws InterruptedException {
        for (int i = 1; i <= 20; i++) {
            new Thread(new Customer(i)).start();
            Thread.sleep(TimeUnit.SECONDS.toMillis(1));
        }
    }
}
