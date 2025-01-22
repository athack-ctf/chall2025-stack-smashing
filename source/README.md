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

# In another terminal, verify connection to TCP socket
nc 127.0.0.1 2025
```

## Running using docker compose

```
docker compose up -d --build

# Verify connection to the TCP socket (if the container is running remotely, use the right ip and port)
nc 127.0.0.1 2025
```
