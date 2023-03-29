public class Hilo extends Thread
{
	public Hilo( String nombre )
	{
		super( nombre );			
	}

	public void run()
	{
		System.out.println( this.getName() );
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
