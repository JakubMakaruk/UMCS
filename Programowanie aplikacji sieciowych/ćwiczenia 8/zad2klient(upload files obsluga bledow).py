# KLIENT

import socket
import os
from os import path

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect(('localhost', 1337))

    pathname = input("Podaj nazwe pliku: ")
    while not path.exists(pathname):
        print("Taki plik nie istnieje!")
        pathname = input("Podaj nazwe pliku: ")

    filesize = os.path.getsize("plik.txt")
    s.send(("Size: " + str(filesize) + "\r\n\r\n").encode())

    data = b''
    while b'WYSYLAJ DANE' not in data:
        data += s.recv(1)
    print("SERVER: " + data.decode())
    y = input("nacisnij Y aby wyslac plik lub N aby zrezygnowac: ")
    y=y.upper()
    if y=='N':
        print("Zrezygnowano z przesylania pliku!")
    else:
        with open("plik.txt", "r") as f:
            a = f.read(1)
            while a:
                s.send(a.encode())
                print("Wyslano: " + a)
                a = f.read(1)
        print("Zakonczono przesylanie!")
except:
    print("Error")