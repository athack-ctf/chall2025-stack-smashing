# How to build/run/connect to the challenge?

## IMPORTANT
- If you modify/rebuild the `server` binary, make sure to test/update the solution as well as the offline artifacts.

## Making `server` binary

```
cd build
cmake ..
make
# copying new binary to ./chall
cd ..
cp ./build/server ./chall/server
```

## Running `server`

```
cd build
./server 2025
```

## Connecting to the server

```
nc 127.0.0.1 2025
```

## Running `server` within the container

```
docker compose up -d --build
```
