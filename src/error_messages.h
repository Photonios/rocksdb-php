#ifndef ROCKSDB_ERROR_MESSAGES_H_
#define ROCKSDB_ERROR_MESSAGES_H_

namespace RocksDB
{

namespace ErrorMessages
{
	const std::string InvalidParamExpectedString 	= "Invalid parameter 0, expected string.";
	const std::string AlreadyActiveConnection 		= "There already is an active connection with a database.";
	const std::string NoActiveConnection 			= "There is no active database connection to close.";
	const std::string ExpectedOneParameter 			= "Expected at least one parameter.";
	const std::string ExpectedTwoParamters 			= "Expected at least two parameters.";
}

} // namespace RocksDB

#endif /* ROCKSDB_ERROR_MESSAGES_H_ */
