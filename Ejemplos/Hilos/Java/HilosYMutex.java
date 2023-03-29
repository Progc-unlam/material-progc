import java.util.concurrent.Semaphore;

public class HilosYMutex 
{
	static Semaphore mtx = new Semaphore(1);

	static class Hilo extends Thread 
	{		
		public Hilo( String nombre )
		{
			super( nombre );			
		}
	
		public void run() 
		{
			try
			{
				mtx.acquire();
				System.out.println( this.getName() );
				mtx.release();
			}
			catch( Exception e ){}
		}
	}
	
	public static void main(String[] args) throws InterruptedException 
	{		
		Hilo HiloA = new Hilo("Hilo A");
		Hilo HiloB = new Hilo("Hilo B");
	
		HiloA.start();
		HiloB.start();			
	
		HiloA.join();
		HiloB.join();
						
		System.out.println( "Fin" );
	}
}