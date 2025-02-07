// # include "../../Includes/Define.hpp"

// Channel::Channel(Channel &other) 
// {*this = other;}

// Channel &Channel::operator=(Channel &other)
// {
// 	if (this != &other)
// 	{
// 		_name = other._name;
// 		_members = other._members;
// 		_operators = other._operators;
// 		_invited = other._invited;
// 		_userLimit = other._userLimit;
// 	}
// 	return *this;
// }

// Channel::Channel(User &admin, std::string name) : _name(name)
// {
// 	_operators.push_back(&admin); 
// }

// Channel::~Channel(){}

// void Channel::addUser(User* user)
// {
// 	if (!user)
// 		return;
// 	_members.push_back(user);
// }

// void Channel::rmUser(User* user)
// {
// 	if (!user)
// 		return;
// 	std::vector<User*>::iterator it = _members.begin();
// 	for (; it != _members.end(); ++it)
// 	{
// 		if ((*it)->getNickname() == user->getNickname())
// 		{
// 		_members.erase(it);
// 		if (checkOperator(user))
// 			rmOperator(user);
// 		return;
// 		}
// 	}
// }

// bool	Channel::checkUser(User* user) const
// {
// 	if (!user)
// 		return false;
// 	std::string user_nick = user->getNickname();
// 	std::vector<User*>::const_iterator it = _members.begin();
// 	for ( ; it != _members.end(); ++it)
// 	{
// 		if ((*it)->getNickname() == user_nick)
// 			return true;
// 	}
// 	return false;
// }

// bool	Channel::checkEmpty() const
// {
// 	return(_members.empty());
// }

// bool User::checkEqual(const User* other) const
// {
// 	return getId() == other->getId() &&
// 		   getUsername() == other->getUsername() &&
// 		   getHostname() == other->getHostname();
// }

// bool Channel::checkOperator(User *user) const
// {
// 	if (!user)
// 		return false;
// 	for (std::vector<User*>::const_iterator it = _operators.begin(); it != _operators.end(); ++it)
// 	{
// 		if ((*it)->checkEqual(user))
// 			return true;
// 	}
// 	return false;
// }

// void	Channel::addOperator(User* user)
// {
// 	if (!user)
// 		return;
// 	_operators.push_back(user);
// }

// void	Channel::rmOperator(User* user)
// {
// 	for (std::vector<User*>::iterator it = _operators.begin(); it != _operators.end(); ++it)
// 	{
// 		if ((*it)->getNickname() == user->getNickname())
// 		{
// 			_operators.erase(it);
// 			return;
// 		}
// 	}
// }


// bool Channel::checkInvited(User *user) const
// {
// 	if (!user)
// 		return false;

// 	for (std::vector<User*>::const_iterator it = _invited.begin(); it != _invited.end(); ++it)
// 	{
// 		if ((*it)->checkEqual(user))
// 			return true;
// 	}
// 	return false;
// }


// void Channel::addInvited(User* user)
// {_invited.push_back(user);}


// //GET
// std::vector<User*> Channel::getMembers() const {return _members;}
// std::string	Channel::getName() const {return _name;}
// size_t	Channel::getUserLimit() const {return _userLimit;}
// std::string Channel::getMembersNicks()
// {
// 	std::ostringstream oss;
// 	for (std::vector<User*>::iterator it = _members.begin(); it != _members.end(); ++it)
// 	{
// 		if (it != _members.begin()) // Ajouter un espace seulement entre les pseudonymes
// 			oss << " ";
// 		if (checkOperator(*it))
// 			oss << "@";
// 		oss << (*it)->getNickname();
// 	}
// 	return oss.str();
// }

// //SET
// void	Channel::setUserLimit(const std::string set) {_userLimit = stringToSizeT(set);}
