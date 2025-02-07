#include "../../Includes/Define.hpp"

void User::ping(Message *msg)
{
	std::cout << SGREEN << "~   Ping a été utilisé par l'utilisateur n°" << _id << END << std::endl;

	// Vérifier si des paramètres sont fournis
	if (msg->param.empty())
	{
		ft_reply(409, "", "", "", "");
		return;
	}
}
