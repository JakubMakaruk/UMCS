#SERWER

import socket

def zamiana(liczba):
    return int(liczba, 16)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 1769))
s.listen(5)

try:
    client, addr = s.accept()

    result = client.recv(1024).decode()

    wersja = zamiana(str(result[0:1]))
    print(wersja)

    adres_zrodlowy = str(zamiana(str(result[24:26]))) + "." + str(zamiana(str(result[26:28]))) + "." + str(zamiana(str(result[28:30]))) + "." + str(zamiana(str(result[30:32])))
    print(adres_zrodlowy)

    adres_docelowy = str(zamiana(str(result[32:34]))) + "." + str(zamiana(str(result[34:36]))) + "." + str(zamiana(str(result[36:38]))) + "." + str(zamiana(str(result[38:40])))
    print(adres_docelowy)

    typ_protokolu = zamiana(str(result[18:20]))
    print(typ_protokolu)

    if(typ_protokolu==6):
        port_zrodlowy=zamiana(str(result[40:44]))
        print(port_zrodlowy)
        port_docelowy=zamiana(str(result[44:48]))
        print(port_docelowy)
        tcp = zamiana(str(result[64:65]))
        print(bytes.fromhex(result[tcp*8+40:]).decode('utf-8'))
    elif(typ_protokol==17):
        port_zrodlowy=zamiana(str(result[40:44]))
        print(port_zrodlowy)
        port_docelowy=zamiana(str(result[44:48]))
        print(port_docelowy)
        dane = bytes.fromhex(result[56:]).decode('utf-8')
		print(dane)

except:
    print("Cos nie tak!")