public class SharedValue
{
    static int[] values;

    public static class MyThread extends Thread
    {
        private int position;
        
        public MyThread( int pos )
        {
            position = pos;			
        }

        public void run()
        {
            System.out.println( "TID: " + this.getId() +" " + values[position] );
        }
    }

    public static void main(String[] args) throws InterruptedException 
    {
        values = new int[2];
        values[0]=10;
        values[1]=20;

        MyThread hiloA = new MyThread(0);
        MyThread hiloB = new MyThread(1);

        hiloA.start();		
        hiloB.start();

        hiloA.join();
        hiloB.join();
    }
}
