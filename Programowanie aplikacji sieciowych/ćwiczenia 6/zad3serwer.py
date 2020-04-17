#SERWER

import socket
import base64

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("localhost", 1337))
s.listen(1)

client, address = s.accept()
print("Connected with client by address: ", address)

ehlo_command = client.recv(1024).decode()
if ehlo_command.find("ehlo")>=0 or ehlo_command.find("EHLO")>=0:
    client.send(str("Polaczono!\n250-localhost").encode())
else:
    client.send(str("404 Bledna komenda!").encode())

auth_command = client.recv(1024).decode()
if auth_command=="auth login" or auth_command=="AUTH LOGIN":
    client.send(str("334 OK ").encode())
else:
    client.send(str("404 Bledna komenda!").encode())

login = client.recv(1024).decode()
l = str(base64.b64decode(login), 'utf-8')
print(l)
client.send(str("OK ").encode())
password = client.recv(1024).decode()
p = str(base64.b64decode(password), 'utf-8')
print(p)
if l=="jakub.makaruk@interia.pl" and p=="12345":
    client.send(str("300 Proces autentykacji zakonczony pomyslnie!\n").encode())
else:
    client.send(str("Zly login lub haslo! Wprowadz ponownie:\n").encode())

mailfrom = client.recv(1024).decode()
print("MAILFROM: " + mailfrom)
rcptto = client.recv(1024).decode()
print("RCPTO: " + rcptto)
data = client.recv(1024).decode()
print("DATA: " + data)
to = client.recv(1024).decode()
print("TO: " + to)
mfrom = client.recv(1024).decode()
print("FROM: " + mfrom)
subject = client.recv(1024).decode()
print("SUBJECT: " + subject)
message = client.recv(1024).decode()
print("MESSAGE: " + message)
quit = client.recv(1024).decode()
print("QUIT: " + quit)

if(mailfrom.find("MAIL FROM:")<0 or rcptto.find("RCPT TO:")<0 or data!="DATA" or to.find("TO:")<0 or mfrom.find("FROM:")<0 or subject.find("SUBJECT:")<0 or quit!="QUIT"):
    client.send(str("BLAD SKLADNI MAILA").encode())
else:
    client.send(str("Wylsano wiadomosc email o zawartosci: "+message).encode())