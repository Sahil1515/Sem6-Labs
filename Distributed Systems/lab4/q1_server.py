import socket
import time

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
udp_host = socket.gethostname()
print(udp_host)
udp_port = 12345
sock.bind((udp_host,udp_port))

while True:
	print("Waiting for client..")
	data,addr  = sock.recvfrom(1024)
	print("Received Messages:",data.decode(),"from",addr)
	currenttime = time.ctime(time.time())+"\r\n"
	sock.sendto(currenttime.encode(),addr)