public class NoAtomic 
{
    static int count = 0;

    static class MyThread extends Thread 
   {
        public void run()
        {
            for (int i=0; i<100; ++i) 
            {
                count++;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException 
    {
        MyThread []threads = new MyThread[1000];
       
        for(int i=0; i<1000; ++i)
        {
            threads[i] = new MyThread();
        }

        for(int i=0; i<1000; ++i)
        {
            threads[i].start();
        }

        for(int i=0; i<1000; ++i)
        {
            threads[i].join();
        }

        System.out.println("Valor: " + count);		
    }
}
