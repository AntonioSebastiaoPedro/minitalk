# **Minitalk**

### 42 Project - Minitalk

## **Overview**
The **Minitalk** project is part of the 42 curriculum and focuses on Inter-Process Communication (IPC) using Unix signals. The project involves creating a client-server system where the client sends a string message to the server, and the server receives and prints it. Communication is achieved using **signals** (specifically `SIGUSR1` and `SIGUSR2`), and the message is transmitted one bit at a time.

## **Key Concepts**
- **Unix Logic**
- **Unix Signals** (`SIGUSR1`, `SIGUSR2`)
- **Inter-Process Communication** (IPC)
- **Client-Server Architecture**
- **Bitwise operations** (bit shifting, bit manipulation)
- **Message encoding/decoding using signals**

## **Requirements**
The project must:
- Handle **signal-based communication** between two programs (client and server).
- Support sending and receiving **strings of characters**.
- Use only the **signals** `SIGUSR1` and `SIGUSR2` for communication.
- Ensure that messages are sent **bit-by-bit**.
- Handle **errors** appropriately (e.g., invalid PID).

## **Main Files**
- `server.c`: The server program that waits for signals and reconstructs the message sent by the client.
- `client.c`: The client program that sends a string as a series of signals to the server.
- `minitalk.h`: Header file containing function prototypes and macros.
- `Makefile`: Automates the compilation process for both the client and server.

## **Usage**

### 1. **Clone the repository**
```
git clone https://github.com/AntonioSebastiaoPedro/minitalk.git
cd minitalk
```

### 2. **Compile the project**
You can compile both the client and server using the provided `Makefile`. Run:
```
make
```
This will generate two executables:
- `server`
- `client`

### 3. **Running the server**
To start the server, run the `server` program. It will display its **Process ID (PID)**, which the client needs to send messages.
```
./server
```

Output:
```
PID: 12345
```

### 4. **Sending a message from the client**
Once the server is running and you've noted its PID, you can send a message using the `client` program:
```
./client <pid_server> "Your message here"
```

Example:
```
./client 12345 "Hello from the client!"
```

### 5. **Output**
The server will display the message it received from the client:
```
Hello from the client!
```

### 6. **Cleaning up**
To remove the compiled files, run:
```
make clean
```

To remove compiled files and object files:
```
make fclean
```

To recompile the project after cleaning:
```
make re
```

## **Bonus Features**
The project also includes some optional bonus features:
- **Unicode support**: The client can send and the server can handle messages containing non-ASCII characters.
- **Acknowledgment system**: The server sends an acknowledgment to the client after successfully receiving a message.

## **Error Handling**
- The client handles invalid server PIDs by printing an error message.
- The server prints an error if it encounters problems during message reconstruction.

### 1. **Compile bonus**
To compile the project with the bonus files, run:
```
make bonus
```

To recompile the project with the bonus files after cleaning:
```
make rebonus
```

## **License**
This project is part of the 42 curriculum and is intended for educational purposes.
---
