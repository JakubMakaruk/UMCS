#SERWER

import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("localhost", 1769))
s.listen(1)

try:
    while True:
        client, addr = s.accept()
        result = []
        data = "a"

        while data:
            data = client.recv(1)
            print(data.decode('utf-8'))
            result.append(data)

        print("Ca³a wiadomosc: %s" %(b"".join(i for i in result)))
    
        client.close()

    s.close()
except:
    s.close()