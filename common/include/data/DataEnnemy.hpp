//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAENNEMY_HH__
#define __DATAENNEMY_HH__

#include <string>
#include <stdint.h>
#include <vector>
#include <utility>
#include "AData.hh"
#include "DataShoot.hpp"

namespace Data {

	class DataEnnemy : public AData {

	public:
	  DataEnnemy() : AData() {_health = 100; _patternPos = 0; };
	  ~DataEnnemy() {};
	  virtual void move()
	  {
	    _x += _pattern[_patternPos].first;
	    _y += _pattern[_patternPos].second;
	    _patternPos++;
	    if (_patternPos >= _pattern.size())
	      _patternPos = 0;
	  };
	  virtual std::vector<DataShoot *> getShoot() {
			std::vector<DataShoot *> tmp;
			return (tmp); 
	  };
	  virtual bool isBoss() const { return (false); };
	  virtual DataEnnemy *getNewEnnemy() { return (new DataEnnemy); }
	protected:
	  std::vector<std::pair<int8_t, int8_t> > _pattern; 
	  uint64_t                              _patternPos;
	};
};

#endif
