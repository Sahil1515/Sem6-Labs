import socket
import time

serversoc=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

host=socket.gethostname()

port=9992

serversoc.bind((host,port))

serversoc.listen(5)

while True:
    conn,addr=serversoc.accept()

    print("Got connection from :",addr[0],addr[1])
    currentTime=time.ctime(time.time())

    conn.send(currentTime.encode('ascii'))
    conn.close()
serversoc.close()