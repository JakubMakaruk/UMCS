import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('www.httpbin.org', 80))

customername=input("Customer name: ")
telephone=input("Telephone: ")
email=input("E-mail address: ")
pizzasize=input("Pizza size\n1.Small\n2.Medium\n3.Large\nCHOICE:")
if pizzasize=='1':
    pizzasize="small"
elif pizzasize=='2':
    pizzasize="medium"
else:
    pizzasize="large"
pizzatoppings=input("Pizza toppings\n1.Bacon\n2.Extra cheese\n3.Onion\n4.Mushroom\nCHOICE:")
if pizzatoppings=='1':
    pizzatoppings="bacon"
elif pizzatoppings=='2':
    pizzatoppings="cheese"
elif pizzatoppings=='3':
    pizzatoppings="onion"
else:
    pizzatoppings="mushroom"
deliverytimeh=input("Delivery time\nHOUR:")
deliverytimemin=input("MINS:")
comments=input("Delivery instructions: ")

data="custname=" + customername + "&custtel=" + telephone + "&custemail=" + email +"&size=" + pizzasize + "&topping=" + pizzatoppings + "&deliver=" + deliverytimeh +"%3A" + deliverytimemin + "&comments=" + comments + "\r\n"
msg = "POST /post HTTP/1.1\r\nHost: www.httpbin.org\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: "+ str(len(data)) + "\r\n\r\n"

bmsg=msg.encode()
bdata=data.encode()
fullmsg=bmsg+bdata

s.sendall(fullmsg)



bata = b''
b = b''
lengthcontent=0

while not b'\r\n\r\n' in bata:
    b = s.recv(1)
    bata += b

lengthcontent=int((bata.split(b'Content-Length:')[1]).split(b'\r\n')[0][1:])
bata=b''
while len(bata) < lengthcontent:
    b = s.recv(1)
    bata += b

print(bata.decode())