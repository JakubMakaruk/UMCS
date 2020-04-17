#KLIENT

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

datagram = "0b54898b1f9a18ecbbb164f2801800e3677100000101080a02c1a4ee001a4cee68656c6c6f203a29"

try:
    s.connect(('localhost', 1769))
    try:
        s.send(datagram.encode('utf-8'))
    except:
        s.close()
    s.close()
except socket.error:
    print("Error")