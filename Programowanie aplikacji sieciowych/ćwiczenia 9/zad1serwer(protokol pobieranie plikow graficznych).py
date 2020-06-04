# SERWER

import socket
import os

pathname = "zdj.png" #musi byc plik w formacie .png o takiej nazwie

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('localhost', 1337))
    s.listen(5)

    info = os.stat(pathname)
    size = info.st_size

    while True:
        client, addr = s.accept()
        print("CONNECTED: " + addr[0])

        data = b''
        while b'\r\n\r\n' not in data:
            data += client.recv(1024)

        if(b'GET_IMAGE' in data):
            client.sendall(("SIZE: " + str(size) + "\r\nNAME: " + pathname + "\r\n\r\n").encode())
            with open(pathname, 'rb') as f:
                l = f.read(1024)
                while(l):
                    client.sendall(l)
                    if f:
                        l = f.read(1024)

                f.closed
        client.close()
    s.close()
except socket.error:
    print("ERROR")