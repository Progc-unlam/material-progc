import java.io.IOException;

public class Main
{
    public static void main(String[] args) throws IOException,  InterruptedException
	{
        try
		{
            ProcessBuilder pb = new ProcessBuilder("java", "HolaMundo.java");
            
			pb.redirectErrorStream(true);
            pb.inheritIO();
            
			Process proceso = pb.start();
            
			int error = proceso.waitFor();
			
			if( error != 0 )
			{
				System.out.println("Error al ejecutar el programa");
			}
        }
    }
}

