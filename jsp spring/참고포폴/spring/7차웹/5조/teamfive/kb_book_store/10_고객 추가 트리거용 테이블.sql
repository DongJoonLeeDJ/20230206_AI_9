CREATE TABLE `customerlog` (
  `custNum` int NOT NULL AUTO_INCREMENT,
  `custid` varchar(50) DEFAULT NULL,
  `custname` varchar(40) DEFAULT NULL,
  `custaddress` varchar(50) DEFAULT NULL,
  `custphone` varchar(20) default null,
  `custLogTime` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`custNum`)
);