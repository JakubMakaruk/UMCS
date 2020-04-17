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

password="Rewritable123"
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
recv5 = clientSocket.recv(1024)
print(recv5.decode())

clientSocket.send("DATA\r\n".encode())

tytul = input("Podaj tytul: ")
wiadomosc_zwykla = input("Podaj tresc wiadomosci: ")
dane = "Content-Type: multipart/mixed; boundary=\"sepp\"\nMIME-Version: 1.0\nTo: <" + recipient + ">\nFrom: <" + username +">\nSubject: " + tytul + "\n\n--sepp\nContent-Type: text/html; charset=\"us-ascii\"\n\n" + "<b>" + wiadomosc_zwykla + "</b>\n" + "<u>" + wiadomosc_zwykla + "</u>\n" + "<i>" + wiadomosc_zwykla + "</i>" +  "\n\n--sepp\nContent-Type: application/octet-stream; Name=\"wiadomosc\"\nMIME-Version: 1.0\nContent-Transfer-Encoding: base64\nContent-Disposition: attachment; filename=\"wiadomosc.txt\"\n" + "emFzenlmcm93YW5hIHdpYWRvbW9zYyBkbyB6YWxhY3puaWth\n--sep--\r\n.\r\n"

clientSocket.send(dane.encode())
clientSocket.send('QUIT\r\n'.encode())

clientSocket.close()