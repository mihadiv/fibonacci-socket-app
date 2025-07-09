import socket  # module for socket communication

# Function that generates the first n terms of the Fibonacci sequence
def fibonacci(n):
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    seq = [0, 1]
    for _ in range(2, n):
        seq.append(seq[-1] + seq[-2])  # each term is the sum of the previous two
    return seq

# Network settings
HOST = '37.120.249.45'  
PORT = 8822            

# Create TCP socket
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind((HOST, PORT))  # bind socket to IP and port
    server_socket.listen(1)  # server waits for a connection
    print(f"\n[SERVER] Listening on {HOST}:{PORT}")

    conn, addr = server_socket.accept()  # accept client connection
    with conn:
        print(f"[SERVER] Connected by {addr}")
        data = conn.recv(1024).decode()  # receive data (n) sent by the client

        if data.isdigit():
            n = int(data)
            fib_seq = fibonacci(n)  # compute Fibonacci sequence
            reversed_seq = list(reversed(fib_seq))  # reverse the list
            response = ', '.join(map(str, reversed_seq))  # format as text

            response = f"The reversed Fibonacci sequence with {n} element(s) is: "
            response += ', '.join(map(str, reversed_seq))
        else:
            response = "Invalid input. Please send a number."

        conn.sendall(response.encode())  # send result to client
        print(f"[SERVER] Sent to client c_fib_inv - by Divoiu Mihaela gr1088:\n{response}")
