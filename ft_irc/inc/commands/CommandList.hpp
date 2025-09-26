#pragma once

# include <iostream>
# include <map>
# include <vector>

using namespace std;

class Server;
class ACommand;
class Client;

class CommandList {
private:
	map<string, ACommand*>	_commands;

	typedef map<string, ACommand*>::const_iterator	commandIt;

	vector<string>	_split(string const &buffer) const;

public:
	CommandList();
	~CommandList();

	ACommand	*getCommand(string const &command) const;
	void		select(Server &server, Client *client, string const &buffer) const;
};
