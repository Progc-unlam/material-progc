import java.net.ServerSocket;
import java.net.Socket;
import java.net.InetAddress;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Servidor 
{
	private static final int MAX_PEND = 10;
	private static final int PUERTO = 5000;
	
	public static void main(String[] args) throws IOException
	{
		ServerSocket ss = new ServerSocket
		( 
			PUERTO, 
			MAX_PEND, 
			InetAddress.getByName("127.0.0.1") 
		);
				
		System.out.println("Esperando");
		
		Socket cs = ss.accept();
				
		BufferedReader del_cliente = new BufferedReader
		(
			new InputStreamReader(cs.getInputStream())
		);

		System.out.println( del_cliente.readLine() );
		
		ss.close();
		cs.close();	
	}
}

