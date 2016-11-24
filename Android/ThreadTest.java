
class ThreadTest {
	public static void main (String[] args){
		MyThread thread1 = new MyThread("thread1");
		MyThread thread2 = new MyThread("thread2");
		thread1.start();
		thread2.start();
		System.out.println("The main runnnig is stopped");
	}
}

class MyThread extends Thread {
	public MyThread(String str){
		super(str);
	}
	public void run(){
		for (int i=0;i<3;i++){
			System.out.println(getName() + "is running");
			try {
				sleep(100);
			} catch (InterruptedException e) {}
		}
		System.out.println(getName() + "stopped");
	}
}
