#SERWER

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 1769))
s.listen(5)

while True:
    client, addr = s.accept()
    while True:
        data = client.recv(1024)
        if not data:
            break;
        imie=str(data)
        if(imie[-2]=='a'):
            result = "Jestes kobieta!"
            client.send(result.encode('utf-8'))
        else:
            result = "Jestes mezczyzna!"
            client.send(result.encode('utf-8'))
        break;
    client.close()
client.close()