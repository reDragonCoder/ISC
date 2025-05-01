package ex_2;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        LinkedList<Patients> arrivalQueue = new LinkedList<>();
        arrivalQueue.add(new Patients(10, 8, "Melendez"));
        arrivalQueue.add(new Patients(20, 10, "Garcia"));
        arrivalQueue.add(new Patients(23, 4, "Colon"));
        arrivalQueue.add(new Patients(30, 12, "Serrano"));
        arrivalQueue.add(new Patients(44, 1, "Rios"));
        arrivalQueue.add(new Patients(100, 4, "Rovira"));

        PriorityQueue<Patients> waitingQueue = new PriorityQueue<>((p1, p2) -> {
            if (p1.getAge() == p2.getAge()) {
                return p1.getArrivalTime() - p2.getArrivalTime();
            }
            return p1.getAge() - p2.getAge();
        });

        int currentTime = 0;
        int serviceDuration = 15;

        while (!arrivalQueue.isEmpty() || !waitingQueue.isEmpty()) {
            if (waitingQueue.isEmpty() && !arrivalQueue.isEmpty()) {
                currentTime = Math.max(currentTime, arrivalQueue.peek().getArrivalTime());
            }

            while (!arrivalQueue.isEmpty() && arrivalQueue.peek().getArrivalTime() <= currentTime) {
                waitingQueue.add(arrivalQueue.poll());
            }

            if (!waitingQueue.isEmpty()) {
                Patients nextPatient = waitingQueue.poll();
                System.out.println("minute " + currentTime + ": attends to " + nextPatient.getLastName());
                currentTime += serviceDuration;
            }
        }
    }
}
