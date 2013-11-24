#include "rocksdb_php.h"
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
		}));

		return rocksdb_extension.module();
	}
}
