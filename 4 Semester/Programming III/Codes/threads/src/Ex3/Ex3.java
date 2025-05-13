package Ex3;

import java.util.*;

public class Ex3  extends Thread{
    int lo, hi;
    int []arr;
    int max;
    public Ex3(int lo, int hi, int[] arr) {
        this.arr = arr;
        this.lo = lo;
        this.hi = hi;
        this.max = Integer.MIN_VALUE;
    }

    public void run() {
        for(int i = lo; i <= hi; i++) {
            if(arr[i] > max) {
                max = arr[i];
            }
        }
    }

    public static void main(String[] args) {
        int size = 100;
        int[] arr = new int[size];
        int numThreads = 10;
        Ex3[] threads = new Ex3[numThreads];
        int blockSize = size/numThreads;

        Random rand = new Random();

        for (int i = 0; i < size; i++) {
            arr[i] =  rand.nextInt(100);
        }

        for(int i = 0 ; i < numThreads; i++) {
            int lo = i*blockSize;
            int hi = (i == numThreads-1)?size:(i+1)*blockSize;
            System.out.println("Thread " + i + ": ");
            for(int j = lo; j < hi; j++) {
                System.out.print(arr[j] + " ");
            }
            System.out.println();
            threads[i] = new Ex3(i, size-1, arr);
            threads[i].start();
        }

        int max = Integer.MIN_VALUE;
        for(int i = 0 ; i < numThreads; i++) {
            try{
                threads[i].join();
                if(threads[i].max > max) {
                    max = threads[i].max;
                }
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        System.out.println("Max element: " + max);
    }
}
