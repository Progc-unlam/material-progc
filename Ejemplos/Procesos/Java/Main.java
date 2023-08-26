import java.io.IOException;
import java.lang.management.ManagementFactory;

public class EjemploProcess
{
    public static long getProcessId()
    {
        return ManagementFactory.getRuntimeMXBean().getPid();
    }

    public static void main(String[] args) throws IOException, InterruptedException
    {
        System.out.println("PID: " + getProcessId());

        ProcessBuilder pb = new ProcessBuilder("java", "HolaMundo.java");
        pb.redirectErrorStream(true);
        pb.inheritIO();
        
        Process proceso = pb.start();
        int error = proceso.waitFor();
		
        if( error != 0 )
        {
            System.out.println("HolaMundo.java finalizó con error");
        }
    }
}
