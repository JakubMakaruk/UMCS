#SERWER

import socket
import pickle

class structure():
    def __init__(a, inted, stringed, floated):
        a.inted = inted
        a.stringed = stringed
        a.floated = floated

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 1769))
s.listen(5)

while True:
    client, addr = s.accept()
    while True:
        data = client.recv(1024)
        if not data:
            break
        data_p = pickle.loads(data)
        client.send(data_p.stringed.encode('utf-8'))
        break
    client.close()
s.close()