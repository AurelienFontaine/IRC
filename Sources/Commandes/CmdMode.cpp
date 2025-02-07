#include "../../Includes/Define.hpp"

void	User::cmdPvtMsg(User *u, std::string name, std::string msg){
	const std::string &targetName = name;
    std::string message = formatUser() + "PRIVMSG " + targetName + " :" + msg + LAST_CHAR;
	userMsg(message, u);
}

void    User::modeTiret(Message *msg)
{
    std::cout << SRED << "~   Mode a été utilisé par l'utilisateur n°" << _id << END << std::endl;
    Channel            *this_channel = _serv->getChannel((msg->param[0]));
    // std::string     ch_name = this_channel->getName();
	size_t size = msg->param.size();
	if (size >= 2 && size < 4)
	{

		std::string print; // a retirer avec le for
		for (size_t i = 0; i < size ; i++)
		{
			print = msg->param[i];
			std::cout << PURPLE << print << std::endl;
		}
		if (!this_channel->checkOperator(this))
			return (ft_reply(482, this_channel->getName(), "", "", ""));
		std::string     stringTiret = msg->param[1];
		std::cout << SGREEN << stringTiret << std::endl;
		// if (this_channel->checkOperator(this))
		//     return (ft_reply(482, ch_name, "", "", ""));
		if (stringTiret == "-t" && this_channel->getTopicOperator() == 1)
		{
			this_channel->setTopicOperator(!this_channel->getTopicOperator());
			std::string send;
			if (this_channel->getTopicOperator() == 1)
				send = "Topic successfully set for Operators only.";
			else
				send = "Topic successfully set for all.";
			cmdPvtMsg(this, msg->param[0], send);
		}
		else if (msg->param[1] == "-k")
		{
		    if (this_channel->getPrivateStatus() == false && size == 3)
			{
				std::string pwd = msg->param[2];
				this_channel->setPrivate(true);
				this_channel->setPassword(pwd);
				std::string send = "Channel successfully set to Private.";
				cmdPvtMsg(this, msg->param[0], send);
			}
			else if (this_channel->getPrivateStatus() == true)
			{
				this_channel->setPrivate(false);
				std::string send = "Channel no longer in Private.";
				cmdPvtMsg(this, msg->param[0], send);
			}
			else
				cmdPvtMsg(this, msg->param[0], ERR_INPUT_CMD);
		}
		else if (msg->param[1] == "-o")
		{
			if (size == 2)
			{
				if (msg->param[1].length() == 2)
					return (ft_reply(461, msg->command, "", "", ""));
			}
            if (size == 3)
            {
                User *user = _serv->getUser(msg->param[2]);
				if (!user)
				{
					ft_reply(441, msg->param[1], this_channel->getName(), "", "");
					cmdPvtMsg(this, msg->param[0], ERR_BAD_ARG);
					return ;
				}
                if (this_channel->findInOperatorList(user->getId()) == -1)
				{
                    this_channel->addOperator(user->getId());
					std::string send = "User : " + user->getNickname() + " successfully added to Operators.";
					cmdPvtMsg(this, msg->param[0], send);
				}
                else
				{
                    this_channel->removeOperator(user->getId());            
					std::string send = "User : " + user->getNickname() + " successfully removed from Operators.";
					cmdPvtMsg(this, msg->param[0], send);
				}
			}
		}
		else if (msg->param[1][0] == '-' && msg->param[1][1] == 'l')
		{
			if (msg->param[1].length() == 2)
				return (ft_reply(461, msg->command, "", "", ""));
			if (msg->param[1].length() > 2)
			{
				std::string str = msg->param[1].substr(2);
				for (size_t i = 0; i < str.length() ; i++)
				{
					if (isdigit(str[i]) == 0)
					{
						cmdPvtMsg(this, msg->param[0], ERR_BAD_ARG);
						return ;
					}
				}
				if (size == 2)
				{
					size_t limitUser = stringToSizeT(str);
					if (limitUser < this_channel->getNbUser() || limitUser > ALLOWED_CONNECTIONS || limitUser > 50 || limitUser <= 0)
					{
						cmdPvtMsg(this, msg->param[0], ERR_BAD_ARG);
					}
					else
					{
						std::string send = "User limit successfully set to : " + str;
						cmdPvtMsg(this, msg->param[0], send);
					}
				}
			}
		}
		else if (msg->param[1] == "-i")
		{
			if (size == 2)
			{
				if (this_channel->getInviteStatus() == false)
				{
					this_channel->setInvite(true);
					this_channel->addAllUsersToWhiteList();
					this_channel->printWhiteList();
					std::string send = "Channel successfully set to Invite only.";
					cmdPvtMsg(this, msg->param[0], send);
					
				}
				else
				{
					this_channel->setInvite(false);
					this_channel->eraseWhiteList();
					std::string send = "Channel no longer in Invite only.";
					cmdPvtMsg(this, msg->param[0], send);
				}
			}
		}
		else
		{
			ft_reply(472, msg->param[1], "", "", "");
			std::string send = ERR_BAD_CMD;
			cmdPvtMsg(this, msg->param[0], send);
		}
	}
}

void User::mode(Message *msg)
{
    if (msg->param[0].at(0) == '#')
    {
		modeTiret(msg);
    }
}
