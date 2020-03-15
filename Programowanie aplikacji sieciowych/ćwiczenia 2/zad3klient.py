#KLIENT

import socket
import pickle

class structure():
    def __init__(a, inted, stringed, floated):
        a.inted = inted
        a.stringed = stringed
        a.floated = floated

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    s.connect(('localhost', 1769))
    while True:
        data = pickle.dumps(structure(1, "napis", 2.5))
        s.send(data)
        data = s.recv(1024)
        if not data:
            break
        print("Odpowiedz: " + data.decode('utf-8'))
        break;
    s.close()
except socket.error:
    print('Error')