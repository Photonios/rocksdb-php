#include "includes.h"
#include "database.h"

extern "C"
{
	PHPCPP_EXPORT void* get_module()
	{
		static Php::Extension rocksdb_extension("RocksDB PHP Extension", "1.0");

		rocksdb_extension.add("RocksDB", Php::Class<RocksDB::Database>(
		{
				Php::Public("__construct", Php::Method<RocksDB::Database>(&RocksDB::Database::__construct)),
				Php::Public("Open", Php::Method<RocksDB::Database>(&RocksDB::Database::Open)),
				Php::Public("GetLastError", Php::Method<RocksDB::Database>(&RocksDB::Database::GetLastError)),
				Php::Public("IsOpen", Php::Method<RocksDB::Database>(&RocksDB::Database::IsOpen)),
				Php::Public("GetDbPath", Php::Method<RocksDB::Database>(&RocksDB::Database::GetDbPath)),
				Php::Public("Get", Php::Method<RocksDB::Database>(&RocksDB::Database::Get)),
				Php::Public("Put", Php::Method<RocksDB::Database>(&RocksDB::Database::Put)),
				Php::Public("Close", Php::Method<RocksDB::Database>(&RocksDB::Database::Close))
		}));

		return rocksdb_extension.module();
	}
}
