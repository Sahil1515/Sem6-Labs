import socket
import time

serversoc=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

host=socket.gethostname()

port=9991

serversoc.bind((host,port))

serversoc.listen(5)

conn,addr=serversoc.accept()

while True:

    data=conn.recv(1024)
    
    if data: 
        print("Client: ",data.decode())
        if data.decode().lower()=='bye':
            break

    print("Server:",end=' ')
    send_data=str(input())

    conn.sendall(bytearray(send_data,'utf-8'))

    if send_data.lower()=='bye':
            break


serversoc.close()