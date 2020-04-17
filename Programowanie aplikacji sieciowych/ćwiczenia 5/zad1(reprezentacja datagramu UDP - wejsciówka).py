def zamiana(udp):
    return int(udp, 16)

def usunspacje(string):
    return string.replace(" ", "")



pdatagram = "68 00 55 6f 00 24 ef fd 70 72 6f 67 72 61 6d 6d 69 6e 67 20 69 6e 20 70 79 74 68 6f 6e 20 69 73 20 66 75 6e"
result = usunspacje(pdatagram)

port_zrodlowy = zamiana(str(result[0:4]))
print(port_zrodlowy)

port_docelowy = zamiana(str(result[4:8]))
print(port_docelowy)

dane = bytes.fromhex(result[16:]).decode('utf-8')
print(dane)