#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <stdint.h>
# include "Data.hpp"

class Serializer {

  private:
	Serializer(void);
	~Serializer(void);
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

};

#endif