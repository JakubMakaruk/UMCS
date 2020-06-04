# SERWER

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 1337))
s.listen(5)

client, addr = s.accept()
print("Connected: " + addr[0])
data = b''

while not b'\r\n\r\n' in data:
    data += client.recv(1)

size = int((data.split(b'Size: ')[1]).split(b'\r\n')[0])
print(size)
client.sendall('WYSYLAJ DANE'.encode())

content_length=0

with open("pobranePlik.txt", "w") as f:
    while content_length < size:
        data = client.recv(1)
        content_length += len(data)
        data = data.decode()
        print("Pobrano: " + str(data))
        f.write(data)
f.close()
client.close()
s.close()