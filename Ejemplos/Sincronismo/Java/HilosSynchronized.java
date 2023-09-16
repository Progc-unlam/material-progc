public class ThreadsSynchronized
{
    static class MyThread extends Thread
    {
        static int value = 0;

        synchronized public void run()
        {
            value++;
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
