Follow the below sequence to run this code:-

# Main Sequence
## Creating the base images and network and start the packet filter
```
make
```


## Start the server
```
make start_server
```

## Start the client
```
make start_client
```

## Modify the client
```
make modify_client
```

## Delete the 2 containers
```
    make delete_pf
    make delete_client
```

