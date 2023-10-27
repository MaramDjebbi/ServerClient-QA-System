# Compilateur et drapeaux
CC = gcc
CFLAGS = -Wall

# Fichiers sources et exécutables cibles
CLIENT_SRC = client.c
SERVER_SRC = serveur.c
CLIENT_EXE = client
SERVER_EXE = serveur

# dossier fifo
FIFO_DIR = fifo
$(FIFO_DIR):
	mkdir -p $(FIFO_DIR)
	

all: create_fifo $(CLIENT_EXE) $(SERVER_EXE)


$(CLIENT_EXE): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT_EXE) $(CLIENT_SRC)


$(SERVER_EXE): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER_EXE) $(SERVER_SRC)

.PHONY: clean run create_fifo

run_server: $(SERVER_EXE) 
	#gnome-terminal -e ./$(SERVER_EXE) 
	#gnome-terminal -e ./$(CLIENT_EXE) 
	gnome-terminal -- $(SHELL) -c "./serveur; exec $SHELL"
run_client:$(CLIENT_EXE)
	gnome-terminal -- $(SHELL) -c "./client && sleep 5; exec $SHELL"


# Creation du dossier fifo
create_fifo: $(FIFO_DIR)


clean:
	rm -f $(CLIENT_EXE) $(SERVER_EXE)
	rm -r fifo/

