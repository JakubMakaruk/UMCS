#Program wyświetlający adres IP dla danego hostname
import socket

try:
    hostname = socket.gethostbyname("google.pl")
    print(hostname)
except:
    print("Nie dziala!")