#KLIENT

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('localhost', 1769))

filename = input("Enter filename: ")

s.send(filename.encode())

port = s.recv(1024).decode()

if port != "Taki plik nie istnieje!":
    print("Received port: " + port)

    ftpsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ftpsocket.connect(('localhost', int(port)))

    result = ftpsocket.recv(1024).decode()
    print("From file '" + filename + "' : " + result)
else:
    print(port)

s.close()