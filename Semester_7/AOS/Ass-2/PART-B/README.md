Follow the below sequence to run:-

# Main Sequence
## Creating the base images and network
```
make
```

## Start the load balancer
``` 
make start_lb 
```

## Start the 3 servers
run each in a new tab
```
make start_server_1
make start_server_2
make start_server_3
```

## Start the client
```
make start_client
```


## Delete everything
```
make full_clean
```

<br><br>

# Miscellaneous Commands

## Modify individually
```
make modify_lb
make modify_server_1
make modify_server_2
make modify_server_3
make modify_client
```

## Delete individually
```
make delete_lb
make delete_server_1
make delete_server_2
make delete_server_3
make delete_client
```
## Create network
```
make create_network
```

