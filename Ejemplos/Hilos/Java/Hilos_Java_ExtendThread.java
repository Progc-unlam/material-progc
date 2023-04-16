public class Hilos_Java_ExtendThread
{
	public static class Hilo extends Thread
	{
		public Hilo( String nombre )
		{
			super( nombre );			
		}
	
		public void run()
		{
			System.out.println( "TID:    " + this.getId() );
			System.out.println(	"Nombre: " + this.getName() );
		}
	}
	
	public static void main(String[] args) throws InterruptedException 
	{
		Hilo HiloA = new Hilo("Hilo A");
		
		HiloA.start();		
		HiloA.join();
					
		System.out.println( "Fin" );
	}
}	


