public class CompartirVariable
{
	static int valores[];
	
	public static class Hilo extends Thread
	{
		private int posicion;
		
		public Hilo( int pos )
		{
			posicion = pos;			
		}
	
		public void run()
		{
			System.out.println( "TID: " + this.getId() +" " + valores[ posicion ] );
		}
	}
	
	public static void main(String[] args) throws InterruptedException 
	{
		valores = new int[2];
		valores[ 0 ]=10;
		valores[ 1 ]=20;
			
		Hilo HiloA = new Hilo( 0 );
		Hilo HiloB = new Hilo( 1 );
		
		HiloA.start();		
		HiloB.start();
		
		HiloA.join();
		HiloB.join();
					
		System.out.println( "Fin" );
	}
}	



