#include "../../Includes/Channel.hpp"

void	Channel::addUser(User *u){
	if (!u)
		throw (ERR_NO_USER);
	if (findInUserList(u) == 1){
		return ;
	}
	_userList.push_back(u);
	std::cout << GRED << u->getId()  << u->getUsername()<< END << std::endl;
	_nbUser++;
}

void	Channel::addOperator(int id){
	if (findInOperatorList(id) != -1)
		return ;
	_operatorList.push_back(id);
}

int	Channel::findInUserList(User *u) const { //renvoie -1 si faux
	if (!u)
		throw (ERR_NO_USER);
	if (_userList.size() == 0)
		return (0);
	for (long unsigned int i = 0; i < _userList.size(); i++)
	{
		if (_userList[i]->getId() == u->getId())
		{
			return (1);
		}
	}
	// throw std::invalid_argument("User not found");
	return (0);
}

int	Channel::findInOperatorList(int id) const { //renvoie -1 si faux
	for (long unsigned int i = 0; i < _operatorList.size(); i++)
	{
		if (_operatorList[i] == id)
		{
			return (i);
		}
	}
	// throw std::invalid_argument("User not found");
	return (-1);
}

void	Channel::removeUser(int id){ //supprime UN user de la liste
	for (size_t i = 0; i < _nbUser; i++)
	{
		if (_userList[i]->getId() == id)
		{
			std::cout << "ON EJECTE QLQ " << std::endl;
			_userList.erase(_userList.begin() + i);
			return ;
		}
	}
	_nbUser--;
}

void	Channel::removeOperator(int id){ //supprime UN operator de la liste
	for (size_t i = 0; i < _nbUser; i++)
	{
		if (_operatorList[i] == id)
		{
			_operatorList.erase(_operatorList.begin() + i);
			return ;
		}
	}
}

void	Channel::printChannelUsers(){
	for (size_t i = 0 ; i < _nbUser ; i++)
	{
		std::cout << _userList[i] << std::endl; // Necessite la fct ostream de user
	}
}

bool	Channel::checkOperator(User *u) const {
	if (!u)
		throw (ERR_NO_USER);
	for (size_t i = 0 ; i < _operatorList.size() ; i++)
	{
		if (_operatorList[i] == u->getId())
			return (true);
	}
	return (false);
}

bool	Channel::checkUser(User *u) const
{
	if (!u)
		throw (ERR_NO_USER);
	int id = u->getId();
	std::vector<User*>::const_iterator it = _userList.begin();
	for ( ; it != _userList.end(); ++it)
	{
		if ((*it)->getId() == id)
			return (true);
	}
	return (false);
}

bool	Channel::checkEmpty() const
{
	return(_userList.empty());
}

bool User::checkEqual(const User* other) const
{
	if (!other)
		throw (ERR_NO_USER);
	return getId() == other->getId() &&
		   getUsername() == other->getUsername() &&
		   getHostname() == other->getHostname();
}


// Invite

void	Channel::addWhitelist(int id){
	_whiteList.push_back(id);
}

void	Channel::addAllUsersToWhiteList(){
	for (size_t i = 0; i < _nbUser ; i++)
	{
		if (!_userList[i])
			return ;
		addWhitelist(_userList[i]->getId());
	}
}

void	Channel::removeWhitelist(int id){
	for (long unsigned int i = 0; i < _whiteList.size(); i++)
	{
		if (_whiteList[i] == id)
		{
			_whiteList.erase(_whiteList.begin() + i);
			return ;
		}
	}
	// throw std::invalid_argument("User not found");
}

int	Channel::findInWhiteList(int id) const { //renvoie -1 si faux
		for (long unsigned int i = 0; i < _whiteList.size(); i++)
	{
		if (_whiteList[i] == id)
		{
			return (i);
		}
	}
	// throw std::invalid_argument("User not found");
	return (-1);
}

void	Channel::printWhiteList(){
	if (_whiteList.size() == 0)
		std::cout << "No one in WhiteList" << std::endl;
	else
	{
		std::cout << BLUE << "Users in the WhiteList :" << std::endl;
		for (size_t i = 0 ; i < _whiteList.size() ; i++)
		{
			std::cout << BLUE << "User[" << i << "]=" << _whiteList[i] << std::endl;
		}
	}
}

void	Channel::eraseWhiteList(){
	std::vector<int>().swap(_whiteList); //vide la whitelist et libere la memoire
}

// Private

int	Channel::comparePassword(std::string password) const {
	if (password == _password)
		return (1);
	return (0);
}



