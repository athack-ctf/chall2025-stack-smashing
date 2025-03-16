# Running This Challenge

## Locally

```
cd build
./server 52030

# In another terminal, verify connection to TCP socket
nc 127.0.0.1 52030
```

## Using docker

Build
```
docker compose up -d --build
```

Run
```
docker run -d --name stack-smashing \
  -p 52030:2025 \
  athack-ctf/chall2025-stack-smashing:latest
```

Verify connection to the TCP socket (if the container is running remotely, use the right ip and port)
```
nc 127.0.0.1 52030
```

## Compiling `server` binary

**IMPORTANT**: If you modify/rebuild the `server` binary, make sure to test/update the solution as well as the offline artifacts.
```
cd ./build
cmake ..
make
# copying new binary to ./chall
cd ..
cp ./build/server ./chall/server
```

