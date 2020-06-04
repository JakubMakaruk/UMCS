# SERWER

import _thread
import socket

def fibbonacci(n):
    if n==0:
        print("Zle wejscie!")
    elif n==1:
        return 1
    elif n==2:
        return 1
    else:
        return fibbonacci(n-1)+fibbonacci(n-2)

def new_thread(client, addr):
    clientmsg = b''
    data = b'cos'
    while b'\r\n' not in clientmsg:
        data = client.recv(1)
        clientmsg += data
    wynik = fibbonacci(int(clientmsg.decode()))
    client.sendall((str(wynik) + '\r\n').encode())
    client.close()

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('localhost', 1337))
    s.listen(5)

    client, addr = s.accept()
    print("Connected: " + addr[0])

    _thread.start_new_thread(new_thread, (client, addr))