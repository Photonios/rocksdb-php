#!/usr/bin/php -q

<?php
	$rockdb = new RocksDB('my_rock_db');
	if($rockdb->Open(true))
		echo "Success\n";
	else
		echo "Failure!\n";
?>
