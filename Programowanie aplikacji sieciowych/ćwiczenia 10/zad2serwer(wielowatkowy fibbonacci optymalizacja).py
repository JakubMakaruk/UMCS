# SERWER

import os
import socket
import asyncio

async def new_thread(client, addr):
    clientfilename = client.recv(1024)

    if os.path.isfile(clientfilename.decode()):
        file = open(clientfilename.decode(), "r")
        content = file.read()
        client.sendall((str(content)+"\r\n").encode())
    else:
        client.sendall(("Taki plik nie istnieje!\r\n").encode())
    client.close()

async def main():
    while True:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind(('localhost', 1337))
        s.listen(5)

        client, addr = s.accept()
        print("Connected: " + addr[0])

        await new_thread(client, addr)

asyncio.run(main())