#include <phpcpp/phpcpp.h>

extern "C"
{
	PHPCPP_EXPORT void* get_module()
	{
		static Php::Extension rocksdb_extension("RocksDB PHP Extension", "1.0");
		return rocksdb_extension.module();
	}
}
