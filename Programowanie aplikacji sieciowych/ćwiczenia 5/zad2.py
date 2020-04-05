import socket, base64

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect(("poczta.interia.pl", 587))
recv = clientSocket.recv(1024)
recv = recv.decode()
print(recv)

heloCommand = 'EHLO jakub\r\n'
clientSocket.send(heloCommand.encode())
recv1 = clientSocket.recv(1024)
print(recv1.decode())

auth = 'AUTH login\r\n'
clientSocket.send(auth.encode())
recv2 = clientSocket.recv(1024)
print(recv2.decode())

username="jakub.makaruk@interia.pl"
email = base64.b64encode(username.encode("utf-8"))
clientSocket.send(email+"\r\n".encode())
recv3 = clientSocket.recv(1024)
print(recv3.decode())

password="FAJNE HASLO TAKIE TAJEMNICZE OJ TAK TAK :)"
haslo = base64.b64encode(password.encode("utf-8"))
clientSocket.send(haslo+"\r\n".encode())
recv3 = clientSocket.recv(1024)
print(recv3.decode())

mailfrom = 'MAIL FROM: <' + username + '>\r\n'
clientSocket.send(mailfrom.encode())
recv4 = clientSocket.recv(1024)
print(recv4.decode())

recipient = input("Podaj odbiorce: ")
mailfrom = 'RCPT TO: <' + recipient + '>\r\n'
clientSocket.send(mailfrom.encode())
recv4 = clientSocket.recv(1024)
print(recv4.decode())

clientSocket.send("DATA\r\n".encode())

tytul = input("Podaj tytul: ")
dane = input("Wprowadz dane: ")
to = "To: <" + recipient + ">\nFrom: <" + username + ">\nSubject: " + tytul + "\n\n" + dane + "\n.\r\n"

clientSocket.send(to.encode())
clientSocket.send('QUIT\r\n'.encode())

clientSocket.close()