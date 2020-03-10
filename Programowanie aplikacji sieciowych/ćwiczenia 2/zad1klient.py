#KLIENT

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect(('localhost', 1769))
    while True:
        data = input("Podaj liczbe: ")
        s.send(data.encode('utf-8'))
        data = s.recv(1024)
        if not data:
            break
        print("Odpowiedz: " + data.decode('utf-8'))
        break;
    s.close()
except socket.error:
    print("Blad!")