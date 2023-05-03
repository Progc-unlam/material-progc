public class HilosSincro
{
	static int res=0;
	
	static class Hilo extends Thread
	{
		synchronized public void run()
		{
		    res+=1;
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

