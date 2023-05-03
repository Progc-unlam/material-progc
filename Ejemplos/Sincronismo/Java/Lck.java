import java.util.concurrent.locks.ReentrantLock;

public class Lck
{
	static ReentrantLock mtx = new ReentrantLock();
	static int res=0;
	
	static class Hilo extends Thread
	{
		public void run()
		{
			mtx.lock();
		    res+=1;
			mtx.unlock();
        }	      
	}
	
	public static void main(String[] args) throws InterruptedException 
	{
		Hilo HiloA = new Hilo();
		Hilo HiloB = new Hilo();
	
		HiloA.start();
		HiloB.start();			
	
		HiloA.join();
		HiloB.join();
						
		System.out.println( "res: " + res );		
	}
}

