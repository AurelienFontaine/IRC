#include "../../Includes/Define.hpp"

void			User::invite(Message *msg)
{
	std::cout << SGREEN << "~   Invite a été utilisé par l'utilisateur n°" << _id << END << std::endl;
	if (msg->param.size() < 2)
		return (ft_reply(461, msg->command, "", "", ""));
	Channel		*channel = _serv->getChannel((msg->param[1]));
    std::cout << GRED << channel << END << std::endl;
	if (channel == NULL)
		return (ft_reply(403, msg->param[1], "", "", ""));
	
	std::string ch_name = channel->getName();

	User		*to_invite = _serv->getUser((msg->param[0]));
	if (to_invite == NULL)
		return (ft_reply(401, msg->param[0], "", "", ""));
	if (!channel->checkUser(this))
		return (ft_reply(442, ch_name, "", "", ""));
	else if (channel->checkUser(to_invite))
		return (ft_reply(443, msg->param[0], ch_name, "", ""));
	else if (!channel->checkOperator(this))
		return (ft_reply(482, ch_name, "", "", ""));
	else
    {
        std::string message = formatUser();
        message.append("INVITE "  + msg->param[0] + " " + ch_name + LAST_CHAR);
        userMsg(message, to_invite);
        std::cout << GYELLOW << "msg :" << message << std::endl;
        std::cout << GBLUE << "channel :" << msg->param[1] << std::endl;
        std::cout << GRED << "User : " << msg->param[0] << std::endl;
        ft_reply(341, msg->param[0], msg->param[1], "", "");
		_serv->addUserToChannel(to_invite, ch_name);
		if (channel->findInWhiteList(to_invite->getId()) == -1)
		{
			channel->addWhitelist(to_invite->getId());
		}
	}
	channel->printWhiteList();
}
	// else
	// {
	// 	std::string part_msg;
	// 	if (msg->param.size() == 2)
	// 		part_msg = "has been invited";
	// 	else
	// 		part_msg = msg->param[2];
	// 	std::string message = formatUser();
	// 	message.append("Invite " + ch_name + " " + msg->param[1] + " :" + part_msg + LAST_CHAR);
	// 	channelMsg(message, channel);
	// 	sendMsg(message);