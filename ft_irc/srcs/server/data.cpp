#include <cstring>
#include <sys/socket.h>

#include "Server.hpp"
#include "Replies.hpp"

#define BUFFER_SIZE 1024

/**
 * @brief Sends a welcome message to a newly registered client.
 *
 * @param server The server object reference.
 * @param client The client pointer to send the welcome message to.
 */
void	Server::_welcome(Server &server, Client *client) const {
	Reply::sendRPL(server, client, RPL::RPL_WELCOME(client->getNickname()), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTDSTART(client->getNickname(), server.getName()), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⢀⣠⣄⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⡾⠿⠿⠿⠿⢷⣶⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⢰⣿⡟⠛⠛⠛⠻⠿⠿⢿⣶⣶⣦⣤⣤⣀⣀⡀⣀⣴⣾⡿⠟⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠻⢿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⡀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠻⣿⣦⡀⠀⠉⠓⠶⢦⣄⣀⠉⠉⠛⠛⠻⠿⠟⠋⠁⠀⠀⠀⣤⡀⠀⠀⢠⠀⠀⠀⣠⠀⠀⠀⠀⠈⠙⠻⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠟⠛⠛⢻⣿"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠈⠻⣿⣦⠀⠀⠀⠀⠈⠙⠻⢷⣶⣤⡀⠀⠀⠀⠀⢀⣀⡀⠀⠙⢷⡀⠸⡇⠀⣰⠇⠀⢀⣀⣀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣤⣶⡶⠶⠶⠒⠂⠀⠀⣠⣾⠟"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠈⢿⣷⡀⠀⠀⠀⠀⠀⠀⠈⢻⣿⡄⣠⣴⣿⣯⣭⣽⣷⣆⠀⠁⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣦⡀⠀⣠⣾⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⣠⣾⡟⠁⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠈⢻⣷⣄⠀⠀⠀⠀⠀⠀⠀⣿⡗⢻⣿⣧⣽⣿⣿⣿⣧⠀⠀⣀⣀⠀⢠⣿⣧⣼⣿⣿⣿⣿⠗⠰⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⠋⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠙⢿⣶⣄⡀⠀⠀⠀⠀⠸⠃⠈⠻⣿⣿⣿⣿⣿⡿⠃⠾⣥⡬⠗⠸⣿⣿⣿⣿⣿⡿⠛⠀⢀⡟⠀⠀⠀⠀⠀⠀⣀⣠⣾⡿⠋⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⣷⣶⣤⣤⣄⣰⣄⠀⠀⠉⠉⠉⠁⠀⢀⣀⣠⣄⣀⡀⠀⠉⠉⠉⠀⠀⢀⣠⣾⣥⣤⣤⣤⣶⣶⡿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢻⣿⠛⢿⣷⣦⣤⣴⣶⣶⣦⣤⣤⣤⣤⣬⣥⡴⠶⠾⠿⠿⠿⠿⠛⢛⣿⣿⣿⣯⡉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣧⡀⠈⠉⠀⠈⠁⣾⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣿⠟⠉⣹⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣸⣿⣿⣦⣀⠀⠀⠀⢻⡀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣿⠋⣿⠛⠃⠀⣈⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡿⢿⡀⠈⢹⡿⠶⣶⣼⡇⠀⢀⣀⣀⣤⣴⣾⠟⠋⣡⣿⡟⠀⢻⣶⠶⣿⣿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣷⡈⢿⣦⣸⠇⢀⡿⠿⠿⡿⠿⠿⣿⠛⠋⠁⠀⣴⠟⣿⣧⡀⠈⢁⣰⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⢻⣦⣈⣽⣀⣾⠃⠀⢸⡇⠀⢸⡇⠀⢀⣠⡾⠋⢰⣿⣿⣿⣿⡿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠿⢿⣿⣿⡟⠛⠃⠀⠀⣾⠀⠀⢸⡇⠐⠿⠋⠀⠀⣿⢻⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠁⢀⡴⠋⠀⣿⠀⠀⢸⠇⠀⠀⠀⠀⠀⠁⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡿⠟⠋⠀⠀⠀⣿⠀⠀⣸⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣁⣀⠀⠀⠀⠀⣿⡀⠀⣿⠀⠀⠀⠀⠀⠀⢀⣈⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_MOTD(client->getNickname(), "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠟⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"), SERVER);
	Reply::sendRPL(server, client, RPL::RPL_ENDOFMOTD(client->getNickname()), SERVER);
}

/**
 * @brief Processes a command received from a client.
 *
 * @param client The client that sent the command.
 */
void	Server::_processClientCommand(Client *client) {
	string	buffer = client->getBuffer();
	size_t	pos;

	while ((pos = buffer.find("\n")) != string::npos) {
		_commands.select(*this, client, buffer.substr(0, (buffer[pos - 1] == '\r' ? pos - 1 : pos)));
		if (client && client->getRegistered() == false) {
			if (client->getGotPasswordRight() && !client->getNickname().empty() && !client->getUsername().empty()) {
				client->setRegistered(true);
				_welcome(*this, client);
			}
		}
		buffer.erase(0, pos + 1);
	}
	client->clearBuffer();
}

/**
 * @brief Receives data from a client and updates the client's buffer.
 *
 * @param clientFd The file descriptor of the client to receive data from.
 *
 * @return true if the client is still connected, false otherwise.
 */
bool	Server::_receiveData(int clientFd) {
	char	buff[BUFFER_SIZE]; bzero(buff, BUFFER_SIZE);
	Client	*client = _clients.getClient(clientFd);
	ssize_t	bytesReceived = recv(clientFd, buff, BUFFER_SIZE - 1, 0);

	if (bytesReceived <= 0) {
		_clients.deleteClient(client);
		return false;
	} else {
		client->addToBuffer(static_cast<string>(buff));
		if (client->getBuffer().find("\n") != string::npos) {
			try {
				_processClientCommand(client);
			} catch (exception &e) {
				_clients.deleteClient(client);
				return false;
			}
		}
	}
	return true;
}
