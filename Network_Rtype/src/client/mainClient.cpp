#include "ManageNetwork.hh"

using namespace Network;

int		main(int ac, char **av)
{
	IManageNetwork					*man = new ManageNetwork();
	std::vector<IUserNetwork *>		_users;
	int								i = 0;

	man->run();
	man->tryConnectClient(4243, "127.0.0.1");
	while (i < 3)
	{
		std::cout << "Tour " << i << std::endl;
		if (i == 0)
			man->pushToServ("Bonjour je suis un client!");
		if (i == 1)
			man->pushToServ("Ceci est mon deuxieme message!");
		man->init();
		if (man->select_it() == false)
			return (-1);
		_users = man->execClient();
		man->updateUsers(_users);
		i++;
	}
	return (0);
}