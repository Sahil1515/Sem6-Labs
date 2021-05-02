

import socket as skt

sock = skt.socket(skt.AF_INET, skt.SOCK_DGRAM)

udp_host = skt.gethostname()
print(udp_host)
udp_port = 12345
msg = "Hello brother"
print('Target UDP host {}\nTarget UDP port {}'.format(str(udp_host), str(udp_port)))

msg = 'Client'
sock.sendto(msg.encode(), (udp_host, udp_port))
data, addr = sock.recvfrom(1024)
name = data.decode()

while True:
	msg = input('Me: ')
	sock.sendto(msg.encode(), (udp_host, udp_port))
	if msg == 'exit':
		break
	data, addr = sock.recvfrom(1024)
	if data.decode() == 'exit':
		print(name, ' has exited')
	else:
		print(name, ": ", data.decode())