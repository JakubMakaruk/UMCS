#KLIENT

def usunspacje(string):
    return string.replace(" ", "")

import socket
import string

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

pdatagram = "45 00 00 4e f7 fa 40 00 38 06 9d 33 d4 b6 18 1bc0 a8 00 02 0b 54 b9 a6 fb f9 3c 57 c1 0a 06 c180 18 00 e3 ce 9c 00 00 01 01 08 0a 03 a6 eb 0100 0b f8 e5 6e 65 74 77 6f 72 6b 20 70 72 6f 6772 61 6d 6d 69 6e 67 20 69 73 20 66 75 6e"

datagram = usunspacje(pdatagram)
print(datagram)

try:
    s.connect(('localhost', 1769))
    try:
        s.send(datagram.encode('utf-8'))
    except:
        s.close()
    s.close()
except socket.error:
    print("Error")