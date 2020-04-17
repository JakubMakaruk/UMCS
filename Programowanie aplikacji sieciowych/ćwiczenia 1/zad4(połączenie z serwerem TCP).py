#Program łączący się z danym serwerem na określonym porcie przy użyciu protokołu TCP i wyświetlający czy udało się nawiązać połączenie czy nie.
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect(("google.pl", 80))
    print("gitara!")
except socket.error:
    print("Blad!")