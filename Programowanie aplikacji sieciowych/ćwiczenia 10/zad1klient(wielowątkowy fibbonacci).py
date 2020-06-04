# KLIENT

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect(('localhost', 1337))

    n = input("Podaj liczbe: ")
    s.sendall((str(n)+'\r\n').encode())

    data_all = b''
    data = b'cos'
    while b'\r\n' not in data_all:
        data = s.recv(1024)
        data_all += data
    print("Wynik: " + data_all.decode())

    s.close()
except socket.error:
    print("Error")