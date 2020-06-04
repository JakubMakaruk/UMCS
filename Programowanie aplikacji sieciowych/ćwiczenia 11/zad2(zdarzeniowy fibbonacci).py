import socket
import select

def fibbonacci(n):
    if n==0:
        print("Zle wejscie!")
    elif n==1:
        return 1
    elif n==2:
        return 1
    else:
        return fibbonacci(n-1)+fibbonacci(n-2)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 1337))
s.listen(5)

clients = []
clients.append(s)

while True:
    c,_,_=select.select(clients, [], [])
    for i in c:
        if i == s:
            client, addr = s.accept()
            clients.append(client)
            print("Connected: " + addr[0])
            continue
        clientmsg = b''
        data = b'cos'
        while b'\r\n' not in clientmsg:
            data = i.recv(1)
            clientmsg += data
        wynik = fibbonacci(int(clientmsg.decode()))
        i.sendall((str(wynik) + '\r\n').encode())
        clients.remove(i)
        i.close()