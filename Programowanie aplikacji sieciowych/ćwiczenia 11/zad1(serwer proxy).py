import socket
import sys
import _thread

def one_client(client):
    try:
        server_proxy = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        data = b''
        while not b'\r\n\r\n' in data:
            data += client.recv(1)
        odp = data.decode()

        adres = odp.find("://")
        if adres == -1:
            http = odp.split()[1]
        else:
            http = odp[adres + 3:]

        link = http.find("/")
        if link != -1:
            http = http[:link]

        porte = http.find(":")
        if porte != -1:
            port = int(http[porte + 1:])
            http = http[:porte]
        else:
            port = 80
        server_proxy.connect((sys.argv[2], port))

        print("ADRES: " + str(http) + "\nPORT: " + str(port))

        server_proxy.sendall(odp.encode())

        result = server_proxy.recv(1)
        while result:
            client.send(result)
            result = server_proxy.recv(1)
    except socket.error as error:
        print(error)
    client.close()


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("localhost", int(sys.argv[1])))
s.listen(4)
try:
    while True:
        client, addr = s.accept()
        print("Connected: " + addr[0])
        _thread.start_new_thread(one_client, (client, ))
except KeyboardInterrupt:
    s.close()
s.close()