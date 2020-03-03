#Skaner portów, który dla danego serwera będzie sprawdzał jakie porty są otwarte przy użyciu protokołu TCP.
import socket

for port in range(75, 85):
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(1)
        result = s.connect(("google.pl", port))
        print ("Git")
        s.close()
    except socket.error:
        print("Blad!")