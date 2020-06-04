# KLIENT

import socket
import os

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


try:
    s.connect(('localhost', 1337))
    filesize = os.path.getsize("plik.txt")
    s.send(("Size: " + str(filesize) + "\r\n\r\n").encode())

    data = b''
    while b'WYSYLAJ DANE' not in data:
        data += s.recv(1)
    print("SERVER: " + data.decode())

    with open("plik.txt", "r") as f:
        a = f.read(1)
        while a:
            s.send(a.encode())
            print("Wyslano: " + a)
            a = f.read(1)

except:
    print("Error")