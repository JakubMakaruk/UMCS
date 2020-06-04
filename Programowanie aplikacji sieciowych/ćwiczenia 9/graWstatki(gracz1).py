# SERWER (pierwszy gracz)

import socket

board = [['X', '-', '-'],
         ['-', 'X', 'X'],
         ['-', '-', '-']]

zestrzelonych = 0

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('localhost', 1337))
    s.listen(5)

    client, addr = s.accept()
    print("CONNECTED: " + addr[0])

    while True:
        data = b''
        while b'\r\n\r\n' not in data:
            data += client.recv(1024)

        if(b'TWOJ_RUCH' in data):
            x = input("Podaj X(od 0 do 2): ")
            y = input("Podaj Y(od 0 do 2): ")

            client.sendall(("X: " + str(x) + "\r\nY: " + str(y) + "\r\n\r\n").encode())
            wynik = b''
            while b'\r\n\r\n' not in wynik:
                wynik += client.recv(1024)
            print(wynik.decode())
            if str(wynik.decode()) == "TRAFIONY\r\n\r\n" or str(wynik.decode()) == "PUDLO\r\n\r\n":
                client.sendall(("TWOJ_RUCH \r\n\r\n").encode())

                msgKlienta = b''
                while not b'\r\n\r\n' in msgKlienta:
                    msgKlienta += client.recv(1)
                klientX = int((msgKlienta.split(b'X:')[1]).split(b'\r\n')[0])
                klientY = int((msgKlienta.split(b'Y:')[1]).split(b'\r\n')[0])
                print("STRZAL GRACZA: " + "x=" + str(klientX) + " y=" + str(klientY))
                if board[klientX][klientY] == 'X':
                    board[klientX][klientY] = '-'
                    print("OBERWALISMY!")
                    zestrzelonych+=1
                    if zestrzelonych == 3:
                        client.sendall(("WYGRALES\r\n\r\n").encode())
                        print("TO KONIEC :( ZESTRZELILI NAS")
                        exit()
                    else:
                        client.sendall(("TRAFIONY\r\n\r\n").encode())
                elif board[klientX][klientY] == '-':
                    print("HAHA! SPUDLOWAL!")
                    client.sendall(("PUDLO\r\n\r\n").encode())
            elif(str(wynik.decode()) == "WYGRALES\r\n\r\n"):
                print("WYGRALES GRE!")
                exit()

except socket.error:
    print("ERROR")