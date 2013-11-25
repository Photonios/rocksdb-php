#include "includes.h"
#include "rocksdb.h"

extern "C"
{
	PHPCPP_EXPORT void* get_module()
	{
		static Php::Extension rocksdb_extension("RocksDB PHP Extension", "1.0");

		rocksdb_extension.add("RocksDB", Php::Class<RocksDB>(
		{
				Php::Public("__construct", Php::Method<RocksDB>(&RocksDB::__construct)),
				Php::Public("Open", Php::Method<RocksDB>(&RocksDB::Open)),
				Php::Public("GetLastError", Php::Method<RocksDB>(&RocksDB::GetLastError)),
				Php::Public("IsOpen", Php::Method<RocksDB>(&RocksDB::IsOpen)),
				Php::Public("GetDbPath", Php::Method<RocksDB>(&RocksDB::GetDbPath)),
				Php::Public("Get", Php::Method<RocksDB>(&RocksDB::Get)),
				Php::Public("Put", Php::Method<RocksDB>(&RocksDB::Put)),
				Php::Public("Close", Php::Method<RocksDB>(&RocksDB::Close))
		}));

		return rocksdb_extension.module();
	}
}
