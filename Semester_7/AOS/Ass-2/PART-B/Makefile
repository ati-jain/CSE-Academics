default:
	sudo docker build -t ubuntu-xdp -f DockerfileLB .
	sudo docker build -t ubuntu-gcc -f DockerfileGCC .
	make create_network

create_network:
	sudo docker network inspect aosd > /dev/null 2>&1 || sudo docker network create --subnet=172.18.0.0/16 aosd



start_lb:
	sudo docker run -d --privileged -p 8080:8080/udp --network aosd   --ip 172.18.0.2 --name xdp_lb ubuntu-xdp /bin/sh -c "tail -f /dev/null"
	make modify_lb
modify_lb:
	sudo docker cp lb.c  xdp_lb:/home/lb.c
	sudo docker cp xdp_loader.c  xdp_lb:/home/xdp_loader.c
	sudo docker exec -it xdp_lb bash -c "cd /home && clang -O2 -target bpf -g -c lb.c -o lb.o"
	sudo docker exec -it xdp_lb bash -c "ip link set dev eth0 xdpgeneric off"
	sudo docker exec -it xdp_lb bash -c "cd /home && gcc -o xdp_loader xdp_loader.c -lbpf  && ./xdp_loader eth0"
delete_lb:
	sudo docker stop xdp_lb
	sudo docker rm xdp_lb



start_server_1:
	sudo docker run -d --network aosd --name ubuntu_c_server_1 --ip 172.18.0.3 ubuntu-gcc /bin/sh -c "tail -f /dev/null"
	make modify_server_1
modify_server_1:
	sudo docker cp server.c ubuntu_c_server_1:/home/server.c
	sudo docker exec -it ubuntu_c_server_1 bash -c "cd /home && gcc -o server -pthread server.c && ./server 6060"
delete_server_1:
	sudo docker stop ubuntu_c_server_1
	sudo docker rm ubuntu_c_server_1


start_server_2:
	sudo docker run -d --network aosd --name ubuntu_c_server_2 --ip 172.18.0.4 ubuntu-gcc /bin/sh -c "tail -f /dev/null"
	make modify_server_2
modify_server_2:
	sudo docker cp server.c ubuntu_c_server_2:/home/server.c
	sudo docker exec -it ubuntu_c_server_2 bash -c "cd /home && gcc -o server -pthread server.c && ./server 7070"
delete_server_2:
	sudo docker stop ubuntu_c_server_2
	sudo docker rm ubuntu_c_server_2


start_server_3:
	sudo docker run -d --network aosd --name ubuntu_c_server_3 --ip 172.18.0.5 ubuntu-gcc /bin/sh -c "tail -f /dev/null"
	make modify_server_3
modify_server_3:
	sudo docker cp server.c ubuntu_c_server_3:/home/server.c
	sudo docker exec -it ubuntu_c_server_3 bash -c "cd /home && gcc -o server -pthread server.c && ./server 9090"
delete_server_3:
	sudo docker stop ubuntu_c_server_3
	sudo docker rm ubuntu_c_server_3


start_client:
	sudo docker run -d --network aosd --name ubuntu_c_client --ip 172.18.0.10 ubuntu-gcc /bin/sh -c "tail -f /dev/null"
	make modify_client
modify_client:
	sudo docker cp client.c ubuntu_c_client:/home/client.c
	sudo docker exec -it ubuntu_c_client bash -c "cd /home && gcc -o client client.c && ./client 8080"
delete_client:
	sudo docker stop ubuntu_c_client
	sudo docker rm ubuntu_c_client





delete_all_servers:
	make delete_server_1
	make delete_server_2
	make delete_server_3

full_clean:
	make delete_lb
	make delete_all_servers
	make delete_client
	sudo docker network rm aosd
	sudo docker rmi ubuntu-xdp
	sudo docker rmi ubuntu-gcc

