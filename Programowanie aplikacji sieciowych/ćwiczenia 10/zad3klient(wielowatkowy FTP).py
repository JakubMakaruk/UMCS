# KLIENT

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect(('localhost', 1337))

    filename = input("Podaj nazwe pliku: ")
    s.sendall(filename.encode())

    data_all = b''
    data = b'cos'
    while b'\r\n' not in data_all:
        data = s.recv(1)
        data_all += data

    print("From file: " + data_all.decode())

    s.close()
except socket.error:
    print("Error")