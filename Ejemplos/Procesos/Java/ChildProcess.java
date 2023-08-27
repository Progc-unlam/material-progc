class ChildProcess 
{
    public static void showInfo( int number )
    {		
        ProcessHandle me = ProcessHandle.current();
        String message = "("+number+") PID: " + me.pid();
        System.out.println( message );
    }

    public static void main(String[] args)
    {
        showInfo( Integer.valueOf(args[0]) );
    }
}