public class ThreadsSynchronized
{
    private static final Object lock = new Object();
	static int value = 0;

    static class MyThread extends Thread
    {
        public void run()
        {
            synchronized(lock)
			{
			    value++;
			}	
        }	      
    }

    public static void main(String[] args) throws InterruptedException 
    {
        MyThread hiloA = new MyThread();
        MyThread hiloB = new MyThread();

        hiloA.start();
        hiloB.start();			

        hiloA.join();
        hiloB.join();
				
        System.out.println("Valor " + value);		
    }
}
