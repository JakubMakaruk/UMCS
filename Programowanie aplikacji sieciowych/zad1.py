
#Program sprawdzający czy dany adres IP jest poprawnym adresem.
import socket

try:
    socket.inet_aton("8.8.8.8")
    print('Valid')
except socket.error:
    print('Not Valid')