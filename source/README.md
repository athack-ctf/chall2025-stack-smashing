## Making `server` binary

```
cd build
cmake ..
make
```

## Running `server`

```
cd build
echo "ATHACK{FLAG_VALUE_GOES_HERE}" > flag.txt
./server 2025
```

## Connecting to the server

```
nc 127.0.0.1 2025
```