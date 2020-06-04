# KLIENT

import socket
import os

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect(('localhost', 1337))
    s.sendall(("GET_IMAGE \r\n\r\n").encode())

    data = b''
    while not b'\r\n\r\n' in data:
        data += s.recv(1)

    size = int((data.split(b'SIZE:')[1]).split(b'\r\n')[0])
    name = data[data[0:].find(b'NAME') + 6 :]

    content_length = 0
    with open('saved/' + name.decode().split('\r\n')[0], 'wb') as f: #trzeba utworzyc folder saved
        if len(data.split(b'\r\n\r\n')) > 1:
            f.write(data.split(b'\r\n\r\n')[1])
            content_length += len(data.split(b'\r\n\r\n')[1])

        while content_length < size:
            data = s.recv(1)
            f.write(data)
            content_length += len(data)
            print(str(100*content_length/size) + '%')

    f.close()
    s.close()
except socket.error:
    print("ERROR")