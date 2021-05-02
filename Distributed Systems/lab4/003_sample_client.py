import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host=socket.gethostname()
port=9991

s.connect((host,port))

while True:
    print("Client:",end=' ')
    data=str(input())
    temp=data
    s.sendall(bytearray(data,'utf-8'))
    if temp.lower()=='bye':
            break

    data=s.recv(1024)
    print("Server:",data.decode())
    if data.decode().lower()=='bye':
            break
    
    

s.close()