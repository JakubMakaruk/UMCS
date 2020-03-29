#SERWER

import socket

def zamiana(udp):
    return int(udp, 16)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 1769))
s.listen(5)

try:
    client, addr = s.accept()

    result = client.recv(1024).decode()
    port_zrodlowy = zamiana(str(result[0:4]))
    print(port_zrodlowy)

    port_docelowy = zamiana(str(result[4:8]))
    print(port_docelowy)

    dlugosc = zamiana(str(result[24:25]))
    print(dlugosc)

    dane = bytes.fromhex(result[64:]).decode('utf-8')
    print(dane)

except:
    print("Cos nie tak!")