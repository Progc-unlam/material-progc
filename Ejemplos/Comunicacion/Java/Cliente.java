import java.net.ServerSocket;
import java.net.Socket;
import java.io.DataOutputStream;
import java.io.IOException;

class Cliente 
{
	private static final int PUERTO = 5000;
	
	public static void main(String[] args) throws IOException
	{
		Socket cs = new Socket( "127.0.0.1", PUERTO );
		
		DataOutputStream al_servidor;
						
		al_servidor = new DataOutputStream(cs.getOutputStream());
		al_servidor.writeUTF( "Atendeme" );

		cs.close();	
	}
}

