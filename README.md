# 🧮 Fibonacci Socket App

This project demonstrates TCP client-server communication using both **C** and **Python**. A client sends an integer `n` to the server, which responds with a computed Fibonacci sequence—either in normal order (with sum) or reversed, depending on the implementation.

## 📌 Overview

The application includes two parallel implementations:

- **C Implementation**
  - `server_fib_sum.c`: Computes the first `n` Fibonacci numbers and their total sum.
  - `client_fib_sum.c`: Sends `n` to the server and displays the sequence and its sum.

- **Python Implementation**
  - `server_fib_reverse.py`: Computes the first `n` Fibonacci numbers and returns them in reverse order.
  - `client_fib_reverse.py`: Sends `n` to the server and displays the reversed sequence.

All communication is performed over TCP using port `8822`.

## 🗂️ File Structure

| File                    | Description                                |
|-------------------------|--------------------------------------------|
| `server_fib_sum.c`      | C server – Fibonacci sequence with sum     |
| `client_fib_sum.c`      | C client                                   |
| `server_fib_reverse.py` | Python server – reversed Fibonacci sequence|
| `client_fib_reverse.py` | Python client                              |
| `project_report_ro.pdf` | Project documentation (in Romanian)        |

## 🚀 How to Run

### ✅ C Version

```bash
gcc server_fib_sum.c -o server
./server
```

```bash
gcc client_fib_sum.c -o client
./client
```

### 🐍 Python Version

```bash
python3 server_fib_reverse.py
```

```bash
python3 client_fib_reverse.py
```

## 💡 Notes

- All files use TCP sockets.
- Both servers listen on IP `37.120.249.45`, port `8822`.
- Make sure the server is running before starting the client.

 
