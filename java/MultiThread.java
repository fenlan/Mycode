/* ------------------------------------------------------------
 *	Author: fenlan
 *	Date: 2017.8.31
 * ------------------------------------------------------------
 *  Output:
 *      2554547108585472000
 *      2439304381882368000
 *      程序运行时间1： 273141ns
 *      2554547108585472000
 *      2439304381882368000
 *      Thread-0 72516ns
 *      Thread-1 106297ns
 * ------------------------------------------------------------
 */

public class MultiThread {
    public static long factorial2(int x) {
        if (x < 0) {
            throw new IllegalArgumentException("x must be>=0");
        }
        if (x <= 1) {
            return 1;
        } else
            return x * factorial2(x - 1);
    }

    public static void main(String[] args) {
        simply();
        complex();
    }

    public static void simply() {
        long startTime = System.nanoTime();
        System.out.println(factorial2(19) + factorial2(20));
        System.out.println(factorial2(18) + factorial2(20));
        long endTime = System.nanoTime();
        System.out.println("程序运行时间1： " + (endTime-startTime) + "ns");
    }

    public static void complex() {
        MyThread1 mythread1 = new MyThread1();
        MyThread2 mythread2 = new MyThread2();
        mythread1.start();
        mythread2.start();
    }
}

class MyThread1 extends Thread {
	public void run(){
        long startTime = System.nanoTime();
        System.out.println(MultiThread.factorial2(19) + MultiThread.factorial2(20));
        long endTime = System.nanoTime();
        System.out.println(getName() + " "  + (endTime-startTime) + "ns");
	}
}

class MyThread2 extends Thread {
	public void run(){
        long startTime = System.nanoTime();
        System.out.println(MultiThread.factorial2(18) + MultiThread.factorial2(20));
        long endTime = System.nanoTime();
        System.out.println(getName() + " " + (endTime-startTime) + "ns");
	}
}
