#include "../../Includes/Define.hpp"

void    User::user(Message *msg)
{
	std::cout << SGREEN << "~   User a été utilisé par l'utilisateur n°" << _id << END << std::endl;
	std::string user = "USER";

	if (_register.okUser)
		return (ft_reply(462, "", "", "", ""));
	if (msg->param.size() < 4)
		return (ft_reply(461, msg->command, "", "", ""));

	_userName = msg->param[0];

	(void) msg->param[1];
	_hostName = _ip;
	_hostName += ".chezMoi.fr";

	(void) msg->param[2];

	_realName = msg->param[3];
	addCommandToRegister(user);
}

void User::leaveChannel()
{
	// Copie locale des canaux pour éviter les problèmes d'invalidation d'itérateurs
	std::vector<Channel *> channelsToLeave = _joinedChannels;

	// Parcours de la liste copiée
	for (std::vector<Channel *>::iterator it = channelsToLeave.begin(); it != channelsToLeave.end(); ++it)
	{
		// Suppression du user de chaque canal
		_serv->rmUserFromChannel(this, (*it)->getName());
	}
}