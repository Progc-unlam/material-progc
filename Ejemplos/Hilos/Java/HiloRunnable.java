public class HiloRunnable implements Runnable
{
	public void run()
	{
		System.out.println( Thread.currentThread().getName() );
	}

	public static void main(String[] args) throws InterruptedException 
	{
		Thread HiloA = new Thread( new HiloRunnable(), "Hilo A" );
		Thread HiloB = new Thread( new HiloRunnable(), "Hilo B" );

		HiloA.start();
		HiloB.start();			

		HiloA.join();
		HiloB.join();
					
		System.out.println( "Fin" );
	}
}	

