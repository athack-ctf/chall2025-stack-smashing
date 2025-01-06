# How to build/run/connect to the challenge?

## IMPORTANT
- If you modify/rebuild the `server` binary, make sure to test/update the solution as well as the offline artifacts.

## Compiling `server` binary

```
cd ./build
cmake ..
make
# copying new binary to ./chall
cd ..
cp ./build/server ./chall/server
```

## Running locally

```
cd build
./server 2025

# In another terminal, very connection to TCP socket
nc 127.0.0.1 2025
```

## Running using docker compose

```
docker compose up -d --build

# Get ip of the running container (replace <container_id> with concreate value)
docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' <container_id>

# Verify connection to the TCP socket (replace ip with the obtained ip address)
nc <ip> 2025
```