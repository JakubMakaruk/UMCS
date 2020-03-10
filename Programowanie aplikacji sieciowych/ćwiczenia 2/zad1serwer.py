#SERWER

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("localhost", 1769))
s.listen(5)

while True:
    client, addr = s.accept()
    print("Connected!" + addr[0])

    while True:
        data = client.recv(1024)
        if not data:
            break;
        print(data.decode('utf-8'))
        client.send(str(int(data)*(int(data))).encode('utf-8'))
    client.close()
client.close()
