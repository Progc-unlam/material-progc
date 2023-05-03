import java.util.concurrent.Semaphore;

public class HilosSemaphore 
{
	static int res=0;
	static Semaphore mtx = new Semaphore(1);
	
	static class Hilo extends Thread 
	{		
		public void run() 
		{
			try
			{
				mtx.acquire();
				res+=1;
				mtx.release();
			}
			catch( Exception e )
			{				
			}
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