#ifndef DATABSE_H_
#define DATABSE_H_

namespace RocksDB
{

/*!
 * \brief The PHP wrapper for the rocksdb::DB class. Represents a single RocksDB database.
 * \author Swen Kooij
 */
class Database : public Php::Base
{
public:
	/*!
	 * \brief Initializes a new instance of the Database class.
	 * \note This is NOT the PHP constructor.
	 */
	Database();

	/*!
	 * \brief The PHP constructor, the method that gets called when
	 * 		  a new instance of this object is being created.
	 * \param db_path The path to a RocksDB file that needs to be opened.
	 */
	void __construct(Php::Parameters &params);

	/*!
	 * \brief The PHP destructor, the method that gets called
	 *		  when this instance is destroyed.
	 */
	void __destruct();

	/*!
	 * \brief Opens the 'connection' with the earlier specified RocksDB file.
	 * \param create_if_missing A boolean indicating whether the database should be created it it does not exists.
	 * \returns A boolean indicating whether opening the database successful.
	 */
	Php::Value Open(Php::Parameters &params);

	/*!
	 * \brief Gets the last error that was thrown, as a string. A textual message
	 * 		  describing the error.
	 * \returns A string, describing the error. If no error occurred, an empty string will be returned.
	 */
	Php::Value GetLastError();

	/*!
	 * \brief Checks whether there's an active connection with a database.
	 * \returns A boolean indicating whether there's an active connection with a database.
	 */
	Php::Value IsOpen();

	/*!
	 * \brief Gets the path to the currently opened database.
	 */
	Php::Value GetDbPath();

	/*!
	 * \brief Closes the current connection to the database.
	 * \returns A boolean indicating whether closing the connection was sucessful, it
	 * 			returns false when there's no active connection.
	 */
	Php::Value Close();

	/*!
	 * \brief Gets the value of the specified key.
	 * \param key The name of the key to get the value for, this has to be a string.
	 * \returns The textual value stored under the specified key, if no key exists with
	 * 			the specified name,false will be returned. If there are any
	 * 			other reasons why you're getting false, check GetLastError();
	 */
	Php::Value Get(Php::Parameters &params);

	/*!
	 * \brief Sets the value of the specified key.
	 * \param key The name of the key to put the value of.
	 * \param value The new value for this key.
	 * \returns A boolean indicating whether the put was sucessful, when it failed,
	 *  		there's probably no active db connection, check GetLastError();
	 */
	Php::Value Put(Php::Parameters &params);

private:
	/*!
	 *  \brief The path to the RocksDB database this instance represents.
	 */
	std::string 	m_db_path;

	/*!
	 * \brief Holds the textual representation of the error that was last thrown.
	 */
	std::string		m_last_error;

	/*!
	 * \brief Represents the 'connection' with the selected RocksDB file.
	 */
	rocksdb::DB*	m_rdb;

	/*!
	 * \brief Indicates whether there's an active 'connection' with a database.
	 */
	bool			m_is_open;
};

} // namespace RocksDB

#endif /* DATABSE_H_ */
