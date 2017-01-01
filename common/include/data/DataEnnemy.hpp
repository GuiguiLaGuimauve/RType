//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAENNEMY_HH__
#define __DATAENNEMY_HH__

#include <string>
#include <stdint.h>
#include "AData.hh"
#include "DataShoot.hpp"

namespace Data {

	class DataEnnemy : public AData {

	public:
		DataEnnemy() {};
		~DataEnnemy() {};
	  virtual void move() {};
	  virtual DataShoot *getShoot() { return (new DataShoot); };
  
	};
};

#endif
