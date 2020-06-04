# SERWER

import _thread
import socket
import os

def new_thread(client, addr):
    clientfilename = client.recv(1024)

    if os.path.isfile(clientfilename.decode()):
        file = open(clientfilename.decode(), "r")
        content = file.read()
        client.sendall((str(content)+"\r\n").encode())
    else:
        client.sendall(("Taki plik nie istnieje!\r\n").encode())
    client.close()

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('localhost', 1337))
    s.listen(5)

    client, addr = s.accept()
    print("Connected: " + addr[0])

    _thread.start_new_thread(new_thread, (client, addr))