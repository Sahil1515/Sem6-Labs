

import socket as skt
import time
sock = skt.socket(skt.AF_INET, skt.SOCK_DGRAM)

udp_host = skt.gethostname()
udp_port = 12345

sock.bind((udp_host, udp_port))
print('Waiting for client')
data, addr = sock.recvfrom(1024)
msg = 'Server'
sock.sendto(msg.encode(), addr)
name = data.decode()
while True:
	data, addr = sock.recvfrom(1024)
	if data.decode() == 'exit':
		print(name, ' has exited')
	else:
		print(name, ": ", data.decode())
	msg = input('Me: ')

	sock.sendto(msg.encode(), addr)
	if msg == 'exit':
		break
