/* ------------------------------------------------------------
 *	Author: fenlan
 *	Date: 2017.8.31
 * ------------------------------------------------------------
 *  Output:
 *      启动线程Y...
 *      线程Y:Thread-0 正在运行
 *      线程Y:Thread-1 正在运行
 *      线程Y:Thread-2 正在运行
 *      线程Y:Thread-3 正在运行
 *      线程Y:Thread-4 正在运行
 *      结束线程Y...
 *      线程X已经启动...
 *      Thread-4运行结束...
 *      启动时间:Aug 31, 2017 5:38:24 PM
 * ------------------------------------------------------------
 */



import java.util.Date;

public class ThreadLife {
    public void startY() {
        ThreadY ty = new ThreadY();
        ty.startThreadY();
        // ty 线程开启后，当前线程继续进行，同时当前线程可以控制ty 线程的结束
        try {
            Thread.sleep(1000);
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
        ty.stopThreadY();
    }
    public void startX() {
        Runnable runnX = new ThreadX();
        Thread threadX = new Thread(runnX);
        threadX.start();
    }
    public static void main(String[] args) {
        ThreadLife test = new ThreadLife();
        test.startY();
        test.startX();
    }
}

class ThreadY extends Thread {
    private boolean isRunState = false;
    public void start() {
        this.isRunState = true;
        super.start();
    }
    public void run() {
        int i = 0;
        try {
            while(isRunState) {
                this.setName("Thread-" + i++);
                System.out.println("线程Y:" + this.getName() + " 正在运行");
                Thread.sleep(200);
            }
        } catch(Exception e) {
        }
        System.out.println(this.getName() + "运行结束...");
    }
    public void setRunning(boolean isRunState) {
        this.isRunState = isRunState;
    }
    public void startThreadY() {
        System.out.println("启动线程Y...");
        this.start();
    }
    public void stopThreadY() {
        System.out.println("结束线程Y...");
        this.setRunning(false);
    }
}

class ThreadX implements Runnable {
    private Date runDate;
    public void run() {
        System.out.println("线程X已经启动...");
        this.runDate = new Date();
        System.out.println("启动时间:" + runDate.toLocaleString());
    }
}
