#KLIENT

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

datagram = "ed740b550024effd70726f6772616d6d696e6720696e20707974686f6e2069732066756e"

try:
    s.connect(('localhost', 1769))
    try:
        s.send(datagram.encode('utf-8'))
    except:
        s.close()
    s.close()
except socket.error:
    print("Error")