import java.util.concurrent.locks.ReentrantLock;

public class ThreadsLock
{
	static ReentrantLock mtx = new ReentrantLock();
	static int value = 0;
	
	static class MyThread extends Thread
	{
		public void run()
		{
			mtx.lock();
		    value+=1;
			mtx.unlock();
        }	      
	}
	
	public static void main(String[] args) throws InterruptedException 
	{
		MyThread threadA = new MyThread();
		MyThread threadB = new MyThread();
	
		threadA.start();
		threadB.start();			
	
		threadA.join();
		threadB.join();
						
		System.out.println("Valor: " + value);		
	}
}
