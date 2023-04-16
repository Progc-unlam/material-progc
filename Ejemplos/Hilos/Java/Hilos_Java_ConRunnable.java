public class Hilos_Java_ConRunnable
{
	public static class Hilo implements Runnable
	{
		private int id;
		
		public Hilo( int i )
		{
			id = i;
		}
		
		@Override
		public void run()
		{
			System.out.println( "Mi ID:  " + id );
			System.out.println( "TID:    " + Thread.currentThread().getId() );
			System.out.println(	"Nombre: " + Thread.currentThread().getName() );
		}
	}
	
	public static void main(String[] args) throws InterruptedException 
	{
		Thread HiloA = new Thread( new Hilo( 1 ), "Hilo A" );
		
		HiloA.start();
		HiloA.join();
						
		System.out.println( "Fin" );
	}
}	
