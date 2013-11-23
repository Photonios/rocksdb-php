#include <phpcpp/phpcpp.h>

extern Php::Value get_test_string();

Php::Value get_test_string()
{
	return std::string("We are awesome!");
}

void add_extension_methods(Php::Extension &extension)
{
	extension.add("get_test_string", get_test_string);
}

extern "C"
{
	PHPCPP_EXPORT void* get_module()
	{
		static Php::Extension rocksdb_extension("RocksDB PHP Extension", "1.0");
		add_extension_methods(rocksdb_extension);
		return rocksdb_extension.module();
	}
}
