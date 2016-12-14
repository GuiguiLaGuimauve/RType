#include "ManageNetwork.hh"

using namespace Network;

int		main(int ac, char **av)
{
	IManageNetwork					*man = new ManageNetwork();
	std::vector<IUserNetwork *>		_users;

	man->run(4242, 10);
	while (1)
	{
		man->init();
		if (man->select_it() == false)
			return (-1);
		_users = man->execServer();
		man->updateUsers(_users);
	}
	return (0);
}