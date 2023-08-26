import java.lang.management.ManagementFactory;

class HolaMundo 
{
    public static void main(String[] args)
    {
        long pid = ManagementFactory.getRuntimeMXBean().getPid();
        System.out.println("PID: " + pid);
        System.out.println("Hola Mundo!");
	}
}
