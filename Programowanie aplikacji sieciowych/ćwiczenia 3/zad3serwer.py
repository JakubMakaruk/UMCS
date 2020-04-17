#SERWER

import socket
import random
import os

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 1769))
s.listen(1)

client, addr = s.accept()
print("Connected by addres: ", addr)

filename = client.recv(1024).decode()
print("Filename: " + str(filename))

if os.path.isfile(filename):
    high_port = random.randint(60000, 65535)

    ftp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ftp_socket.bind(('localhost', high_port))
    ftp_socket.listen(1)

    client.send(str(high_port).encode())

    ftp_client, ftp_addr = ftp_socket.accept()

    file = open(filename, "r")
    content = file.read()
    print("File's content: " + content)

    ftp_client.send(content.encode())
else:
    client.send("Taki plik nie istnieje!".encode())


client.close()
