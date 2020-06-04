import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('www.httpbin.org', 80))

s.send("""GET /html HTTP/1.1\r\nHost: www.httpbin.org\r\nUser-Agent:Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_3) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/7046A194A\r\n\r\n""".encode())

data = b''
d = b''

while not b'\r\n\r\n' in data:
    d = s.recv(1)
    data += d

lengthcontent=0
sizepage=len(data)

for i in data.split(b'\r\n'):
    if b'Content-Length:' in i:
        lengthcontent=int(i[len(b'Content-Length:'):])

print(lengthcontent)
print(sizepage)
print(data)

while len(data) < lengthcontent+sizepage:
    d = s.recv(1)
    data += d

s.close()

data = data.decode()
print(data)

file = open("index.html", "w+")
file.write(data[data.index('<html'):])
file.close()