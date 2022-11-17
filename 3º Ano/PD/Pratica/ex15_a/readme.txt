MySQL Server: sql7.freemysqlhosting.net
Port number: 3306 (default)

Database name: sql7531261

Username: sql7531261
Password: IpbydJD2A6

Database structure (a single table):

	CREATE TABLE pi_workers (
  		address VARCHAR(100) NOT NULL,
  		port INT NOT NULL,
  		timestamp TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  		PRIMARY KEY (address, port)
	);
