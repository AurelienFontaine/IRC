// #ifndef CHANNEL_HPP
// # define CHANNEL_HPP

// # include "Define.hpp"

// class User;

// class Channel
// {
// 	private:
// 		std::string			_name;
// 		size_t 				_userLimit;
// 		std::vector<User*> _members;
// 		std::vector<User*> _invited;
// 		std::vector<User*> _operators;

// 	public:
// 		Channel(User &admin, std::string name);
// 		Channel(Channel &other);
// 		Channel &operator=(Channel &other);
// 		~Channel();

// 		void	addUser(User *user);
// 		void	rmUser(User *user);
// 		bool	checkUser(User *user) const;
// 		bool	checkEmpty() const;
// 		bool	checkOperator(User *user) const;
// 		void	addOperator(User* user);
// 		void	rmOperator(User* user);
// 		bool	checkInvited(User *user) const;
// 		void	addInvited(User* user);

// 		void	setUserLimit(std::string set);

// 		size_t				getUserLimit() const;
// 		std::string			getName() const;
// 		std::string			getMembersNicks();
// 		std::vector<User*>	getMembers() const;

// };

// std::ostream	&operator<<(std::ostream &flux, Channel const &rhs );

// #endif