#include "rocksdb_php.h"
#include "rocksdb.h"

RocksDB::RocksDB() :
	m_db_path()
{

}

void RocksDB::__construct(Php::Parameters &params)
{
	if(params.empty() || !params[0].isString())
		Php::ThrowError("Invalid parameter 0, expected string.");

	m_db_path = params[0].stringValue();
}

void RocksDB::__destruct()
{

}

Php::Value RocksDB::Open(Php::Parameters &params)
{
	bool create_if_missing = false;

	if(params.empty() || !params[0].isBool())
		create_if_missing = false;
	else
		create_if_missing = params[0].boolValue();

	rocksdb::Options options;
	options.create_if_missing = create_if_missing;

	rocksdb::Status status = rocksdb::DB::Open(options, m_db_path, &m_rdb);

	if(!status.ok())
		return false;

	return true;
}
