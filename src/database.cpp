#include "includes.h"
#include "database.h"
#include "error_messages.h"

namespace RocksDB
{

Database::Database() :
	m_db_path		(),
	m_rdb	 		(NULL),
	m_last_error	(),
	m_is_open		(false)
{

}

void Database::__construct(Php::Parameters &params)
{
	if(params.empty() || !params[0].isString())
		Php::ThrowError(ErrorMessages::InvalidParamExpectedString);

	m_db_path = params[0].stringValue();
}

void Database::__destruct()
{
	Close();
}

Php::Value Database::Open(Php::Parameters &params)
{
	if(IsOpen())
	{
		m_last_error = ErrorMessages::AlreadyActiveConnection;
		return false;
	}

	bool create_if_missing = false;

	if(params.empty() || !params[0].isBool())
		create_if_missing = false;
	else
		create_if_missing = params[0].boolValue();

	rocksdb::Options options;
	options.create_if_missing = create_if_missing;

	rocksdb::Status status = rocksdb::DB::Open(options, m_db_path, &m_rdb);

	if(!status.ok())
	{
		m_last_error = status.ToString();
		m_is_open = false;
		return false;
	}

	m_is_open = true;

	return true;
}

Php::Value Database::GetLastError()
{
	return m_last_error;
}

Php::Value Database::IsOpen()
{
	if(m_rdb == NULL)
		return false;

	return m_is_open;
}

Php::Value Database::GetDbPath()
{
	return m_db_path;
}

Php::Value Database::Close()
{
	if(m_rdb == NULL)
	{
		m_last_error = ErrorMessages::NoActiveConnection;
		return false;
	}

	delete m_rdb;
	return true;
}

Php::Value Database::Get(Php::Parameters &params)
{
	if(params.empty())
			Php::ThrowError(ErrorMessages::ExpectedOneParameter);

	if(!IsOpen())
	{
		m_last_error = ErrorMessages::NoActiveConnection;
		return false;
	}

	std::string key = params[0].stringValue();
	std::string value;

	rocksdb::Status status = m_rdb->Get(rocksdb::ReadOptions(), key, &value);

	if(!status.ok())
	{
		m_last_error = status.ToString();
		return false;
	}

	return value;
}

Php::Value Database::Put(Php::Parameters &params)
{
	if(params.empty() || params.size() < 2)
		Php::ThrowError(ErrorMessages::ExpectedTwoParamters);

	if(!IsOpen())
	{
		m_last_error = ErrorMessages::NoActiveConnection;
		return false;
	}

	std::string key = params[0].stringValue();
	std::string value = params[1].stringValue();

	m_rdb->Put(rocksdb::WriteOptions(), key, value);

	return true;
}

} // namespace RocksDB
