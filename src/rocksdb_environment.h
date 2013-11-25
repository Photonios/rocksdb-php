#include "includes.h"

#ifndef ROCKSDB_ENVIRONMENT_H_
#define ROCKSDB_ENVIRONMENT_H_

/*!
 * \brief Implements the 'Php::Environment' class, allows access to the environment,
 * 		  and thus allows us to set global variables/constants.
 * \author Swen Kooij
 */
class RocksDBEnvironment : public Php::Environment
{
};

#endif /* ROCKSDB_ENVIRONMENT_H_ */
