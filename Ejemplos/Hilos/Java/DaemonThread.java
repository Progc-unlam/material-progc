public class DaemonThread 
{
    public static class MyThread implements Runnable
    {
        @Override
        public void run() 
        {
            System.out.println("TID:    " + Thread.currentThread().getId());
            System.out.println("Nombre: " + Thread.currentThread().getName());
        }
    }

    public static void main(String[] args) throws InterruptedException 
    {
        Thread testThread = new Thread(new MyThread(), "A");
        testThread.setDaemon(true);
        testThread.start();
        Thread.sleep(2000);
    }
}
