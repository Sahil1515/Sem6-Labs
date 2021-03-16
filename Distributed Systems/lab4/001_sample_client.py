import  socket

HOST='127.0.0.1'
PORT=2053

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    data=input("send data to server:")
    s.sendall(bytearray(data,'utf-8'))
    data=s.recv(1024)
    print("From Server Got back")
    print(data.decode())

