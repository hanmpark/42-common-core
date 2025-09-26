#include "channel/Channel.hpp"

using namespace std;

Channel::Channel() : _modes(NOMODE) {}

Channel::Channel(string const &name) : _name(name), _limit(0), _modes(TOPIC) {}

Channel::~Channel() {}

string	Channel::getName() const { return _name; }

void	Channel::addMode(e_modes mode) { _modes |= mode; }

void	Channel::removeMode(e_modes mode) { _modes &= ~mode; }

void	Channel::removeClient(Client *client) {
	if (_clients.getClient(client->getFd()))
		_clients.removeClient(client);
	if (_operators.getClient(client->getFd()))
		_operators.removeClient(client);
	if (_invited.getClient(client->getFd()))
		_invited.removeClient(client);
}

string	Channel::getTopic() const { return _topic; }

string	Channel::getKey() const { return _key; }

size_t	Channel::getLimit() const { return _limit; }

unsigned int	Channel::getModes() const { return _modes; }

ClientList	&Channel::getClientsList() { return _clients; }

ClientList	&Channel::getOperatorsList() { return _operators; }

ClientList	&Channel::getInvitedList() { return _invited; }

void	Channel::setTopic(string const &topic) { _topic = topic; }

void	Channel::setKey(string const &key) { _key = key; }

void	Channel::setLimit(int limit) { _limit = limit; }
