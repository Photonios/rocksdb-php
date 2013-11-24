#ifndef ROCKSDB_H_
#define ROCKSDB_H_

/*!
 * \brief The PHP wrapper for the rocksdb::DB class. Represents a single RocksDB database.
 * \author Swen Kooij
 */
class RocksDB : public Php::Base
{
public:
	/*!
	 * \brief Initializes a new instance of the RocksDB class.
	 * \note This is NOT the PHP constructor.
	 */
	RocksDB();

	/*!
	 * \brief The PHP constructor, the method that gets called when
	 * 		  a new instance of this object is being created.
	 * \param db_path The path to a RocksDB file that needs to be openend.
	 */
	void __construct(Php::Parameters &params);

	/*!
	 * \brief The PHP destructor, the method that gets called
	 *		  when this instance is destroyed.
	 */
	void __destruct();

	/*!
	 * Opens the 'connection' with the earlier specified RocksDB file.
	 * \param create_if_missing A boolean indicating whether the database should be created it it does not exists.
	 * \returns A boolean indicating whether opening the database sucessful.
	 */
	Php::Value Open(Php::Parameters &params);

private:
	/*!
	 *  \brief The path to the RocksDB database this instance represents.
	 */
	std::string 	m_db_path;

	/*!
	 * \brief Represents the 'connection' with the selected RocksDB file.
	 */
	rocksdb::DB*	m_rdb;
};

#endif /* ROCKSDB_H_ */
