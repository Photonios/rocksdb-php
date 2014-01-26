#ifndef ROCKSDB_ENVIRONMENT_H_
#define ROCKSDB_ENVIRONMENT_H_

namespace RocksDB
{

/*!
 * \brief Implements the 'Php::Environment' class, allows access to the environment,
 * 		  and thus allows us to set global variables/constants.
 * \author Swen Kooij
 */
class Environment : public Php::Environment
{
};

} // namespace RocksDB

#endif /* ROCKSDB_ENVIRONMENT_H_ */
