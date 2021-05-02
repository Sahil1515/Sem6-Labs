import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host=socket.gethostname()
port=9992

s.connect((host,port))

tm=s.recv(1024)

print("Current time from server:",tm.decode())

s.close()