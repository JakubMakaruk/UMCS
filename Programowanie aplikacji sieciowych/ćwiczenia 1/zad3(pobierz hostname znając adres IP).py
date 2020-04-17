#Program wyświetlający hostname dla podanego adresu IP
import socket

try:
    hostname = socket.gethostbyaddr("8.8.8.8")
    print(hostname)
except:
    print("Nie dziala!")