#ifndef DEFINE_HPP
#define DEFINE_HPP

//COLORS
//Gras
#define GRED "\033[1;31m"
#define GBLUE "\033[1;36m"
#define GGREEN "\033[1;32m"
#define GYELLOW "\033[1;33m"
#define GPURPLE "\033[1;35m"
//Simple
#define RED "\033[0;31m"
#define BLUE "\033[0;36m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define END "\033[0;39m"
//Souligner
#define SRED "\033[4;31m"
#define SBLUE "\033[4;36m"
#define SGREEN "\033[4;32m"
#define SYELLOW "\033[4;33m"
#define SPURPLE "\033[4;35m"
#define SEND "\033[4;39m"

//Header
# include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <algorithm>
#include <cstdarg>
#include <cstring>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "Server.hpp"
#include "User.hpp"
#include "Utils.hpp"
#include "Channel.hpp"

#define RESTORE_TIME 1
#define ALLOWED_CONNECTIONS 20
#define MAX_BUFFER 1024
#define NB_COMDS 11
#define T_SHUTDOWN 300
#define LAST_CHAR "\r\n"
#define OK_CHAR "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890!_-+=@"

/*ERRORS*/
#define ERR_INPUT "\033[1;31m Use : ./ircserv <port> <password>"
#define ERR_PORT "\033[1;31mPort must be between 6665-6669>"
#define ERR_INPUT_CMD "\033[1;31mWrong number of args to use the command"
#define ERR_BAD_ARG "\033[1;31mArgument not allowed"
#define ERR_BAD_CMD "\033[1;31mCommand not found"
// Choix des ports -> https://fr.wikipedia.org/wiki/Internet_Relay_Chat
//SOCKETS
#define ERR_CREATE "\033[1;31mFailed to create socket"
#define ERR_BIND "\033[1;31mFailed to bind socket"
#define ERR_OPT "\033[1;31mFailed to set socket options"
#define ERR_LISTEN "\033[1;31mFailed to listen to socket"
//LOOP
#define ERR_SELECT "\033[1;31mFailed to select"
//USER
#define ERR_U_MEMORY "\033[1;31mFailed to add new user, not enough memory"
#define ERR_ACCEPT 1"\033[;31mFailed to accept"
#define ERR_RECV "\033[1;31mFailed to recv"
#define ERR_SEND "\033[1;31mFailed to send"
//CHANNEL
#define ERR_NO_USER "\033[1;31mNo user found"
//COMMANDES
#define NICK_VALID_CHAR "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-~"
//UTILS
#define ERR_CONVERT_ST "Failed to convert to size_t"



//IRSSI_CODE
// RPL001
#define RPL_WELCOME(nick, user, host) (":Welcome to the Internet Relay Network " \
			+ nick + "!" + user + "@" + host)
// RPL002
#define RPL_YOURHOST(servername, ver) (":Your host is " + servername + ", running version " + ver)
// RPL003
#define RPL_CREATED(_startTime) (":This server was created " + _startTime)
// RPL004
#define RPL_MYINFO(servername, version, channelModes, userModes) (":" + servername + \
				" " + version + " " + channelModes + " " + userModes)
// ERR461
#define ERR_NEEDMOREPARAMS(command) (command + " :Not enough parameters")

// ERR462
#define ERR_ALREADYREGISTERED "462 :Unauthorized command (already registered)"
// ERR464
#define ERR_PASSWDMISMATCH	"* :Password incorrect"

// NICK COMMAND
// ERR431
#define ERR_NONICKNAMEGIVEN ":No nickname given" //431
// - Returned when a nickname parameter expected for a command and isn't found.

// ERR432
#define ERR_ERRONEUSNICKNAME(nick) (nick + " :Erroneous nickname") //432
//          - Returned after receiving a NICK message which contains
//            characters which do not fall in the defined set.  See
//            section 2.3.1 for details on valid nicknames.

// ERR433
#define ERR_NICKNAMEINUSE(arg1) (arg1 + " :Nickname is already in use") //433
//          - Returned when a NICK message is processed that results
//            in an attempt to change to a currently existing
//            nickname..
//  [ server : 6667 ] :*.freenode.net 433 * epresa-c :Nickname is already in use.

//JOIN
// RPL353
#define RPL_NAMREPLY(channel, nick) "= " + channel + " :" + nick
// = #lol :@Guest36096 mikeWpit
//"( "=" / "*" / "@" ) <channel>
//:[ "@" / "+" ] <nick> *( " " [ "@" / "+" ] <nick> )

//- "@" is used for secret channels, "*" for private channels,
//  and "=" for others (public channels).

// RPL366
#define RPL_ENDOFNAMES(channel) channel + " :End of NAMES list"

// PART
// 403
#define ERR_NOSUCHCHANNEL(channel_name) (channel_name + " :No such channel")

// ERR442
#define ERR_NOTONCHANNEL(channel) (channel + " :You're not on that channel")
// - Returned by the server whenever a user tries to perform a
// channel affecting command for which the user isn't a member.

// KICK
// ERR476
#define ERR_BADCHANMASK(channel) (channel+ " :Bad Channel Mask")

//ERR482
#define ERR_CHANOPRIVSNEEDED(channel) (channel + " :You're not channel operator")
// - Any command requiring 'chanop' privileges (such as MODE messages)
// MUST return this error if the user making the attempt is not a
// chanop on the specified channel.

// ERR441
#define ERR_USERNOTINCHANNEL(nick, channel) (nick + " " + channel + " :They aren't on that channel")
// - Returned by the server to indicate that the target
// user of the command is not on the given channel.

// PING PONG
// ERR409
#define ERR_NOORIGIN " :No origin specified"
// ERR402
#define ERR_NOSUCHSERVER(server) (server + " :No such server")

//PRIVMSG
// ERR411
#define ERR_NORECIPIENT(command) (":No recipient given (" + command + ")")
// ERR412
#define ERR_NOTEXTTOSEND ":No text to send"
// ERR404
#define ERR_CANNOTSENDTOCHAN(channel_name) (channel_name + " :Cannot send to channel")

//INVITE
// ERR443
#define ERR_USERONCHANNEL(user, channel) (user + " " + channel + " :is already on channel")

// RPL341
#define RPL_INVITING(invited, channel) (invited + " :" + channel)


// ERR473
#define ERR_INVITEONLYCHAN(channel) (channel + " :Cannot join channel (+i)")

// RPL322
#define RPL_LIST(channel, total_users , modes, topic) (channel + " " + total_users + " :[" + modes + "] " + topic)
// RPL323
#define RPL_LISTEND ":End of LIST"

//RPL 405
#define ERR_TOOMANYCHANNELS(channel) (channel + " :You have joined to many channels")

// ERR471
#define ERR_CHANNELISFULL(channel) (channel + " :Cannot join channel (+l)")
// RPL351
#define ERR_NOTREGISTERED(command, notregistered) (command + " :" + notregistered)

//TOPIC 
//RPL331
#define RPL_NOTOPIC(topic) (topic + " No topic is set")
//RPL332
#define RPL_TOPIC(channel, topic) (channel + " :" + topic)

//MODE
//472
#define ERR_UNKNOWNMODE(char) (char + " :" + "Given Mode unknown") 

// ERR475
#define ERR_BADCHANNELKEY(channel) (channel + " :Cannot join channel (+k)")

#endif