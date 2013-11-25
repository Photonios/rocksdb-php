#!/usr/bin/php -q

<?php
	// Attempt to open database named 'my_rock_db'
	$rockdb = new RocksDB('my_rock_db');
	if($rockdb->Open(true))
		echo "Open DB: ok\n";
	else
		die("Open DB: failed -> " . $rockdb->GetLastError() . "\n");

	// Get the database path and verify that we opened the database successfully
	echo "DB Path: " . $rockdb->GetDbPath() . "\n";
	echo "Is Open: " . $rockdb->IsOpen() . "\n";

	// Store the value 'my_awesome_value' under the 'my_awesome_key'
	$result = $rockdb->Put('my_awesome_key', 'my_awesome_value');
	if($result)
		echo "Put: my_awesome_key -> my_awesome_value\n";
	else
		die("Put: failed -> " . $rockdb->GetLastError() . "\n");

	// Get the value for 'my_awesome_key'
	$value = $rockdb->Get('my_awesome_key');
	if(!$value)
		echo "Get: failed -> " . $rockdb->GetLastError() . "\n";
	else
		die("Get: my_awesome_key -> " . $value . "\n");

	die("Close: " . $rockdb->Close() . "\n"); 
?>





