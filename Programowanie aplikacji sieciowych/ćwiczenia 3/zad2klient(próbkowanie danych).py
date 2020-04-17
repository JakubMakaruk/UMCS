#KLIENT

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect(('localhost', 1769))
    try:
        data = "Ala ma kota"
        s.sendall(data.encode('utf-8'))
    except:
        s.close()
    s.close()
except socket.error:
    print ('Error')