public class ThreadsSynchronizedB
{
    static int value = 0;

    static class MyThread extends Thread
    {
        public void run()
        {
            synchronized(this)
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
				
        System.out.println("Valor "+value );		
    }
}
