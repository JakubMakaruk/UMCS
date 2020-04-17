#KLIENT

import socket

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

serverSocket.connect(("localhost", 1337))
while True:
    ehlo_command = input("Wprowadz ehlo [ehlo USERNAME]: ")
    serverSocket.send(ehlo_command.encode())
    result_ehlo = serverSocket.recv(1024).decode()
    print(result_ehlo)
    while result_ehlo.find("404")<0: #jezeli w komunikacie z serwera nie znaleziono 404 - kod błędu
        authlogin_command = input("Wprowadz auth login: ")
        serverSocket.send(authlogin_command.encode())
        result_auth = serverSocket.recv(1024).decode()
        print(result_auth)
        while result_auth.find("404")<0:
            login = input("Podaj login: \n")
            serverSocket.send(login.encode())
            result_login = serverSocket.recv(1024).decode()
            print(result_login)
            password = input("Podaj haslo: \n")
            serverSocket.send(password.encode())
            result_password = serverSocket.recv(1024).decode()
            print(result_password)
            while result_password.find("300")>=0:
                msg_mailfrom = input()
                serverSocket.send(msg_mailfrom.encode())
                msg_rcptto = input()
                serverSocket.send(msg_rcptto.encode())
                msg_data = input()
                serverSocket.send(msg_data.encode())
                msg_to = input()
                serverSocket.send(msg_to.encode())
                msg_from = input()
                serverSocket.send(msg_from.encode())
                msg_subject = input()
                serverSocket.send(msg_subject.encode())
                msg_content = ""
                while True:
                    line = input()
                    if(line!="."):
                        msg_content=msg_content+line
                    else:
                        break
                serverSocket.send(msg_content.encode())
                msg_quit = input()
                serverSocket.send(msg_quit.encode())

                print("Koniec")

                result = serverSocket.recv(1024).decode()
                print(result)
                serverSocket.close()
