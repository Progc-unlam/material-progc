import java.util.concurrent.Semaphore;

public class ThreadsSemaphore 
{
    static int value=0;
    static Semaphore mtx = new Semaphore(1);

    static class MyThread extends Thread 
   {
        public void run() 
        {
            try
            {
                mtx.acquire();
                value+=1;
                mtx.release();
            }
            catch( Exception e )
            {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) throws InterruptedException 
    {
        MyThread threadA = new MyThread();
        MyThread threadB = new MyThread();

        threadA.start();
        threadB.start();			

        threadA.join();
        threadB.join();

        System.out.println("Valor: " + value);		
    }
}
