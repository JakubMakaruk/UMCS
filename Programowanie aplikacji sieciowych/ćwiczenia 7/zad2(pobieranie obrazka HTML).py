import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('www.httpbin.org', 80))

s.send("""GET /image/png HTTP/1.1\r\nHost: www.httpbin.org\r\n\r\n""".encode())

data = b''
d = b''
lengthcontent=0

while not b'\r\n\r\n' in data:
    d = s.recv(1)
    data += d

lengthcontent=int((data.split(b'Content-Length:')[1]).split(b'\r\n')[0][1:])
data=b''
while len(data) < lengthcontent:
    d = s.recv(1)
    data += d

s.close()

file = open("photo.png", "wb")
file.write(data[:lengthcontent])
file.close()