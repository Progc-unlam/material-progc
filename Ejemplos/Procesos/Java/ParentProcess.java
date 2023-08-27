import java.io.IOException;

class ParentProcess 
{
    static Process childs[]; 
	
    public static void createChilds( int numberOfChilds ) throws IOException
    {		
        ProcessBuilder builder;
        childs = new Process[ numberOfChilds ];
        for(int i=0; i<numberOfChilds; i++)
        {
            builder = new ProcessBuilder("java","ChildProcess.java",Integer.toString(i+1));
           	builder.inheritIO();
            childs[ i ] = builder.start();
        }
    }

    public static void waitChilds( int numberOfChilds ) throws InterruptedException
    {		
        for(int i=0; i<numberOfChilds; i++)
        {
            childs[ i ].waitFor();
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException
    {
        int numberOfChilds = Integer.valueOf(args[0]);
        createChilds( numberOfChilds );
        waitChilds( numberOfChilds );		
    }
}