import socket

# host=socket.gethostname()

HOST = '127.0.0.1'
PORT = 2053

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.listen(5)
    conn,addr=s.accept()
    print("Hi")

    with conn:
        print("Connected by :",addr)
        while True:
            data=conn.recv(1024)
            if data:
                print("From client got:",data.decode())
                data=input("Enter msg to client:")       

            if not data:
                break

            conn.sendall(bytearray(data,'utf-8'))

print("Hello")

conn.close()