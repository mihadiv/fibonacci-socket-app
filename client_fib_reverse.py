import socket  # module for TCP/IP socket communication

# Network settings
HOST = '37.120.249.45'
PORT = 8822 

# Ask the user for a number
n = input("Enter a number (n) to get reversed Fibonacci: ")

# Create a TCP socket and connect to the server
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))       # establish the connection
    s.sendall(n.encode())         # send n as a string
    data = s.recv(1024).decode()  # receive the response from the server

# Display the result
print("\n[CLIENT] Received from server s_fib_inv - by Divoiu Mihaela gr1088:")
print(data)
