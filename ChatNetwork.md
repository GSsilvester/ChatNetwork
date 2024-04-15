Welcome and thank you for batting an eye at my ChatNetwork Project.

This is the general structure which I've used developing this project:

The exact steps in which you create a Client - Server communication:

#1) Socket : Create a new communication.
#2) Bind : Attach a local address to a socket.
#3) Listen : Announce willingness to accept connections.
#4) Accept : Block caller until a connection request arrives.
#5) Connect : Actively attempt to establish a connection.
#6) Send : Send some data over a connection.
#7) Receive : Receive some data over a connection.
#8) Close : Release the connection.

Using Instructions:

#1) Using our IDE of choice we will need to navigate in the IDE terminal/ Bash Terminal to the folder in which we have downloaded this project.
#2) We will need to compile it: 
./Server.cpp
./Client.cpp
#3) Rename and run the executables

After this steps the ChatNetwork will be running with a maximum buffer of 1024. 
