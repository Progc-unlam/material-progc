public class ExtendThread
{
    public static class MyThread extends Thread
    {
        public void run()
        {
            System.out.println("TID:    " + this.getId());
            System.out.println("Nombre: " + this.getName());
        }
    }

    public static void main(String[] args) throws InterruptedException 
    {
        MyThread testThread = new MyThread();

        testThread.start();		
        testThread.join();        
    }
}
