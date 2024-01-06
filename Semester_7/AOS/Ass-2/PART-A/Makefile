default:
	sudo docker build -t ubuntu-xdp -f DockerfileXDP .
	sudo docker build -t ubuntu-gcc -f DockerfileGCC .
	make create_network
	make start_pf

create_network:
	sudo docker network inspect aosd > /dev/null 2>&1 || sudo docker network create --subnet=172.18.0.0/16 aosd

start_pf:
	sudo docker run -d --privileged --network aosd   --ip 172.18.0.51 --name xdp_pf ubuntu-xdp /bin/sh -c "tail -f /dev/null"
	make modify_pf

modify_pf:
	sudo docker cp packet_filter.c  xdp_pf:/home/packet_filter.c
	sudo docker cp xdp_loader.c  xdp_pf:/home/xdp_loader.c
	sudo docker exec -it xdp_pf bash -c "cd /home && clang -O2 -target bpf -g -c packet_filter.c -o packet_filter.o"
	sudo docker exec -it xdp_pf bash -c "ip link set dev eth0 xdpgeneric off"
	sudo docker exec -it xdp_pf bash -c "cd /home && gcc -o xdp_loader xdp_loader.c -lbpf  && ./xdp_loader eth0"
delete_pf:
	sudo docker stop xdp_pf
	sudo docker rm xdp_pf


start_server:
	make modify_server

modify_server:
	sudo docker cp server.c xdp_pf:/home/server.c
	sudo docker exec -it xdp_pf bash -c "cd /home && gcc -o server -pthread server.c && ./server 7000"

start_client:
	sudo docker run -d --network aosd --name ubuntu_c_client_A --ip 172.18.0.61 ubuntu-gcc /bin/sh -c "tail -f /dev/null"
	make modify_client
modify_client:
	sudo docker cp client.c ubuntu_c_client_A:/home/client.c
	sudo docker exec -it ubuntu_c_client_A bash -c "cd /home && gcc -o client client.c && ./client 7000"
delete_client:
	sudo docker stop ubuntu_c_client_A
	sudo docker rm ubuntu_c_client_A