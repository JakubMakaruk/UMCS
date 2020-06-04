# KLIENT (drugi gracz)

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

board = [['-', 'X', '-'],
         ['-', '-', 'X'],
         ['X', '-', '-']]

zestrzelonych = 0

s.connect(('localhost', 1337))
try:
    while True:
        s.sendall(("TWOJ_RUCH \r\n\r\n").encode())

        data = b''
        while not b'\r\n\r\n' in data:
            data += s.recv(1)

        enemyX = int((data.split(b'X:')[1]).split(b'\r\n')[0])
        enemyY = int((data.split(b'Y:')[1]).split(b'\r\n')[0])

        print("STRZAL GRACZA: " + "x=" + str(enemyX) + " y=" + str(enemyY))
        if board[enemyX][enemyY] == 'X':
            board[enemyX][enemyY] = '-'
            print("OBERWALISMY!")
            zestrzelonych+=1
            if zestrzelonych==3:
                s.sendall(("WYGRALES\r\n\r\n").encode())
                print("TO KONIEC :( ZESTRZELILI NAS")
                exit()
            else:
                s.sendall(("TRAFIONY\r\n\r\n").encode())
        elif board[enemyX][enemyY] == '-':
            print("HAHA! SPUDLOWAL!")
            s.sendall(("PUDLO\r\n\r\n").encode())
        #elif board[enemyX][enemyY] == 'JUZ TU STRZELALES'

        enemyMsg = b''
        while not b'\r\n\r\n' in enemyMsg:
            enemyMsg += s.recv(1)
        if(b'TWOJ_RUCH' in enemyMsg):
            x = input("Podaj X(od 0 do 2): ")
            y = input("Podaj Y(od 0 do 2): ")

            s.sendall(("X: " + str(x) + "\r\nY:" + str(y) + "\r\n\r\n").encode())
            wynik = b''
            while b'\r\n\r\n' not in wynik:
                wynik += s.recv(1024)
            print(wynik.decode())
            if (str(wynik.decode()) == "WYGRALES\r\n\r\n"):
                print("WYGRALES GRE!")
                exit()

except socket.error:
    print("ERROR")