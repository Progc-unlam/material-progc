public class HiloDemoniaco 
{
	public static class Hilo extends Thread 
	{
		@Override
		public void run() 
		{
			try
			{
				sleep(1000);
			}
			catch (InterruptedException e)
			{				
			}
		}
	}
	
	public static void main(String[] args) throws InterruptedException 
	{
		Hilo HiloA = new Hilo();
		HiloA.setDaemon(true);		
		HiloA.start();		
		System.out.println( "Fin" );
	}
}	






