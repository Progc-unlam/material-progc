public class EjemploGetPid
{
    public static void mostrarInfo()
    {		
        ProcessHandle yo = ProcessHandle.current();
        long pid  = yo.pid();
        long ppid = yo.parent().get().pid();
        System.out.println("PID: " + pid + " PPID: " + ppid );
    }

    public static void main(String[] args)
    {
        mostrarInfo();	
    }
}