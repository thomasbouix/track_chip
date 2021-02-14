-- sqlite3 track_chip.db
-- .read track_chip.sql

DROP TABLE IF EXISTS Location;
DROP TABLE IF EXISTS Device;
DROP TABLE IF EXISTS Owner;

CREATE TABLE Location 	(	id 			INTEGER 	PRIMARY KEY AUTOINCREMENT, 
							altitude  	INTEGER 	NOT NULL,
							latitude 	INTEGER 	NOT NULL,
							longitude  	INTEGER 	NOT NULL,
							send_time	TIMESTAMP 	DEFAULT CURRENT_TIMESTAMP, 
							device_id 	INTEGER 	NOT NULL, 
							FOREIGN KEY (device_id) REFERENCES Device(id)
					  	);

CREATE TABLE Device 	(	id 			INTEGER 	PRIMARY KEY AUTOINCREMENT, 
							name 		TEXT 		NOT NULL, 
							ref_com 	INTEGER 	NOT NULL,
							owner_id 	INTEGER 	NOT NULL, 
							FOREIGN KEY (owner_id) REFERENCES Owner(id)
						);

CREATE TABLE Owner 		(	id 			INTEGER 	PRIMARY KEY AUTOINCREMENT, 
							lastname 	TEXT 		NOT NULL, 
							firstname 	TEXT 		NOT NULL, 
							username	TEXT		NOT NULL,
							password	TEXT		NOT NULL,
							phone 		TEXT 		NOT NULL,
							email 		TEXT 		NOT NULL
						);

INSERT INTO Owner(lastname, firstname, username, password, phone, email) VALUES 
			("Admin"	, "Admin"	, "admin"		, "test_admin"	, "0000000000", "admin@gmail.com"		),
			("Calvino"	, "Enzo"	, "enzo"		, "test_enzo"	, "0672983618", "enzo@gmail.com"		),
			("Idomar"	, "Aziz"	, "aziz"		, "test_aziz"	, "0673283912", "aziz@gmail.com"		),
			("Bouix"	, "Thomas"	, "thomas"		, "test_thomas"	, "0691826334", "thomas@gmail.com"		),
			("Raphanel"	, "Eugene"	, "eugene"		, "test_eugene"	, "0634233648", "eugene@gmail.com"		),
			("Cover"	, "Harry"	, "harrycover"	, "test_harry"	, "0678246351", "harrycover@gmail.com"	);

INSERT INTO Device(name, ref_com, owner_id) VALUES
			("TrackChip", "KF6853", 1);

INSERT INTO Location(altitude, latitude, longitude, device_id) VALUES
			(34, 48.88, 2.36, 1);

