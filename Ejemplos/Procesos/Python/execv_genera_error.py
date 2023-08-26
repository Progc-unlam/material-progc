import os
import sys

try:
    os.execv("", ["/bin/ls","-l"] )

except OSError as error:
    sys.exit( "Error: " + os.strerror( error.errno ) )