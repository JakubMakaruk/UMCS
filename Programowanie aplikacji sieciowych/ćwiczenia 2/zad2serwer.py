#SERWER
import socket
import datetime

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("localhost", 1769))
s.listen(5)

while True:
    client, addr = s.accept()
    while True:
        data = client.recv(1024)
        if not data:
            break;
        print(data.decode("utf-8"))
        client.send(datetime.datetime.now().strftime('%d-%m-%Y %H::%M::%S').encode('utf-8'))
    client.close()
s.close()